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

using namespace std;

class MySQL : public Module {
private:

public:
    MySQL(string name, ModuleType type);
    void start() override;
    void initConnection();
};

MySQL::MySQL(string name, ModuleType type) : Module(name, type) {}



void MySQL::initConnection() {
    // TODO: Make connection with Mongo Server.
}

void MySQL::start() {
    Module::start();

}


#endif //HOTEL_MANAGEMENT_MYSQL_H
