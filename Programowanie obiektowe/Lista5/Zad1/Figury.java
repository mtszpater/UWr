package com.company;


abstract class Figury implements Comparable<Figury> {

    abstract double get_size();

    public int compareTo(Figury b){
        if(b.get_size() > get_size()){
            return -1;
        }
        if(b.get_size() < get_size()){
            return 1;
        }
        return 0;
    }

    abstract public String toString();

}

