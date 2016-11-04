package com.company;

/**
 * author @pater
 */
public abstract class Wyrazenie {
    /**
     * Zwraca wynik obliczenia wyrazenia w typie double
     * @return double
     */
    public abstract double oblicz();

    /**
     * Zwraca wynik obliczenia sumowania wryazen w typie double
     * @return double
     * @param wyr wyrazenie
     */
    public static double sumuj (Wyrazenie[] wyr)
    {
        double suma = 0.0;

        for( Wyrazenie x : wyr)
        {
            suma = suma + x.oblicz();
        }

        return suma;
    }

    /**
     * Zwraca wynik obliczenia mnozenia wyrazen w typie double
     * @return double
     * @param wyr wyrazenie
     */
    public static double pomnoz (Wyrazenie[] wyr)
    {

        double suma = wyr[0].oblicz();

        for( int i = 1; i < wyr.length; i++)
        {
            suma = new Pomnoz(new Stala(suma), wyr[i]).oblicz();
        }

        return suma;
    }

    @Override
    public String toString() {
        return "Wyrazenie{}";
    }

    /**
     Metoda do porównywania tego
     */
    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        Wyrazenie zmienna = (Zmienna) o;

        return o != null ? o.equals(zmienna) : zmienna == null;

    }
}
