package com.company;
import java.util.*;

public class Sort <T extends Comparable<? super T>> {

    ArrayList<T> arraylist;

    public Sort(){
        arraylist = new ArrayList<T>();
    }

    public void print(){

        for (T str : arraylist) {
            System.out.println(str);
        }

    }

    public T get(){

        T tmp = arraylist.get(0);

        arraylist.remove(0);

        return tmp;

    }

    public void add(T element){

        arraylist.add(element);

        Collections.sort(arraylist);


    }



}
