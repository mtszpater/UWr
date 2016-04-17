package com.company;

public class Kolo extends Figury  {
    private int r;

    public Kolo(int r){
        this.r = r;
    }

    public double get_size(){
        return r*r*3.14;
    }
    public String toString() {
        return "Pole tego kola " + this.get_size();
    }

}
