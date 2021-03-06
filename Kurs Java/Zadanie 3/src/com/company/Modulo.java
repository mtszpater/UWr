/*
 * Copyright (c) 2016. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
 * Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
 * Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
 * Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
 * Vestibulum commodo. Ut rhoncus gravida arcu.
 */

package com.company;

/**
 * author @pater
 */
public class Modulo extends Operator2Arg {

    public Modulo(Wyrazenie a, Wyrazenie b) {
        super(a,b);

    }

    @Override
    public double oblicz() {

        if(b.oblicz() == 0)
        {
            throw new IllegalArgumentException("Cholero, nie dziel przez 0:>");
        }

        return a.oblicz() % b.oblicz();
    }
    @Override
    public String toString() {
        return  a + "mod" + b;
    }
}
