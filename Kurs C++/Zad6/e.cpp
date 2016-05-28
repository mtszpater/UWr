//
// Created by Mateusz Pater on 08.04.2016.
//

#include "e.h"


double e::oblicz() {
    return M_E;
}

std::string e::formatuj_wyrazenie() {
    return std::to_string(oblicz());
}