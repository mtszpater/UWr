package com.company;

/**
 * author @pater
 */
public class Zmienna extends Wyrazenie {

    static private final Zbior z;

    static {
        z = new Zbior(10);
        z.wstaw(new Para("x", -1.618));
        z.wstaw(new Para("y", 3.0));
        z.wstaw(new Para("z", 4.0));
    }

    private String value;

    public Zmienna(String key) {
        value = key;
    }


    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        Zmienna zmienna = (Zmienna) o;

        return value != null ? value.equals(zmienna.value) : zmienna.value == null;

    }

    @Override
    public String toString() {
        return value;
    }

    @Override

    public double oblicz() {
        return z.czytaj(value);
    }
}
