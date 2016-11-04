package com.company;

/**
 * author @pater
 */
public class Logarytmuj extends Operator2Arg {

    public Logarytmuj(Wyrazenie a, Wyrazenie b) {
        super(a,b);
    }
    @Override
    public double oblicz() throws IllegalArgumentException {

        if(a.oblicz() <= 1 || b.oblicz() < 0)
        {
            throw new IllegalArgumentException("Logarytm bledny");
        }

        return a.oblicz() * b.oblicz();
    }

    @Override
    public String toString() {
        return "log("+a+"," + b+")";
    }
}
