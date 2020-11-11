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

using namespace std;

class Utilities : public Module {
public:
    Utilities(string name, ModuleType type);
};

Utilities::Utilities(string name, ModuleType type) : Module(name, type) {}


#endif //HOTEL_MANAGEMENT_UTILITIES_H
