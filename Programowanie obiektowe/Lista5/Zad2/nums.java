package com.company;

/**
 * Created by teez on 25.03.2016.
 */
public class nums extends wyrazenie{

    private int value;

    public nums( int value ){
        this.value = value;
    }

    public String toString(){
        return " Stala o wartosci " + this.oblicz();
    }

    public int oblicz(){
        return value;
    }
}
