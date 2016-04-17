package com.company;

import java.awt.EventQueue;

import javax.swing.JFrame;

public class Main
{
    public static void main(String[] args)
    {

         JFrame ex;

                System.out.println(args[1]);
                System.out.println(args[0]);

                // 1 - Tramwaj, 0 - Samochod
                if(args[1].toString().compareTo("Tramwaj") ==  0) {
                    ex = new SamochodEdit(args[0], 1);
                    ex.setVisible(true);
                }
                else if(args[1].toString().compareTo("Samochod") == 0){
                    ex = new SamochodEdit(args[0], 0);
                    ex.setVisible(true);
                }else{
                    System.out.println("Zla nazwa klasy");
                }



    }
}