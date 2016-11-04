package com.company;

/**
 * author @pater
 */
public class Poteguj extends Operator2Arg {

    public Poteguj(Wyrazenie a, Wyrazenie b) {
        super(a,b);
    }

    @Override
    public double oblicz() {
        return Math.pow(a.oblicz(), b.oblicz());
    }
    @Override
    public String toString() {
        return a + "^" + b;
    }
}
