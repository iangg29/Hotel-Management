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
#include "modules/DataHandler.h"
#include "modules/Utilities.h"

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
    DataHandler dataHandler;

    void menu();

public:
    App(string, bool, float);

    string getName();

    string getAuthor();

    float getVersion();

    DataHandler getSQL();

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
App::App(string name, bool debug, float version) : dataHandler("DataHandler Manager", ModuleType::DATA) {
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
 * Método principal para iniciar la aplicación.
 */
void App::start() {
    if (!isStarted()) {
        // TODO: Start handle.
        setStarted(true);
        if (isDebug()) cout << "Loading modules..." << endl;
        Utilities utilities("Utilities Manager", ModuleType::INFO);
        addModule(utilities);
        // TODO: Complete modules.
        cout << "La aplicación ha iniciado correctamente." << endl;
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
        delete this;
        cout << "La aplicación se ha cerrado correctamente." << endl;
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
    while (isStarted()) {
        menu();
        cout << "Por favor, escoje una opción: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                cout << "Estas a punto de hacer una reservación!" << endl;
                break;
            case 4:
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
    cout << "1. Hacer reservación" << endl;
    cout << "2. Reservaciones confirmadas" << endl;
    cout << "3. Habitaciones disponibles" << endl;
    cout << "4. Salir" << endl;
}


#endif //HOTEL_MANAGEMENT_APP_H
