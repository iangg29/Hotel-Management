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

#include <string>

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
    int phone;

public:
    Guest();

    Guest(string, int, Gender, int);

    string getName();

    int getAge();

    Gender getGender();

    int getPhone();

    void setName(string);

    void setAge(int);

    void setGender(Gender);

    void setPhone(int);
};

Guest::Guest() {
    this->name = "";
    this->age = 0;
    this->gender = Gender::UNDEFINED;
    this->phone = 0;
}

Guest::Guest(string name, int age, Gender gender, int phone) {
    this->name = name;
    this->age = age;
    this->gender = gender;
    this->phone = phone;
}

string Guest::getName() {
    return this->name;
}

int Guest::getAge() {
    return this->age;
}

Gender Guest::getGender() {
    return this->gender;
}

int Guest::getPhone() {
    return this->phone;
}

void Guest::setName(string name) {
    this->name = name;
}

void Guest::setAge(int age) {
    this->age = age;
}

void Guest::setGender(Gender gender) {
    this->gender = gender;
}

void Guest::setPhone(int phone) {
    this->phone = phone;
}


#endif //HOTEL_MANAGEMENT_GUEST_H
