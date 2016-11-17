/*
 * Copyright (c) 2016.
 * @author Mateusz Pater
 * @email mtszpater@gmail.com
 *
 */

package narzedzia;
/**
 * Klasa do obliczania wartości wyrażenia floor
 * @author pater
 */
public class Floor extends Operator1arg {

    /**
     * Funkcja do obliczania wartości wyrażenia zależnie od zainicjowanych argumentów klasy funkcja
     * @see Funkcja#dodajArgument(double)
     * @return double wartość
     * @throws WyjatekONP w przypadku braku argumentów
     */
    @Override
    public double obliczWartosc() throws WyjatekONP {
        super.obliczWartosc();
        return Math.floor(array[0]);
    }
}

