package com.company;

/**
 * Created by teez on 11.04.2016.
 */
public class Tramwaj extends Pojazd  {

    private static final long serialVersionUID = -3614949347444157588L;

    public Tramwaj(String _name, String _color, int _year) {
        this.color = _color;
        this.year = _year;
        this.name = _name;
    }

    @Override

    public String toString() {
        return "Tramwaj o kolorze " + this.color + " oraz marce " + this.name + " z roku " + this.year;
    }

}
