//
// Created by Mateusz Pater on 08.04.2016.
//

#include "zmienna.h"


double zmienna::oblicz() {
    for(int i = 0; i < myVector.size(); i++){
        if(myVector[i].first == value){
            return myVector[i].second;
        }
    }
}

void zmienna::newPair(std::string k, double s){


    for(int i = 0; i < myVector.size(); i++){
        if(myVector[i].first == k){
            throw std::invalid_argument("Już w bazie istnieje taka zmienna");
        }
    }

    myVector.emplace_back(std::make_pair(k, s));

}


std::string zmienna::formatuj_wyrazenie() {
    return value;
}

void zmienna::setValue(double newValue){

    for(int i = 0; i < myVector.size(); i++){
        if(myVector[i].first == value){
            myVector[i].second = newValue;
        }
    }

}


void zmienna::changeValue(std::string _value) {

    int exists = 0;

    for(int i = 0; i < myVector.size(); i++){
        if(myVector[i].first == _value){
            exists = 1;
        }
    }

    if( exists == 0 ){
        throw std::invalid_argument("Nie ma takiej zmiennej w bazie");
    }

    value = _value;

}

zmienna::zmienna(const std::string &value) : value(value) {

    newPair("x",10.00);
    newPair("y",2.00);
    newPair("z",3.00);


    int exists = 0;

    for(int i = 0; i < myVector.size(); i++){
        if(myVector[i].first == value){
            exists = 1;
        }
    }

    if( exists == 0 ){
        throw std::invalid_argument("Nie ma takiej zmiennej w bazie");
    }
}

std::string zmienna::opis() {

}


