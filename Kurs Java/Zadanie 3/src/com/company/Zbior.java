package com.company;

import java.util.Arrays;

/**
 * author @pater
 */
public class Zbior {

    int max = 10;
    int stos;
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

    private void Rozpocznij() {
        this.pary = new Para[max];
        this.stos = 0;
    }


    @Override
    public String toString() {
        return "Zbior{" +
                "max=" + max +
                ", stos=" + stos +
                ", pary=" + Arrays.toString(pary) +
                '}';
    }

    public Para szukaj(String kl) {

        for (int i = 0; i < stos; ++i) {
            if (kl.compareTo(pary[i].getKey()) == 0) {
                return pary[i];
            }
        }
        return null;
    }

    public void wstaw(Para p) throws IllegalArgumentException {
        if (max < stos + 1) {
            System.out.println("Zbior pelny");
            return;
        }

        if (szukaj(p.getKey()) != null) {
            System.out.println("Para z takim kluczem już istnieje");
        } else {
            System.out.println("Para dodana");
            pary[stos] = p;
            ++stos;
        }

    }


    public double czytaj(String kl) throws IllegalArgumentException {
        return szukaj(kl).getValue();
    }

    public void ustal(Para p) throws IllegalArgumentException {

        if (szukaj(p.getKey()) != null) {

            szukaj(p.getKey()).setValue(p.getValue());


        } else {
            wstaw(p);
        }


    }

    public int ile() {
        return stos;
    }

    public void czysc () {
        Rozpocznij();
    }
}
