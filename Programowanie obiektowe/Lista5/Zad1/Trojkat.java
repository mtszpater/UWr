package com.company;

public class Trojkat extends Figury  {

    private double a;
    private double h;

    public Trojkat(double a, double h){
        this.a = a;
        this.h = h;
    }

    public double get_size(){
        return a*h/2;
    }
    public String toString() {
        return "Pole tego trojkata " + this.get_size();
    }

}
