package com.company;

/**
 * author @pater
 */
public class Logarytmuj extends Operator2Arg {
    private Wyrazenie a;
    private Wyrazenie b;

    public Logarytmuj(Wyrazenie a, Wyrazenie b) {
        this.a = a;
        this.b = b;
    }

    @Override
    public double oblicz() {

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
