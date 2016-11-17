/*
 * Copyright (c) 2016.
 * @author Mateusz Pater
 * @email mtszpater@gmail.com
 *
 */
package narzedzia;
/**
 * Klasa opisująca błąd pustego stosu
 * @author pater
 */
public class ONP_PustyStos extends WyjatekONP {
    public ONP_PustyStos(String message) {
        super("Pusty stos: " + message);
    }
}
