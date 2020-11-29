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

#ifndef HOTEL_MANAGEMENT_UTILITIES_H
#define HOTEL_MANAGEMENT_UTILITIES_H

#include <iostream>
#include <string>
#include "../Module.h"

/*
 * Utilities: Módulo que contiene métodos de utilidad para la aplicación.
 * @file Utilities.h
 * @author Ian
 * */

using namespace std;

class Utilities : public Module {
public:
    Utilities(string, ModuleType);
};

/**
 * Constructor del módulo.
 * @param name Nombre del módulo.
 * @param type Tipo del módulo.
 */
Utilities::Utilities(string name, ModuleType type) : Module(name, type) {}


#endif //HOTEL_MANAGEMENT_UTILITIES_H
