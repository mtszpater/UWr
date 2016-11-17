/*
 * Copyright (c) 2016.
 * @author Mateusz Pater
 * @email mtszpater@gmail.com
 *
 */
package narzedzia;
/**
 * Klasa opisująca wartość wyrażenia Pi
 * @author pater
 */
public class Pi extends Operator0arg {

    /**
     * Funkcja do obliczania wartości wyrażenia zależnie od zainicjowanych argumentów klasy funkcja
     * @see Funkcja#dodajArgument(double)
     * @return double wartość
     */
    @Override
    public double obliczWartosc() throws WyjatekONP {
        return Math.PI;
    }
}
