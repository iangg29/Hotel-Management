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

using namespace std;

enum class ModuleType {
    DATA,
    INFO
};

class Module {
protected:
    string name;
    ModuleType type;
    bool started;

public:
    Module(string name, ModuleType type);

    string getName();

    ModuleType getType();

    bool isStarted();

    void setStarted(bool started);

    virtual void start();

    virtual void end();

    void printInfo();
};

Module::Module(string name, ModuleType type) {
    this->name = name;
    this->type = type;
    start();
}

string Module::getName() {
    return this->name;
}

void Module::start() {
    setStarted(true);
    cout << "Módulo " << getName() << " ha iniciado." << endl;
}

void Module::end() {
    setStarted(false);
    cout << "Módulo " << getName() << " se ha cerrado!" << endl;
    delete[] this;
}

void Module::printInfo() {
    cout << "Módulo\nNombre: " << getName() << endl;
}

bool Module::isStarted() {
    return this->started;
}

void Module::setStarted(bool started) {
    this->started = started;
}

ModuleType Module::getType() {
    return this->type;
}


#endif //HOTEL_MANAGEMENT_MODULE_H
