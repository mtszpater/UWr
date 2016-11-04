package com.company;

/**
 * author @pater
 */
public class Pomnoz extends Operator2Arg {

    public Pomnoz(Wyrazenie a, Wyrazenie b) {
        super(a,b);
    }

    @Override
    public double oblicz() {
        return a.oblicz() * b.oblicz();
    }
    @Override
    public String toString() {
        return a + "*" + b;
    }
}
