/*
 * Copyright (c) 2016.
 * @author Mateusz Pater
 * @email mtszpater@gmail.com
 *
 */

package narzedzia;

import java.io.IOException;
import java.util.logging.FileHandler;
import java.util.logging.Logger;
import java.util.logging.SimpleFormatter;

/**
 * Główna klasa zarządzająca wyrażeniem ONP
 * @author pater
 */
public class Wyrazenie
{

    /**
     * Kolejka symboli wyrażenia ONP (elementy typu Symbol).
     */
    private Kolejka kolejka;
    /**
     * Stos z wynikami pośrednimi obliczeń (elementy typu double).
     */
    private Stos stos;
    /**
     * Lista zmiennych czyli pary klucz-wartość (String-double).
     */
    private SLL zmienne;

    /**
     * Obsługuje logowanie aktywności do pliku.
     */
    public static final Logger loger = Logger.getLogger(Wyrazenie.class.getName());
    private static FileHandler fh;

    static
    {
        try
        {
            fh = new FileHandler("calc.log", false);
            loger.addHandler(fh);
            SimpleFormatter formatter = new SimpleFormatter();
            fh.setFormatter(formatter);
            loger.setUseParentHandlers(false);
            loger.info("Uruchomiono KalkulatorONP");
        } catch (IOException ex)
        {
            System.err.println(ex.getMessage());
        } catch (SecurityException ex)
        {
            System.err.println(ex.getMessage());
        }
    }

    /**
     * Konstruuje wyrażenie z podanym napisem zawierającym ONP oraz listą
     * zmiennych.
     *
     * @param onp napis zawierający wyrażenie ONP
     * @param zm lista zmiennych ( pary klucz-wartość)
     * @throws WyjatekONP w przypadku braku zmiennej
     */
    public Wyrazenie(String onp, SLL zm) throws WyjatekONP
    {
        kolejka = new Kolejka();
        zmienne = zm;
        String[] tokeny = onp.split("\\s+");
        stos = new Stos();

        loger.info("Zainicjalizowano wyrażenie: " + onp);
        for (int i = 0; i < tokeny.length; ++i)
        {
            if (tokeny[i].matches("\\d+.\\d+") || tokeny[i].matches("-\\d+.\\d+") || tokeny[i].matches("-\\d+.") || tokeny[i].matches("\\d+"))
            {
                loger.info("Wsadzilem na stos:" +  tokeny[i]);
                stos.push(Double.parseDouble(tokeny[i]));
            }
            else if (tokeny[i].matches("\\p{Alpha}\\p{Alnum}*") && !zawiera(tokeny[i]))
            {

                if(zmienne.search(tokeny[i]) == -1)
                    throw new WyjatekONP("Nie ma takiej zmiennej: " + tokeny[i]);

                stos.push(zmienne.searchToValue(tokeny[i]));
                loger.info("Tutaj sie cos dzieje");
            }
            else if (tokeny[i].toLowerCase().equals("pi") || tokeny[i].toLowerCase().equals("e"))
            {
                if (tokeny[i].toLowerCase().equals("pi"))
                {
                    stos.push(new Pi().obliczWartosc());
                }
                else
                {
                    stos.push(new E().obliczWartosc());
                }
            }
            else
            {

                Funkcja f = zamien(tokeny[i]);
                kolejka.add(f);

                while (f.brakujaceArgumenty() > 0)
                {
                    if (stos.zlicz() != 0)
                    {
                        double argument = stos.value();
                        f.dodajArgument(argument);
                        stos.pop();
                    } else
                    {
                        throw new ONP_PustyStos("");
                    }
                }
                stos.push(f.obliczWartosc());

            }
            stos.show();
        }
        loger.info("Obliczono wyrażenie " + onp + "  = " + wynik());
    }

    /**
     * Zwraca wynik obliczonego wyrażenia ONP.
     *
     * @return wynik skonstruowanego wyrażenia
     * @throws ONP_BłędneWyrażenie w przypadku zlego wyrazenia
     */
    public double wynik() throws WyjatekONP
    {
        if(stos.zlicz() != 1)
            throw new ONP_BłędneWyrażenie();

        return stos.value();
    }

    /**
     * Funkcja sprawdzająca, czy podany napis należy do zbioru operatorów.
     *
     * @param s napis do sprawdzenia
     * @return <code>true</code> jeśli napis jest jednym z operatorów,
     * <code>false</code> w przeciwnym wypadku
     */
    private boolean zawiera(String s)
    {
        boolean zawiera = false;

        String[] oper =
                {
                        "+", "-", "*", "/",
                        "abs", "acot", "atan", "ceil", "cos", "e", "exp", "floor",
                        "frac", "ln", "log", "max", "min", "pi", "^", "sgn", "sin"
                };


        for (int i = 0; i < 21; i++)
        {
            if (s.equals(oper[i]))
            {
                zawiera = true;
                break;
            }
        }
        return zawiera;
    }

    /**
     * Zwraca Funkcję odpowiadającą (nazwą i typem) podanemu napisowi.
     *
     * @param s nazwa funkcji
     * @return Obiekt typu <code>Funkcja</code> odpowiadający napisowi
     * @throws ONP_NieznanySymbol jeśli nie istnieje funkcja odpowiadająca
     * podanemu napisowi.
     */
    private Funkcja zamien(String s) throws WyjatekONP
    {
        s = s.toLowerCase();
        switch (s) {
            case "+":
                return new Dodawanie();
            case "-":
                return new Odejmowanie();
            case "*":
                return new Mnozenie();
            case "/":
                return new Dzielenie();
            case "abs":
                return new Abs();
            case "acot":
                return new Acot();
            case "atan":
                return new Atan();
            case "ceil":
                return new Ceil();
            case "cos":
                return new Cos();
            case "exp":
                return new Exp();
            case "floor":
                return new Floor();
            case "ln":
                return new Ln();
            case "log":
                return new Log();
            case "max":
                return new Max();
            case "min":
                return new Min();
            case "^":
                return new Pow();
            case "sgn":
                return new Sgn();
            case "sin":
                return new Sin();
            default:
                throw new ONP_NieznanySymbol(s);
        }
    }
}
