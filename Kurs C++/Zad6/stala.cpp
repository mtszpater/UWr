//
// Created by Mateusz Pater on 08.04.2016.
//

#include "stala.h"



double stala::oblicz(){
    return value;
}

std::string stala::opis() {

}

stala::stala(int value) : value(value) { }


int stala::getValue() {
    return value;
}

std::string stala::formatuj_wyrazenie() {
    return std::to_string(value);
}
