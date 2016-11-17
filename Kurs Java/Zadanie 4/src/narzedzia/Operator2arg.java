/*
 * Copyright (c) 2016.
 * @author Mateusz Pater
 * @email mtszpater@gmail.com
 *
 */
package narzedzia;
/**
 * Klasa opisująca operatory 2 argumentowe
 * @author pater
 */
abstract class Operator2arg extends Funkcja{
    /**
     * Ustala arność funkcji 2 argumentowej
     * @return 2
     */
    @Override
    public int arnosc() {
        return 2;
    }
}
