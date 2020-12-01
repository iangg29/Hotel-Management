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

#ifndef HOTEL_MANAGEMENT_MODULE_H
#define HOTEL_MANAGEMENT_MODULE_H

#include <iostream>
#include <string>

/*
 * Module: Clase base para cada módulo a registrar en la aplicación.
 * @file Module.h
 * @author Ian
 * */

using namespace std;

/**
 * Tipos disponibles de módulos.
 * DATA: Manejan información de la base de datos.
 * INFO: Controlan el flujo de datos de dicha información.
 */
enum class ModuleType {
    DATA,
    INFO
};

class Module {
protected:
    string name;
    ModuleType type;
    bool started;

    virtual void log(string);

    virtual void logWarn(string);

    virtual void logError(string);

    virtual void log(string, string);

public:
    Module(string, ModuleType);

    string getName();

    ModuleType getType();

    bool isStarted();

    void setStarted(bool);

    virtual void start();

    virtual void end();

    void printInfo();
};

/**
 * Constructor de la clase.
 * @param name Nombre del módulo.
 * @param type Tipo del módulo.
 */
Module::Module(string name, ModuleType type) {
    this->name = name;
    this->type = type;
    start();
}

/**
 * Obtiene el nombre del módulo.
 * @return Nombre del módulo.
 */
string Module::getName() {
    return this->name;
}

/**
 * Método disponible en todos los módulos que se ejecuta al inciar.
 */
void Module::start() {
    setStarted(true);
    cout << "Módulo " << getName() << " ha iniciado." << endl;
}

/**
 * Método que finaliza el módulo.
 */
void Module::end() {
    setStarted(false);
    cout << "Módulo " << getName() << " se ha cerrado!" << endl;
}

/**
 * Método de ayuda que imprime información del módulo.
 */
void Module::printInfo() {
    cout << "Módulo:" << endl;
    cout << "Nombre: " << getName() << endl;
    cout << "Iniciado: " << isStarted() << endl;

}

/**
 * Obtiene el estatus del módulo.
 * @return Si el módulo está iniciado o no.
 */
bool Module::isStarted() {
    return this->started;
}

/**
 * Asigna el estatus del módulo.
 * @param started El módulo está iniciado o no.
 */
void Module::setStarted(bool started) {
    this->started = started;
}

/*+
 * Obtiene el tipo de módulo.
 * @return Tipo de módulo.
 */
ModuleType Module::getType() {
    return this->type;
}

/**
 * Imprime mensaje en la consola con prefijo.
 * @param message Mensaje a imprimir.
 */
void Module::log(string message) {
    cout << "[i] " << message << endl;
}

/**
 * Imprime mensaje en la consola con prefijo.
 * @param message Mensaje a imprimir.
 */
void Module::logWarn(string message) {
    cout << "[WARNING] " << message << endl;
}

/**
 * Imprime mensaje en la consola con prefijo.
 * @param message Mensaje a imprimir.
 */
void Module::logError(string message) {
    cout << "[ERROR] " << message << endl;
}

/**
 * Imprime mensaje en la consola con prefijo definido.
 * @param prefix Prefijo.
 * @param message Mensaje.
 */
void Module::log(string prefix, string message) {
    cout << "[" << prefix << "] " << message << endl;
}


#endif //HOTEL_MANAGEMENT_MODULE_H
