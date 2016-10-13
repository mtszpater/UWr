package com.company;



public class Main {


    public static void main(String[] args) {

        Liczebniki liczebniki = new Liczebniki();

        int n;
        for (int i = 0; i < args.length; i++)

            try {
                n = Integer.parseInt(args[i]);

                if(n < 0)
                    throw new IllegalArgumentException("liczba ujemna " + args[i] + " jest błędem");
                else
                    System.out.println(liczebniki.converter( Integer.parseInt(args[i])));

            } catch (NumberFormatException e) {
                throw new IllegalArgumentException(args[i] + " chyba nie jest liczbą");
            }



    }
}
