/*
 * Copyright (c) 2016.
 * @author Mateusz Pater
 * @email mtszpater@gmail.com
 *
 */
package narzedzia;

/**
 * Klasa opisująca zmienną
 * @author pater
 */

public class Zmienna extends Operand
{

    public final String identyfikator;

    private double zmienna;

    private final String wzorzec = "\\p{Alpha}\\p{Alnum}*";

    @Override
    public String toString() {
        return "Zmienna{" +
                "identyfikator='" + identyfikator + '\'' +
                ", zmienna=" + zmienna +
                '}';
    }

    public Zmienna(String identyfikator_, double zmienna_)
    {

        if (identyfikator_.matches(wzorzec))
        {
            this.identyfikator = identyfikator_;

        } else
        {
            throw new IllegalArgumentException("Podales identyfikator niepasujacy do wzorca: " + wzorzec);
        }
        this.zmienna = zmienna_;
    }

    @Override
    public double obliczWartosc() throws WyjatekONP
    {
        return zmienna;
    }

}
