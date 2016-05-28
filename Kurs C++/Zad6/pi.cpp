//
// Created by Mateusz Pater on 08.04.2016.
//

#include "pi.h"


double pi::oblicz() {
    return M_PI;
}

std::string pi::formatuj_wyrazenie() {
    return std::to_string(oblicz());
}
