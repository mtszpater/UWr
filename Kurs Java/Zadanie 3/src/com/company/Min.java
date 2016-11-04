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
public class Min extends Operator2Arg {

    public Min(Wyrazenie a, Wyrazenie b) {
        super(a,b);
    }

    @Override
    public double oblicz() {

        return Math.min(a.oblicz(), b.oblicz());
    }
    @Override
    public String toString() {
        return "min("+a+"," + b+")";
    }
}
