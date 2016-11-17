/*
 * Copyright (c) 2016.
 * @author Mateusz Pater
 * @email mtszpater@gmail.com
 *
 */

package narzedzia;
/**
 * Klasa do obliczania wartości wyrażenia dzielenia
 * @author pater
 */

public class Dzielenie extends Operator2arg{

    /**
     * Funkcja do obliczania wartości wyrażenia zależnie od zainicjowanych argumentów klasy funkcja
     * @see Funkcja#dodajArgument(double)
     * @return double wartość
     * @throws WyjatekONP w przypadku braku argumentów
     * @throws ONP_DzieleniePrzez0 w przypadku dzielenia przez 0
     */
    @Override
    public double obliczWartosc() throws WyjatekONP {
        super.obliczWartosc();

        if( array[0] == 0 )
            throw new ONP_DzieleniePrzez0(array[1].toString() + " / " + array[0].toString());

        return array[1] / array[0];
    }
}
