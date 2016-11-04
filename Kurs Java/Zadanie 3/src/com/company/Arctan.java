package com.company;

/**
 * author @pater
 */


public class Arctan extends Operator1Arg {

    /* Class constructor */
    public Arctan(Wyrazenie a) {
        super(a);
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
