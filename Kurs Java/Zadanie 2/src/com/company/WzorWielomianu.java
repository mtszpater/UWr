package com.company;


import com.company.obliczenia.TrojkatPascala;

public class WzorWielomianu {

    private static String zwroc_operator(int i, boolean isNegative){

        if(isNegative == false) return " + ";

        if ( i%2 == 0)
            return " + ";
        return " - ";
    }

    private static String generuj_poczatek(String s, int n)
    {
        return "(" + s + ")" + "^" + n + " =";
    }


    public static String wartosc_dodatnia(String a, String b, int n, boolean isNegative){

        if(n == 0) return " 1";

        if(n == 1)
        {
            if(isNegative == false) {
                return " " + a + " + " + b;
            }
            else
            {
                return " " + a + " - " + b;
            }
        }

        int stopien_a = n;
        int stopien_b = 0;

        String s="";

        int i = 0;
        for(long x : TrojkatPascala.getTrojkat()[n])
        {
            if(x == 0) continue;

            s += " ";
            if( x != 1 ) s = s+ zwroc_operator(i,isNegative) + x;
            ++i;

            if( stopien_a != 0 )
            {
                if( stopien_a == 1)
                {
                    s = s + a;
                }
                else {
                    s = s + a + "^" + stopien_a;
                }
                --stopien_a;
            }

            if( stopien_b != n+1 )
            {
                if( stopien_b == 1)
                {
                    s = s + b;
                }
                else {
                    if(stopien_b != 0)
                        s = s + b + "^" + stopien_b;
                }
                if( stopien_b+1 == n )
                    s = s + zwroc_operator(i,isNegative);
                ++stopien_b;
            }

        }

        return s;
    }

    public static String oblicz(String s, int n) {

        int p = s.indexOf("+");
        if (p == -1) {
            p = s.indexOf("-");
        }

        if(s.substring(0, p).length() == 0 || s.substring(p + 1).length() == 0)
            throw new IllegalArgumentException("Podales zly format wyrazenia");

        if (p == -1) {
            return generuj_poczatek(s, n) + wartosc_dodatnia(s.substring(0, p), s.substring(p + 1), n, true);
        } else {
            return generuj_poczatek(s, n) + wartosc_dodatnia(s.substring(0, p), s.substring(p + 1), n, false);
        }

    }
    public static void main(String[] args) {

        if(args.length < 2)
            throw new IllegalArgumentException("Za mało argumentów");

        try {

            if(Integer.parseInt(args[1]) < 0 || Integer.parseInt(args[1]) > 66)
                throw new IllegalArgumentException("liczba " + args[1] + " jest błedna");
            else
                System.out.println(oblicz(args[0], new Integer(args[1])));

        } catch (NumberFormatException e) {
            throw new IllegalArgumentException(args[1] + " chyba nie jest liczbą");
        }




    }
}
