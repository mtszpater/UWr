package com.company;

/**
 * author @pater
 * Definiuje operatory 1-argumentowe
 */

public abstract class Operator1Arg extends Wyrazenie
{
    protected final Wyrazenie a;

    public Operator1Arg (Wyrazenie a1) {
        if (a1==null) throw new IllegalArgumentException();
        a = a1;
    }
}