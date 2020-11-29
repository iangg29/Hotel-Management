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

/*
 * Suite: Clase para definir el modelo de cada suite.
 * @file Suite.h
 * @author Ian
 * */

using namespace std;

class Suite {
private:
    int suiteNumber;
    bool available;
    Guest guest;

public:
    Suite();

    void setSuiteNumber(int);

    bool isAvailable();

    string getGuestName();

    int getSuiteNumber();

    void setAvailable();

    void checkInGuest(Guest &guest);

    void display();
};

/**
 * Constructor de la clase Suite
 */
Suite::Suite() {
    this->available = true;
}

/*+
 * Asigna el número de suite al objeto.
 * @param suiteNumber Número a asignar.
 */
void Suite::setSuiteNumber(int suiteNumber) {
    this->suiteNumber = suiteNumber;
}

/**
 * Obtiene el número de suite del hotel.
 * @return Número de suite.
 */
int Suite::getSuiteNumber() {
    return this->suiteNumber;
}

/*+
 * Revisa si la suite está disponible.
 * @return La suite no está ocupada.
 */
bool Suite::isAvailable() {
    return this->available;
}

/**
 * Obtiene el nombre del huesped de la habitación.
 * @return Nombre del huesped.
 */
string Suite::getGuestName() {
    return this->guest.getName();
}

/**
 * Asigna la suite como disponible.
 */
void Suite::setAvailable() {
    this->available = true;
}

/**
 * Asigna la suite a un huesped previamente ya registrado.
 * @param guest Objeto del huesped a asignar.
 */
void Suite::checkInGuest(Guest &guest) {
    this->available = false;
    this->guest = guest;
}

/**
 * Imprime información relevante de la suite.
 */
void Suite::display() {
    if (isAvailable()) {
        cout << "La suite #" << getSuiteNumber() << " está disponible." << endl;
    } else {
        cout << "La suite #" << getSuiteNumber() << " está actualmente ocupada por " << getGuestName() << endl;
    }
}


#endif //HOTEL_MANAGEMENT_SUITE_H
