package com.company;

public class Kwadrat extends Figury {

    private double a;

    public Kwadrat(double a){
        this.a = a;
    }

    public double get_size(){
        return a*a;
    }
    public String toString() {
        return "Pole tego kwadratu " + this.get_size();
    }



}
