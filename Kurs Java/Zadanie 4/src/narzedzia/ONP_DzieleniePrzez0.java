/*
 * Copyright (c) 2016.
 * @author Mateusz Pater
 * @email mtszpater@gmail.com
 *
 */
package narzedzia;
/**
 * Klasa opisująca błąd dzielenia przez 0
 * @author pater
 */
public class ONP_DzieleniePrzez0 extends WyjatekONP {

    public ONP_DzieleniePrzez0(String message) {
        super("Dzielenie przez 0: " + message);
    }

}
