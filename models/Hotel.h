//
// Hotel Management System
//
// Ian García González
// A01706892
//
// File created on 19/11/20.
//
// Copyright © 2020. All rights reserved.
//
//

#ifndef HOTEL_MANAGEMENT_HOTEL_H
#define HOTEL_MANAGEMENT_HOTEL_H

#include <iostream>
#include <string>
#include <vector>
#include "Suite.h"

/*
 * Hotel: Clase principal del hotel.
 * @file Hotel.h
 * @author Ian
 * */

using namespace std;

class Hotel {
private:
    string name;
    int num_suites;
    vector<Suite> suites;

    int next();

public:
    Hotel(string, int);

    string getName();

    int getNumSuites();

    bool hasFreeSuites();

    bool checkIn(Guest &guest);

    bool checkOut(Guest &guest);

    bool checkOut(string);

    void display();
};

/**
 * Constructor de la clase.
 * @param name Nombre del hotel.
 * @param num_suites Número de suites con las que cuenta el hotel.
 */
Hotel::Hotel(string name, int num_suites) {
    this->name = name;
    this->num_suites = num_suites;
    this->suites.resize(num_suites);
    for (int i = 0; i < num_suites; i++) {
        suites[i].setSuiteNumber(i + 1);
    }
}

/**
 * Obtiene el nombre del hotel.
 * @return Nombre.
 */
string Hotel::getName() {
    return this->name;
}

/**
 * Obtiene el número de suites con las que cuenta el hotel.
 * @return Número de suites.
 */
int Hotel::getNumSuites() {
    return this->num_suites;
}

/**
 * Obtiene el número de suite que esté disponible.
 * @return Número de suite.
 */
int Hotel::next() {
    for (int i = 0; i < num_suites; i++) {
        if (suites[i].isAvailable()) {
            return i;
        }
    }
    return -1;
}

/**
 * Revisa si el hotel cuenta con suites disponibles.
 * @return
 */
bool Hotel::hasFreeSuites() {
    return next() >= 0;
}

/**
 * Registra un huesped en la suite disponible.
 * @param guest Huesped.
 * @return Posible error o confirmación de la acción.
 */
bool Hotel::checkIn(Guest &guest) {
    int nextSuite = next();
    if (nextSuite >= 0) {
        suites[nextSuite].checkInGuest(guest);
        cout << "Huesped: " << guest.getName() << " asignado a la suite: #" << nextSuite + 1 << endl;
        return true;
    } else {
        cout << "Por el momento no hay habitaciones disponibles." << endl;
        return false;
    }
}

/**
 * Quita al huesped de la habitación previamente registrada.
 * @param name Nombre del huesped.
 * @return Posible error o confirmación de la acción.
 */
bool Hotel::checkOut(string name) {
    for (int i = 0; i < num_suites; i++) {
        if (suites[i].getGuestName() == name) {
            suites[i].setAvailable();
            return true;
        }
    }
    cout << "No se encontró registro de " << name << " en este hotel." << endl;
    return false;
}

/**
 * Quita al huesped de la habitación previamente registrada.
 * @param guest Objeto del huesped.
 * @return Posible error o confirmación de la acción.
 */
bool Hotel::checkOut(Guest &guest) {
    return checkOut(guest.getName());
}

/**
 * Imprime información relevante del hotel.
 */
void Hotel::display() {
    cout << "---- Hotel " << getName() << " ----" << endl;
    for (int i = 0; i < num_suites; i++) {
        suites[i].display();
    }
}


#endif //HOTEL_MANAGEMENT_HOTEL_H
