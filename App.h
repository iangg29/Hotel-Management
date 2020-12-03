//
// Hotel Management System
//
// Ian García González
// A01706892
//
// File created on 10/11/20.
//
// Copyright © 2020. All rights reserved.
//
//

#ifndef HOTEL_MANAGEMENT_APP_H
#define HOTEL_MANAGEMENT_APP_H

#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include "modules/DataHandler.h"
#include "modules/Utilities.h"
#include "models/Hotel.h"

/*
 * App: Clase principal de la aplicación donde se manejan los módulos y controladores.
 * @file App.h
 * @author Ian
 * */

using namespace std;

class App {
private:
    string name;
    string author;
    bool debug;
    bool started;
    float version;
    vector<Module> modules;
    DataHandler dataHandler = DataHandler("DataHandler Manager", ModuleType::DATA);
    Hotel hotel = Hotel("Moon Palace", 10);
    unsigned int startTime;
    unsigned int finishTime;

    void menu();

public:
    App(string, bool, float);

    string getName();

    string getAuthor();

    float getVersion();

    DataHandler getDataHandler();

    Hotel getHotel();

    vector<Module> getModules();

    bool isDebug();

    bool isStarted();

    void setStarted(bool);

    void addModule(Module &module);

    void start();

    void end();

    void launchConsole();
};

/**
 * Constructor de la aplicación principal.
 * @param name Nombre de la aplicación.
 * @param debug Modo debug.
 * @param version Versión de la aplicación.
 */
App::App(string name, bool debug, float version) {
    this->name = name;
    this->debug = debug;
    this->version = version;
    this->author = "Ian García";
    this->started = false;
    addModule(dataHandler);
}

/**
 * Obtiene nombre de la app.
 * @return Nombre de la aplicación.
 */
string App::getName() {
    return this->name;
}

/**
 * Obtiene nombre del autor de la app.
 * @return Autor de la aplicación.
 */
string App::getAuthor() {
    return this->author;
}

/**
 * Revisa si el modo debug está encendido.
 * @return Modo debug encendido o no.
 */
bool App::isDebug() {
    return this->debug;
}

/**
 * Obtiene versión de la app.
 * @return Versión de la aplicación.
 */
float App::getVersion() {
    return this->version;
}

/**
 * Revisa si la aplicación ya fué iniciada.
 * @return Aplicación iniciada.
 */
bool App::isStarted() {
    return this->started;
}

/**
 * Asigna si la aplicación ya fué iniciada.
 * @param started Ya fué iniciada la aplicación.
 */
void App::setStarted(bool started) {
    this->started = started;
}

/**
 * Obtiene el módulo que administra los datos del programa.
 * @return Data handler module.
 */
DataHandler App::getDataHandler() {
    return this->dataHandler;
}

/**
 * Obtiene la instancia del hotel principal.
 * @return Hotel.
 */
Hotel App::getHotel() {
    return this->hotel;
}

/**
 * Método principal para iniciar la aplicación.
 */
void App::start() {
    if (!isStarted()) {
        startTime = std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::system_clock::now().time_since_epoch()).count();
        setStarted(true);
        if (isDebug()) cout << "Loading modules..." << endl;
        Utilities utilities("Utilities Manager", ModuleType::INFO);
        addModule(utilities);
        cout << "La aplicación ha iniciado correctamente." << endl;
        finishTime = std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::system_clock::now().time_since_epoch()).count();
        cout << "Aplicación iniciada en [" << (finishTime - startTime) << "]ms." << endl;

        launchConsole();
    } else {
        cout << "La aplicación ya ha sido iniciada!" << endl;
    }
}

/**
 * Método para terminal y cerrar la aplicación.
 * Limpia cache y vacia datos.
 */
void App::end() {
    if (isStarted()) {
        setStarted(false);
        // TODO: Clear cache.
        for (Module module : getModules()) {
            module.end();
        }
        cout << "La aplicación se ha cerrado correctamente." << endl;
        cout << "Gracias por utilizar esta aplicación." << endl;
    }
}

/**
 * Obtiene módulos registrados.
 * @return Vector con los métodos registrados en la aplicación.
 */
vector<Module> App::getModules() {
    return this->modules;
}

/**
 * Método para registrar módulo.
 * @param module Módulo a registrar en la aplicación.
 */
void App::addModule(Module &module) {
    getModules().push_back(module);
}

/**
 * Método para iniciar la conversación app - usuario.
 */
void App::launchConsole() {
    int opcion = 0;
    Guest selected, newGuest;
    string guestName, nombre, gender;
    int age, phone;
    dataHandler.loadSampleData();
    while (isStarted()) {
        menu();
        cout << "Por favor, escoje una opción: ";
        cin >> opcion;
        while (cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Por favor, escoje una opción: ";
            cin >> opcion;
        }
        switch (opcion) {
            case 1:
                cout << "Estas a punto de hacer una reservación!" << endl;
                cout << "Por favor ingresa el nombre de un huesped previamente registrado: ";
                cin >> guestName;
                selected = dataHandler.searchGuest(guestName);
                if (selected.getAge() != -1) {
                    if (hotel.checkIn(selected)) {
                        cout << "Bienvenido a " << hotel.getName() << ", " << selected.getName() << endl;
                        cout << "Disfruta tu estancia en " << hotel.getName() << "!" << endl;
                    } else {
                        cout << "Ha ocurrido un error al registrar al huesped." << endl;
                        cout << "Intenta de nuevo por favor." << endl;
                    }
                } else {
                    cout << "No se ha podido encontrar al huésped \"" << guestName << "\"." << endl;
                    cout << "Intenta de nuevo por favor." << endl;
                }
                break;
            case 2:
                cout << "Estas a punto de hacer checkout!" << endl;
                cout << "Por favor ingresa el nombre del huesped: ";
                cin >> guestName;
                if (hotel.checkOut(guestName)) {
                    cout << "Hasta luego " << guestName << "." << endl;
                }
                break;
            case 3:
                cout << "Estas a punto de buscar un huesped!" << endl;
                cout << "Por favor ingresa el nombre del huesped a buscar: ";
                cin >> guestName;
                selected = dataHandler.searchGuest(guestName);
                if (selected.getAge() != -1) {
                    selected.display();
                } else {
                    cout << "No se ha podido encontrar al huésped \"" << guestName << "\"." << endl;
                    cout << "Intenta de nuevo por favor." << endl;
                }
                break;
            case 4:
                hotel.display();
                break;
            case 5:
                dataHandler.displayGuests();
                break;
            case 6:
                cout << "Estas a punto de registrar un nuevo huesped!" << endl;
                cout << "Ingresa el nombre del huesped: ";
                cin >> nombre;
                cout << "Ingresa la edad del huesped: ";
                cin >> age;
                cout << "Ingresa el género del huésped (M, F, I): ";
                cin >> gender;
                cout << "Ingresa el celular del huésped: ";
                cin >> phone;
                newGuest = Guest(nombre, age,
                                 (gender == "M" ? Gender::MALE : (gender == "F" ? Gender::FEMALE : Gender::UNDEFINED)),
                                 phone);
                dataHandler.addGuest(newGuest);
                break;
            case 7:
                end();
                break;
            default:
                cout << "Opción no encontrada, vuelve a intentarlo." << endl;
                break;
        }
    }
}

/**
 * Método para mandar al usuario las opciones posibles dentro de la aplicación.
 */
void App::menu() {
    cout << "1. CheckIn a huesped" << endl;
    cout << "2. CheckOut a huesped" << endl;
    cout << "3. Buscar huesped" << endl;
    cout << "4. Información de suites." << endl;
    cout << "5. Huespedes registrados." << endl;
    cout << "6. Crea un nuevo registro para huesped." << endl;
    cout << "7. Salir" << endl;
}


#endif //HOTEL_MANAGEMENT_APP_H
