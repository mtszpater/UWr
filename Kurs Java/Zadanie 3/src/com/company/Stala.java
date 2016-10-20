package com.company;

/**
 * author @pater
 */
public class Stala extends Wyrazenie {
    double value;

    public Stala(double value) {
        this.value = value;
    }

    @Override
    public double oblicz() {
        return value;
    }

    @Override
    public String toString() {
        return ""+value;
    }
}

