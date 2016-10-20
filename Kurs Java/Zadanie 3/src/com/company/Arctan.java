package com.company;

/**
 * author @pater
 */
public class Arctan extends Operator1Arg {
    private Wyrazenie a;

    public Arctan(Wyrazenie a) {
        this.a = a;
    }

    @Override
    public double oblicz() {
        return Math.atan(a.oblicz());
    }
    @Override
    public String toString() {
        return "arctan("+a+")";
    }

}
