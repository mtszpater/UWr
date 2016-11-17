/*
 * Copyright (c) 2016.
 * @author Mateusz Pater
 * @email mtszpater@gmail.com
 *
 */
package narzedzia;
/**
 * Klasa opisująca błąd nieznanego symbolu
 * @author pater
 */
public class ONP_NieznanySymbol extends WyjatekONP {
    public ONP_NieznanySymbol(String message) {
        super("Nieznany Symbol: " + message);
    }
}
