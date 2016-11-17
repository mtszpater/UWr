/*
 * Copyright (c) 2016.
 * @author Mateusz Pater
 * @email mtszpater@gmail.com
 *
 */
package narzedzia;
/**
 * Klasa opisująca wartosc wyrazenia Log
 * @author pater
 */
public class Log extends Operator2arg {

    /**
     * Funkcja do obliczania wartości wyrażenia zależnie od zainicjowanych argumentów klasy funkcja
     * @see Funkcja#dodajArgument(double)
     * @return double wartość
     * @throws WyjatekONP w przypadku braku argumentów
     * @throws ONP_BłędneWyrażenie w przypadku złego logarytmu
     */
    @Override
    public double obliczWartosc() throws WyjatekONP {
        super.obliczWartosc();

        if(array[0] <= 1 || array[1] < 0)
            throw new ONP_BłędneWyrażenie("Logarytm bledny");


        return (Math.log(array[1])/Math.log(array[0]));
    }

}

