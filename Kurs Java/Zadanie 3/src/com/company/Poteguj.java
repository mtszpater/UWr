package com.company;

/**
 * author @pater
 */
public class Poteguj extends Operator2Arg {
    private Wyrazenie a;
    private Wyrazenie b;

    public Poteguj(Wyrazenie a, Wyrazenie b) {
        this.a = a;
        this.b = b;
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
