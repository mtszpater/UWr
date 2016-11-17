/*
 * Copyright (c) 2016.
 * @author Mateusz Pater
 * @email mtszpater@gmail.com
 *
 */
package narzedzia;
/**
 * Klasa opisująca wartosc wyrazenia Ln
 * @author pater
 */
public class Ln extends Operator1arg {


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

        if(array[0] < 0)
        {
            throw new ONP_BłędneWyrażenie("logarytm błędny");
        }

        return Math.log(array[0]);
    }
}

