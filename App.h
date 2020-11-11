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
#include "modules/Firebase.h"
#include "modules/Utilities.h"

using namespace std;

class App {
private:
    string name;
    string author;
    bool debug;
    bool started;
    float version;
    vector<Module> modules;

    void menu();

public:
    App(string name, bool debug, float version);

    string getName();

    string getAuthor();

    bool isDebug();

    bool isStarted();

    float getVersion();

    vector<Module> getModules();

    void setStarted(bool started);

    void addModule(Module &module);

    void start();

    void end();

    void launchConsole();
};

App::App(string name, bool debug, float version) {
    this->name = name;
    this->debug = debug;
    this->version = version;
    this->author = "Ian García";
    this->started = false;
}

string App::getName() {
    return this->name;
}

string App::getAuthor() {
    return this->author;
}

bool App::isDebug() {
    return this->debug;
}

float App::getVersion() {
    return this->version;
}

bool App::isStarted() {
    return this->started;
}

void App::setStarted(bool started) {
    this->started = started;
}

void App::start() {
    if (!isStarted()) {
        // TODO: Start handle.
        setStarted(true);
        if (isDebug()) cout << "Loading modules..." << endl;
        Utilities utilities("Utilities Manager", ModuleType::INFO);
        Firebase firebase("Firebase Manager", ModuleType::DATA);
        addModule(firebase);
        addModule(utilities);
        // TODO: Complete modules.
        cout << "La aplicación ha iniciado correctamente." << endl;
        launchConsole();
    } else {
        cout << "La aplicación ya ha sido iniciada!" << endl;
    }
}

void App::end() {
    if (isStarted()) {
        setStarted(false);
        // TODO: Clear cache.
        delete this;
        cout << "La aplicación se ha cerrado correctamente." << endl;
    }
}

vector<Module> App::getModules() {
    return this->modules;
}

void App::addModule(Module &module) {
    getModules().push_back(module);
}

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

void App::menu() {
    cout << "1. Hacer reservación" << endl;
    cout << "2. Reservaciones confirmadas" << endl;
    cout << "3. Habitaciones disponibles" << endl;
    cout << "4. Salir" << endl;
}


#endif //HOTEL_MANAGEMENT_APP_H
