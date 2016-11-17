/*
 * Copyright (c) 2016.
 * @author Mateusz Pater
 * @email mtszpater@gmail.com
 *
 */

package narzedzia;
/**
 * Klasa opisująca Element kolejki
 */
class Element {
    private Funkcja wartosc;
    private Element next;

    /**
     * Konstruktor Elementu kolejki
     * @param x funkcja
     */
    public Element(Funkcja x){
        wartosc = x;
        next = null;
    }

    public void setNext(Element e){
        next = e;
    }


}
/**
 * Klasa opisująca kolejkę
 */
class Kolejka {
    Element first, last;

    public Kolejka(){
        first = last = null;
    }

    /**
     * Dodawanie nowego elementu kolejki
     * @param x funkcja
     */
    public void add(Funkcja x){

        Element temp = new Element(x);
        if(first==null){
            first = last = temp;
        }
        else {
            last.setNext(temp);
            temp.setNext(last);
            last = temp;
        }

    }



}
