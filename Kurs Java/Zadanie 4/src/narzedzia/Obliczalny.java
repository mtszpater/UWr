/*
 * Copyright (c) 2016.
 * @author Mateusz Pater
 * @email mtszpater@gmail.com
 *
 */
package narzedzia;
/**
 * Interfejs opisujący Symbol, każdy obiekt musi być obliczalny
 * @author pater
 */
public interface Obliczalny {
    double obliczWartosc() throws WyjatekONP;
}
