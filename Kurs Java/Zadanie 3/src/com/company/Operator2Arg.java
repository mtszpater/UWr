package com.company;

/**
 * author @pater
 */

public abstract class Operator2Arg extends Operator1Arg
{
    protected final Wyrazenie b;

    public Operator2Arg (Wyrazenie a1, Wyrazenie a2) {
        super(a1);
        if (a2==null) throw new IllegalArgumentException();
        b = a2;
    }
}