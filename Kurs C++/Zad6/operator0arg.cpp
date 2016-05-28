//
// Created by Mateusz Pater on 15.04.2016.
//

#include "operator0arg.h"

std::string operator0arg::opis(){
    return "Wartosc " + std::to_string(oblicz());
}