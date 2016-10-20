package com.company;

/**
 * author @pater
 */
public class Liczebniki {

    private static final String[] jed_glowne = {
            "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
            "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

    private static final String[] jed_porzad = {
            "zeroth", "first", "second", "third", "fourth", "fifth", "sixth", "seventh", "eighth", "ninth", "tenth",
            "eleventh", "twelfth", "thirteenth", "fourteenth", "fifteenth", "sixteenth", "seventeenth", "eighteenth", "nineteenth"};

    private static final String[] dzies_glowne = {
            "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

    private static final String[] dzies_porzad = {
            "twentieth", "thirtieth", "fortieth", "fiftieth", "sixtieth", "seventieth", "eightieth", "ninetieth"};

    private static final String[] duze_glowne = {
            "thousand", "million", "billion"};

    private static final String[] duze_porzad = {
            "hundredth", "thousandth", "millionth", "billionth"};





    /* Zamienmy ostatnia liczbę, aby uzyskać formę liczebnika */
    private String getLastNumber( int n, int i )
    {
        int tmp_i = i;
        while( i != 0){
            n *= 10;
            --i;
        }

        if( n > 99 )
            return getLastNumberBiggerThan99(tmp_i);
        if (n < 20) {
            return jed_porzad[n];
        }

        if (n % 10 == 0) {
            return dzies_porzad[n / 10 - 2];
        }

        return dzies_glowne[n / 10 - 2] + "-" + jed_porzad[n % 10];
    }


    /* Ile zer, taka liczba. Tysiace, Miliony, Miliardy */
    private String getLastNumberBiggerThan99(int i) {

        if( i == 2 )
            return duze_porzad[i-2];
        else if( i == 3 )
            return duze_porzad[i-2];
        else if(i > 3 && i <= 8)
            return duze_porzad[2];
        else
            return duze_porzad[3];

    }

    private String returnLastNumberSuffix( int n )
    {

        switch (n%10) {
            case 1:
                return "st";
            case 2:
                return "nd";
            case 3:
                return "rd";
            default:
                return "th";
        }

    }


    public String converter( int n )
    {
        if( n == 0 ) return "zero (0th)" ;

        String result = convertNumberToWords(n);


        int k = 0;
        int i = 0;
        int z = n;

        /* Niszczmy zera, liczmy je */
        while( z % 10 == 0) {
            ++i;
            z /= 10;
        }


        if(z % 10 != 0)
        {
            if( i == 0) {
                if (z % 100 != 0)
                    k = z % 100;
            }
            else
                k = z % 10;
        }

        result = result.substring(0, result.lastIndexOf(" ") + 1) +getLastNumber(k, i) + " ("+n+returnLastNumberSuffix(n)+")";

        return result;
    }

    private String convertNumberToWords (int n) {

        if (n <= 999) {
            return convertLessThan1000(n);
        }


        String s = null;
        int t = 0;


        while (n > 0) {
            if (n % 1000 != 0) {

                String s2 = convertLessThan1000(n % 1000);

                if (t > 0) {
                    s2 = s2 + " " + duze_glowne[t-1];
                }


                if (s == null) {
                    s = s2;
                }
                else {
                    s = s2 + " " + s;
                }

            }
            n /= 1000;
            t++;
        }


        return s; }

    private String convertLessThan1000 (int n)
    {
        String s1 = jed_glowne[n / 100] + " hundred";

        String s2 = convertLessThan100(n % 100);


        if (n <= 99) {
            return s2;
        }
        else if (n % 100 == 0) {
            return s1;
        }
        else {
            return s1 + " " + s2;
        }
    }


    private String convertLessThan100 (int n) {
        if (n < 20) {
            return jed_glowne[n];
        }
        String s = dzies_glowne[n / 10 - 2];
        if (n % 10 == 0) {
            return s;
        }
        return s + "-" + jed_glowne[n % 10];
    }

}
