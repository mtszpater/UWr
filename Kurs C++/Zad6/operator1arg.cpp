//
// Created by Mateusz Pater on 15.04.2016.
//

#include "operator1arg.h"

std::string operator1arg::opis() {

    return "Wartosc " + std::to_string(oblicz());

}