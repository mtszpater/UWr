/*
 * Copyright (c) 2016.
 * @author Mateusz Pater
 * @email mtszpater@gmail.com
 *
 */
package narzedzia;
/**
 * Klasa opisująca błąd błędnego wyrażenia
 * @author pater
 */
public class ONP_BłędneWyrażenie extends WyjatekONP {
    public ONP_BłędneWyrażenie(String message) {
        super("Błędne wyrażenie: " + message);
    }

    public ONP_BłędneWyrażenie() {
        super("Błędne wyrażenie");
    }
}
