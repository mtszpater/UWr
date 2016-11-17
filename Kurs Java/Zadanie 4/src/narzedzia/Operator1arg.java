/*
 * Copyright (c) 2016.
 * @author Mateusz Pater
 * @email mtszpater@gmail.com
 *
 */
package narzedzia;
/**
 * Klasa opisująca operatory 1 argumentowe
 * @author pater
 */
abstract class Operator1arg extends Funkcja {
    /**
     * Ustala arność funkcji 1 argumentowej
     * @return 1
     */
    @Override
    public int arnosc() {
        return 1;
    }
}
