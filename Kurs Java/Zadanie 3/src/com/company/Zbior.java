package com.company;

import java.util.Arrays;

/**
 * author @pater
 * Definiuje zbiór
 */
public class Zbior {

    private int max = 10;
    private int stos;
    private Para[] pary;

    public Zbior(int max) {
        if (max < 0)
            throw new IllegalArgumentException("Za mało elementow zbioru");

        this.max = max;
        Rozpocznij();
    }

    public Zbior() {
        Rozpocznij();
    }

    /**
     * ustala rozmiar zbioru
     */
    private void Rozpocznij() {
        this.pary = new Para[max];
        this.stos = 0;
    }


    /**
     *
     * @return String
     */
    @Override
    public String toString() {
        return "Zbior{" +
                "max=" + max +
                ", stos=" + stos +
                ", pary=" + Arrays.toString(pary) +
                '}';
    }

    /**
     * Szuka po kluczu
     * @param kl string
     * @return Para
     */

    public Para szukaj(String kl) {

        for (int i = 0; i < stos; ++i) {
            if (kl.compareTo(pary[i].getKey()) == 0) {
                return pary[i];
            }
        }
        return null;
    }

    /**
     * Wstawia pare
     * @param p Para
     * @throws IllegalArgumentException rzuc wyjatkiem kiedy zbior pelny
     */
    public void wstaw(Para p) throws IllegalArgumentException {
        if (max < stos + 1) {
            throw new IllegalArgumentException("Zbiór pełny");
        }

        if (szukaj(p.getKey()) != null) {
            System.out.println("Para z takim kluczem już istnieje");
        } else {
            System.out.println("Para dodana");
            pary[stos] = p;
            ++stos;
        }

    }

    /**
     * Czyta po kluczu
     * @param kl String
     * @return double
     */
    public double czytaj(String kl) {
        return szukaj(kl).getValue();
    }

    /**
     * Wrzuca pare nawet jesli istnieje o podanym ID
     * @param p Para
     */

    public void ustal(Para p){

        if (szukaj(p.getKey()) != null) {

            szukaj(p.getKey()).setValue(p.getValue());


        } else {
            wstaw(p);
        }


    }

    /**
     * Zwraca ilosc elementów zbioru
     * @return int
     */
    public int ile() {
        return stos;
    }

    /**
     *  Funkcja czyści całkowicie zbiór
     */
    public void czysc () {
        Rozpocznij();
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Zbior)) return false;

        Zbior zbior = (Zbior) o;

        if (max != zbior.max) return false;
        if (stos != zbior.stos) return false;
        // Probably incorrect - comparing Object[] arrays with Arrays.equals
        return Arrays.equals(pary, zbior.pary);

    }

}
