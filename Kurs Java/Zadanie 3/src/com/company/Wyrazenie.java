package com.company;

/**
 * author @pater
 */
public abstract class Wyrazenie {
    /* Funkcja abstrakcyjna, ktora dziedziczy kazda podklasa */
    public abstract double oblicz();

    /* Sumowanie tablicy wyrazen */
    public static double sumuj (Wyrazenie[] wyr)
    {
        double suma = 0.0;

        for( Wyrazenie x : wyr)
        {
            suma = suma + x.oblicz();
        }

        return suma;
    }

    /* Mnozenie tablicy wyrazen */
    public static double pomnoz (Wyrazenie[] wyr)
    {

        double suma = wyr[0].oblicz();

        for( int i = 1; i < wyr.length; i++)
        {
            suma = new Pomnoz(new Stala(suma), wyr[i]).oblicz();
        }

        return suma;
    }

}
