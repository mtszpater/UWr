package com.company;

import java.io.Serializable;

/**
 * Created by teez on 11.04.2016.
 */
public class Pojazd implements Serializable {

    private static final long serialVersionUID = 4661681646491395516L;
    int year;
    String name;
    String color;


    public void setColor( String _color ) {
        this.color = _color;
    }
    public void setYear( int _year ) {
        this.year = _year;
    }
    public void setName( String _name ) {
        this.name = _name;
    }

    public String getColor( ) {
        return this.color;
    }
    public int getYear( ) {
        return this.year;
    }
    public String getName( ) {
        return this.name;
    }

}
