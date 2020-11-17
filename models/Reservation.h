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

#ifndef HOTEL_MANAGEMENT_RESERVATION_H
#define HOTEL_MANAGEMENT_RESERVATION_H

#include <string>
#include <vector>
#include <ctime>
#include "Suite.h"

class Reservation {
private:
    static int getUUID();

    Suite suite;
    vector<Guest> guests;
    time_t ttime = time(0);
    char *date;
public:
    Reservation(Suite, vector<Guest>);

    Suite getSuite();

    vector<Guest> getGuests();

    char * getDate();
};


Reservation::Reservation(Suite suite, vector<Guest> guests) {
    this->suite = suite;
    this->guests = guests;
    this->date = ctime(&ttime);
}


int Reservation::getUUID() {
    static std::atomic<std::uint32_t> uid{0};
    return ++uid;
}

Suite Reservation::getSuite() {
    return this->suite;
}

vector<Guest> Reservation::getGuests() {
    return this->guests;
}

char * Reservation::getDate() {
    return this->date;
}

#endif //HOTEL_MANAGEMENT_RESERVATION_H
