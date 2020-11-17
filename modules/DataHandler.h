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

#ifndef HOTEL_MANAGEMENT_DATAHANDLER_H
#define HOTEL_MANAGEMENT_DATAHANDLER_H

#include <iostream>
#include <string>
#include "../Module.h"

/*
 * DataHandler: Módulo donde se administra todas las solicitudes a la base de datos SQL.
 * @file DataHandler.h
 * @author Ian
 * */

using namespace std;

class DataHandler : public Module {
private:
    string name;
    ModuleType type;
public:
    DataHandler(string, ModuleType);
};

/**
 * Constructor del módulo.
 * @param name Nombre del módulo
 * @param type Tipo del módulo
 */
DataHandler::DataHandler(string name, ModuleType type) : Module(name, type) {
    this->name = name;
    this->type = type;
}


#endif //HOTEL_MANAGEMENT_DATAHANDLER_H
