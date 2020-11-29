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
#include "../models/Guest.h"

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
    vector<Guest> guests;
public:
    DataHandler(string, ModuleType);

    void addGuest(Guest &guest);

    Guest searchGuest(string);

    void displayGuests();

    void loadSampleData();
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

/**
 * Carga ejemplos para la aplicación.
 * @return Vector con huéspedes prueba.
 */
void DataHandler::loadSampleData() {
    Guest ian("Ian García", 18, Gender::MALE, 4423637690);
    Guest diego("Diego", 20, Gender::MALE, 442776690);
    Guest andrea("Andrea", 19, Gender::FEMALE, 442456821);
    Guest daniel("Daniel", 18, Gender::MALE, 4421869432);
    Guest valentina("Valentina", 18, Gender::MALE, 4427564871);

    addGuest(ian);
    addGuest(diego);
    addGuest(andrea);
    addGuest(daniel);
    addGuest(valentina);
}

void DataHandler::addGuest(Guest &guest) {
    guests.push_back(guest);
    cout << "Guest added! (" << guest.getName() << ")" << endl;
}

Guest DataHandler::searchGuest(string name) {
    for (Guest guest : guests) {
        if (guest.getName() == name) {
            return guest;
        }
    }
    return Guest("NOT FOUND", -1, Gender::UNDEFINED, -1);
}

void DataHandler::displayGuests() {
    if (!guests.empty()) {
        cout << "La información del huéspedes a la fecha es:" << endl;
        for (Guest guest : guests) {
            guest.display();
        }
    } else {
        cout << "No se encontraron huéspedes registrados!" << endl;
    }
}


#endif //HOTEL_MANAGEMENT_DATAHANDLER_H
