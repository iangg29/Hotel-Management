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

#ifndef HOTEL_MANAGEMENT_MYSQL_H
#define HOTEL_MANAGEMENT_MYSQL_H

#include <iostream>
#include <string>
#include "../Module.h"

/*
 * MySQL: Módulo donde se administra todas las solicitudes a la base de datos SQL.
 * @file MySQL.h
 * @author Ian
 * */

using namespace std;

class MySQL : public Module {
private:

public:
    MySQL(string name, ModuleType type);
    void start() override;
    void initConnection();
};

/**
 * Constructor del módulo.
 * @param name Nombre del módulo
 * @param type Tipo del módulo
 */
MySQL::MySQL(string name, ModuleType type) : Module(name, type) {}


/*
 * Inicia la conexión con el servidor SQL.
 */
void MySQL::initConnection() {
    // TODO: Make connection with Mongo Server.
}

/*
 * Sobreescribe el método start del módulo para añadir cambios.
 */
void MySQL::start() {
    Module::start();

}


#endif //HOTEL_MANAGEMENT_MYSQL_H
