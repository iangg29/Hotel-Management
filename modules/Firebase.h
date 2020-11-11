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

#ifndef HOTEL_MANAGEMENT_FIREBASE_H
#define HOTEL_MANAGEMENT_FIREBASE_H

#include <iostream>
#include <string>
#include "../Module.h"

using namespace std;

class Firebase : public Module {
public:
    Firebase(string name, ModuleType type);
};

Firebase::Firebase(string name, ModuleType type) : Module(name, type) {}


#endif //HOTEL_MANAGEMENT_FIREBASE_H
