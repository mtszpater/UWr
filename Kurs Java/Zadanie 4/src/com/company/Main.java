/*
 * Copyright (c) 2016.
 * @author Mateusz Pater
 * @email mtszpater@gmail.com
 *
 */
package com.company;

import narzedzia.*;

import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * @author pater
 * Klasa główna programu kalkulatora ONP
 */
public class Main {


    /**
     * Zmienne statyczne
     */
    private static final int CLEAR = 0;
    private static final int CLEAREVERYTHING = 1;
    private static final int CALC = 2;
    private static final String EXIT = "exit";
    private static final int UNDEFINED = -1;


    /**
     * GŁOWNA KLASA INICJALIZUJĄCA PROGRAM
     */
    static void init()
    {

        SLL l = new SLL();

        Scanner odczyt = new Scanner(System.in);
        String command = odczyt.nextLine();
        Wyrazenie wyr;

        while( ! command.equals(EXIT) ) {

            switch (numberOfOperation(command)) {

                case CLEAREVERYTHING:

                    System.out.println("Wszystkie zmienne zostały skasowane");
                    l = new SLL();
                    break;

                case CLEAR:

                    deleteVariableFromList(l, command);
                    break;

                case CALC:

                    try {

                        wyr = new Wyrazenie(cutToOnlyONP(command), l);

                        l = AddVariableToList(l, wyr.wynik(), command);

                        System.out.println( wyr.wynik() );


                    } catch (WyjatekONP wyjatekONP) {
                        System.out.println( "[BŁĄD] : "+ wyjatekONP.getMessage() );
                    }

                    break;

                default:
                    throw new AssertionError(command);
            }
            command = odczyt.nextLine();
        }


    }


    /**
     * Zwraca rodzaj operacji
     * @param v string
     * @return int
     */
    static int numberOfOperation( String v )
    {
        if( v.startsWith("clear") ) {
            if (v.matches("(?i).* \\p{Alpha}\\p{Alnum}*.*")) {
                return CLEAR;
            }
            return CLEAREVERYTHING;
        }
        if( v.startsWith("calc") )
            return CALC;

        return UNDEFINED;

    }

    /**
     * Sprawdzamy ile jest zmiennych w wyrazeniu
     * @param v string
     * @return int
     */
    static int howManyVariable( String v ){

        String pattern = "\\p{Alpha}\\p{Alnum}* =";

        Pattern r = Pattern.compile(pattern);
        Matcher m = r.matcher(v);

        int count = 0;
        while(m.find()) {
            count++;
        }

        return count;
    }

    /**
     * Ucina stringa do postaci samego wyrazenia ONP
     * @param v string
     * @return string cutted
     */
    static String cutToOnlyONP ( String v ){

        v = v.replace("calc ", "");

        if(howManyVariable(v) == 0)
            return v;


        int p = v.indexOf("=");

        String first = v.substring(0, p-2);

        return first;
    }


    /**
     *
     * @param list lista zmiennych
     * @param value wartość zmiennej
     * @param ONP wyrazenie
     * @return
     */
    static SLL AddVariableToList( SLL list, double value, String ONP )
    {

        Matcher m = Pattern.compile("\\p{Alpha}\\p{Alnum}* =").matcher(ONP);

        while (m.find()){

            String variable = m.group().replace(" =", "");

            if( list.search(variable) > 0)
                list.removeAt(list.search(variable));


            list.insertLast(new Zmienna(variable, value));

        }

        return list;
    }


    /**
     * Kasuje zmienna/zmienne z listy
     * @param list lista zmiennych
     * @param ONP wyrazenie onp
     */
    static void deleteVariableFromList( SLL list, String ONP )
    {
        ONP = ONP.replace("clear ", "");

        Matcher m = Pattern.compile("\\p{Alpha}\\p{Alnum}*").matcher(ONP);

        while (m.find()){

            System.out.println("Usuwam: "+ list.removeAt(list.search(m.group())));

        }

    }

    public static void main(String[] args) throws WyjatekONP {

        init();

    }
}
