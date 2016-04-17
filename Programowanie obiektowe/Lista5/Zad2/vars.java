package com.company;
import java.util.Map;

/**
 * Created by teez on 25.03.2016.
 */
public class vars extends wyrazenie{

    private String nazwa;
    private Map<String, Integer> kontekst;

    public vars(String nazwa, Map<String, Integer> kontekst) {
        this.nazwa = nazwa;
        this.kontekst = kontekst;
    }
    public String toString(){
        return " Zmienna o wartosci " + this.oblicz();
    }

    public int oblicz() {
        return kontekst.get(nazwa);
    }

}
