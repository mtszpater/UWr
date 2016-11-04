package com.company;

/**
 * author @pater
 * definiuje operatory 2-argumentowe
 */
public class Para {

    public final String key;
    private double value;

    public Para(String key, double value) {
        this.key = key;
        this.value = value;
    }

    public double getValue() {
        return value;
    }

    public void setValue(double value) {
        this.value = value;
    }

    public String getKey() {
        return key;
    }

    @Override
    public String toString() {
        return "Para{" +
                "key='" + key + '\'' +
                ", value=" + value +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        Para para = (Para) o;

        return key != null ? key.equals(para.key) : para.key == null;

    }

}
