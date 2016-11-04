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
public class Sinus extends Operator1Arg {

    public Sinus(Wyrazenie a) {
        super(a);
    }

    @Override
    public double oblicz() {
        return Math.sin(a.oblicz());
    }
    @Override
    public String toString() {
        return "sinus("+a+")";
    }

}
