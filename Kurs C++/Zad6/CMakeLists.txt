cmake_minimum_required(VERSION 3.3)
project(arytmetyka2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp wyrazenie.cpp wyrazenie.h zmienna.cpp zmienna.h stala.cpp stala.h dodaj.cpp dodaj.h odejmij.cpp odejmij.h pomnoz.cpp pomnoz.h podziel.cpp podziel.h potega.cpp potega.h log.cpp log.h modulo.cpp modulo.h lognat.cpp lognat.h cosinus.cpp cosinus.h sinus.cpp sinus.h odwrotna.cpp odwrotna.h bezwgledna.cpp bezwgledna.h exp.cpp exp.h przeciwna.cpp przeciwna.h pi.cpp pi.h e.cpp e.h operator0arg.cpp operator0arg.h operator1arg.cpp operator1arg.h operator2arg.cpp operator2arg.h)
add_executable(arytmetyka2 ${SOURCE_FILES})