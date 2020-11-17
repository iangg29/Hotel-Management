//
// Hotel Management System
//
// Ian García González
// A01706892
//
// File created on 16/11/20.
//
// Copyright © 2020. All rights reserved.
//
//

#ifndef HOTEL_MANAGEMENT_SUITE_H
#define HOTEL_MANAGEMENT_SUITE_H

#include <string>
#include "../Module.h"
#include "Guest.h"

class Suite {
private:
    string name;
    int beds;
    bool available;
    int maxGuests;

public:
    Suite();

    Suite(string, int);

    string getName();

    int getBeds();

    bool isAvailable();

    int getMaxGuests();

    void book();
};

Suite::Suite() {
    this->name = "";
    this->beds = 0;
    this->available = false;
    this->maxGuests = 0;
}

Suite::Suite(string name, int beds) {
    this->name = name;
    this->beds = beds;
    this->available = false;
    this->maxGuests = 0;
}

string Suite::getName() {
    return this->name;
}

int Suite::getBeds() {
    return this->beds;
}

bool Suite::isAvailable() {
    return this->available;
}

int Suite::getMaxGuests() {
    return this->maxGuests;
}


#endif //HOTEL_MANAGEMENT_SUITE_H
