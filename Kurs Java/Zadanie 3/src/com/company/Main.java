/*
 * Copyright (c) 2016. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
 * Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
 * Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
 * Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
 * Vestibulum commodo. Ut rhoncus gravida arcu.
 */

package com.company;

public class Main {

    public static void main(String[] args) {


        Para a = new Para("key", 2.0);
        Para b = new Para("key", 2.3);
        Para c = new Para("key2", 2.1);

        if (a.equals(b)) System.out.println(a + " jest podobne do " + b);
        if (a.equals(c)) {
            System.out.println(a + " jest podobne do " + b);
        } else
        {
            System.out.println(a + " nie jest podobne do " + b);
        }



        Zbior z = new Zbior(3);

        z.wstaw(a);
        z.wstaw(b); // Nie, bo klucz ten sam
        z.wstaw(c);

        System.out.println(z.szukaj("key"));

        System.out.println(z);


        // Spróbujmy teraz resztę metod

        System.out.println("Szukaj 'key' = " + z.szukaj("key"));
        System.out.println("Ile ich mamy w zbiorze? = " + z.ile());
        System.out.println("Jaka ma wartosc para o kluczu key = " + z.czytaj("key"));
        // Ustalmy teraz nowa pare dla klucza = key
        z.ustal(b);
        System.out.println("Jaka ma wartosc para o kluczu TERAZ key = " + z.czytaj("key"));
        // Koniec imprezy, wyczyśćmy.
        z.czysc();
        System.out.println("Po wyczyszczeniu: " + z);




        Wyrazenie a_x = new Dodaj( new Stala(3.0), new Stala(5.0));

        System.out.println(a_x + " = " + a_x.oblicz());

        Wyrazenie c_x = new Dodaj( new Stala(3.0), new Pomnoz(new Zmienna("x"), new Stala(7.0)));

        System.out.println(c_x + " = " + c_x.oblicz());

        Wyrazenie b_x = new Podziel(
                new Odejmij(
                        new Pomnoz(
                                new Stala(3.0),
                                new Stala(11.0)),
                        new Stala(1.0)),
                new Dodaj(
                        new Stala(7.0),
                        new Stala(5.0)
                ));

        System.out.println(b_x + " = " + b_x.oblicz());

        Wyrazenie d = new Arctan(
                new Podziel(
                        new Pomnoz(
                                new Dodaj(
                                        new Zmienna("x"),
                                        new Stala(13.0)
                                ),
                                new Zmienna("x")
                        ),
                        new Stala(2.0)
                )
        );
        System.out.println(d + " = " + d.oblicz());

        Wyrazenie e = new Dodaj(
                new Poteguj(new Stala(2.0), new Stala(5.0)),
                new Pomnoz(
                        new Zmienna("x"),
                        new Logarytmuj(new Stala(2.0), new Zmienna("y"))
                )
        );
        System.out.println(e + " = " + e.oblicz());






        // Przetestujmy sumowanie i mnozenie
        Wyrazenie[] s = new Wyrazenie[3];
        s[0] = new Stala(5);
        s[1] = new Stala(3);
        s[2] = new Stala(3);

        System.out.println("Dodawanie wynik: " + Wyrazenie.sumuj(s));
        System.out.println("Mnozenie wynik: " + Wyrazenie.pomnoz(s));



        // Test reszty wyrazen

        System.out.println(new Bezwgledna(new Stala(-5.0)) + " = " + new Bezwgledna(new Stala(-5.0)).oblicz() );
        System.out.println(new Cosinus(new Stala(-5.0)) + " = " + new Cosinus(new Stala(-5.0)).oblicz() );
        System.out.println(new Sinus(new Stala(0.20)) + " = " + new Sinus(new Stala(0.20)).oblicz() );
        System.out.println(new Odwrotna(new Stala(2)) + " = " + new Odwrotna(new Stala(2)).oblicz() );
        System.out.println(new Przeciwna(new Stala(-5.0)) + " = " + new Przeciwna(new Stala(-5.0)).oblicz() );
        System.out.println(new Max(new Stala(-5.0), new Zmienna("x")) + " = " + new Max(new Stala(-5.0), new Zmienna("x")).oblicz() );
        System.out.println(new Min(new Stala(-5.0), new Zmienna("x")) + " = " + new Min(new Stala(-5.0), new Zmienna("x")).oblicz() );
        System.out.println(new Modulo(new Stala(-5.0), new Zmienna("x")) + " = " + new Modulo(new Stala(-5.0), new Zmienna("x")).oblicz() );


    }


}
