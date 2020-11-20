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

    void loadSampleData();

    vector<Guest> getGuests();

    void addGuest(Guest &guest);

    Guest searchGuest(string);
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

    this->guests.push_back(ian);
    this->guests.push_back(diego);
    this->guests.push_back(andrea);
    this->guests.push_back(daniel);
    this->guests.push_back(valentina);
}

/**
 * Obtiene los huéspedes registrados en la aplicación.
 * @return Guests.
 */
vector<Guest> DataHandler::getGuests() {
    return this->guests;
}

/**
 * Busca al huésped en los registros de la aplicación.
 * @param guestName Guest name
 * @return Guest
 */
Guest DataHandler::searchGuest(string guestName) {
    for (Guest guest : getGuests()) {
        if (guest.getName().find(guestName)) {
            return guest;
        }
    }
}

/**
 * Agrega al huesped al registro de la aplicación.
 * @param guest Huesped.
 */
void DataHandler::addGuest(Guest &guest) {
    getGuests().push_back(guest);
    cout << "El usuario ha sido añadido con éxito!" << endl;
}


#endif //HOTEL_MANAGEMENT_DATAHANDLER_H
