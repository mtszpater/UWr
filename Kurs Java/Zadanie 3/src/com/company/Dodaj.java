package com.company;

/**
 * author @pater
 */
public class Dodaj extends Operator2Arg {

    public Dodaj(Wyrazenie a, Wyrazenie b) {
        super(a,b);
    }

    @Override
    public double oblicz() {
        return a.oblicz() + b.oblicz();
    }
    @Override
    public String toString() {
        return "(" + a + "+" + b + ")";
    }
}
