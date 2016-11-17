/*
 * Copyright (c) 2016.
 * @author Mateusz Pater
 * @email mtszpater@gmail.com
 *
 */

package narzedzia;
/**
 * Interfejs opisujący funkcję
 * @author pater
 */
public interface Funkcyjny extends Obliczalny {
    int arnosc();
    int brakujaceArgumenty();
    void dodajArgument (double k) throws WyjatekONP;
}
