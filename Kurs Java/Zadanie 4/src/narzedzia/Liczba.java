/*
 * Copyright (c) 2016.
 * @author Mateusz Pater
 * @email mtszpater@gmail.com
 *
 */
package narzedzia;
/**
 * Klasa opisująca liczbę
 * @author pater
 */
public class Liczba implements Obliczalny{

    double wart;

    /**
     * Konstruktor z ustaleniem wartości liczby
     * @param wart wartość liczby
     */
    public Liczba(double wart) {
        this.wart = wart;
    }

    /**
     * Funkcja do obliczania wartości wyrażenia zależnie od zainicjowanych argumentów klasy funkcja
     * @see Funkcja#dodajArgument(double)
     * @return double wartość
     * @throws WyjatekONP w przypadku braku argumentów
     */
    @Override
    public double obliczWartosc() throws WyjatekONP {
        return wart;
    }
}
