package com.company;

/**
 * Created by teez on 25.03.2016.
 */
public class Odejmij extends wyrazenie {

    int a;
    int b;


    public Odejmij(wyrazenie a, wyrazenie b){
        this.a = a.oblicz();
        this.b = b.oblicz();
    }
    public String toString(){
        return " Wynikiem bedzie suma " + this.a + " - " +  this.b;
    }

    public int oblicz() {
        return this.a-this.b;
    }
}
