/*
 * Copyright (c) 2016.
 * @author Mateusz Pater
 * @email mtszpater@gmail.com
 *
 */

package narzedzia;
/**
 * Klasa do obliczania wartości wyrażenia E
 * @author pater
 */
public class E extends Operator0arg{

    /**
     * Funkcja do obliczania wartości wyrażenia zależnie od zainicjowanych argumentów klasy funkcja
     * @see Funkcja#dodajArgument(double)
     * @return double wartość
     * @throws WyjatekONP w przypadku braku argumentów
     */
    @Override
    public double obliczWartosc() throws WyjatekONP {
        return Math.E;
    }
}
