package com.company;
import java.util.Map;
import java.util.HashMap;

public class Main {

    public static void main(String[] args) {

        nums k = new nums(5);

        Map<String, Integer> map = new HashMap<String, Integer>();

        map.put("Y", 10);

        vars v = new vars("Y", map);

        wyrazenie wyr;

        wyr = new Dodaj(k, v);

        System.out.println(wyr.toString());

        wyr = new Odejmij(k, v);

        System.out.println(wyr.oblicz());

        wyr = new Pomnoz(k, v);

        System.out.println(wyr.oblicz());

        /* Zagnieżdżanie */

        nums z = new nums(wyr.oblicz()); // 50
        wyr = new Dodaj(z, v); // 50 + 10
        nums z1 = new nums(wyr.oblicz()); // 60

        wyr = new Dodaj(z, z1); // 50+60
        System.out.println(wyr.oblicz()); // 110


	// write your code here
    }
}
