package com.company;
import java.util.*;
public class Main {

    public static void main(String[] args) {
        // write your code here


        Sort z = new Sort();

        z.add(new Kwadrat(2));
        z.add(new Kwadrat(3));
        z.add(new Kolo(4));
        z.add(new Trojkat(10, 3));
        z.add(new Prostokat(10, 3));

        z.print();

        System.out.println("PRZERWA");
        // Element usunięty
        System.out.println(z.get());
        System.out.print(z.get());


    }
}
