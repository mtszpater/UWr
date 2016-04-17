package com.company;

public class Prostokat extends Figury  {

    private double a;
    private double b;

    public Prostokat(double a, double b){
        this.a = a;
        this.b = b;
    }

    public double get_size(){
        return a*b;
    }
    public String toString() {
        return "Pole tego prostokatu " + this.get_size();
    }



}

