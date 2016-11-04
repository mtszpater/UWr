package com.company;

/**
 * author @pater
 */
public class Podziel extends Operator2Arg{

    public Podziel(Wyrazenie a, Wyrazenie b) {
        super(a,b);

    }

    @Override
    public double oblicz() {

        if(b.oblicz() == 0)
        {
            throw new IllegalArgumentException("Cholero, ie dziel przez 0:>");
        }

        return a.oblicz() / b.oblicz();
    }
    @Override
    public String toString() {
        return  a + "/" + b;
    }
}
