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

#ifndef HOTEL_MANAGEMENT_GUEST_H
#define HOTEL_MANAGEMENT_GUEST_H

#include <iostream>
#include <string>

/*
 * Module: Clase para definir el modelo de cada huesped.
 * @file Guest.h
 * @author Ian
 * */

using namespace std;

/**
 * Género de los huéspedes.
 * MALE: Hombre.
 * FEMALE: Mujer.
 * UNDEFINED: Sin definir.
 */
enum class Gender {
    MALE,
    FEMALE,
    UNDEFINED
};

class Guest {
private:
    string name;
    int age;
    Gender gender;
    long phone;

public:
    Guest();

    Guest(string, int, Gender, long);

    string getName();

    int getAge();

    Gender getGender();

    long getPhone();

    void setName(string);

    void setAge(int);

    void setGender(Gender);

    void setPhone(long);

    void display();
};

/**
 * Constructor de la clase.
 */
Guest::Guest() {
    this->name = "";
    this->age = 0;
    this->gender = Gender::UNDEFINED;
    this->phone = 0;
}

/**
 * Constructor de la clase con parámetros.
 * @param name Nombre del huesped.
 * @param age Edad del huesped.
 * @param gender Género del huesped.
 * @param phone Celular del huesped.
 */
Guest::Guest(string name, int age, Gender gender, long phone) {
    this->name = name;
    this->age = age;
    this->gender = gender;
    this->phone = phone;
}

/*+
 * Obtiene el nombre del huesped.
 * @return Nombre.
 */
string Guest::getName() {
    return this->name;
}

/**
 * Obtiene la edad del huesped.
 * @return Edad.
 */
int Guest::getAge() {
    return this->age;
}

/**
 * Obtiene el género del huesped.
 * @return Género.
 */
Gender Guest::getGender() {
    return this->gender;
}

/**
 * Obtiene el celular del huesped.
 * @return Celular.
 */
long Guest::getPhone() {
    return this->phone;
}

/**
 * Asigna el nombre del huesped al objeto.
 * @param name Nombre del huesped.
 */
void Guest::setName(string name) {
    this->name = name;
}

/**
 * Asigna la edad del huesped al objeto.
 * @param age Edad del huesped.
 */
void Guest::setAge(int age) {
    this->age = age;
}

/**
 * Asigna el género del huesped al objeto.
 * @param gender Género del huesped.
 */
void Guest::setGender(Gender gender) {
    this->gender = gender;
}

/**
 * Asigna el celular del huesped al objeto.
 * @param phone Celular del huesped.
 */
void Guest::setPhone(long phone) {
    this->phone = phone;
}

/**
 * Imprime información relevante acerca del huesped.
 */
void Guest::display() {
    cout << "Nombre: " << getName() << endl;
    cout << "Género: "
         << (getGender() == Gender::MALE ? "Hombre" : (getGender() == Gender::FEMALE ? "Mujer" : "Sin definir"))
         << endl;
    cout << "Edad: " << getAge() << endl;
    cout << "Celular: " << getPhone() << endl;
}


#endif //HOTEL_MANAGEMENT_GUEST_H
