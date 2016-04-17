package com.company;
import java.awt.*;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.io.*;
import java.time.Year;
import java.util.*;
import javax.swing.*;

/**
 * Created by teez on 11.04.2016.
 */
public class SamochodEdit extends JFrame implements ActionListener, Serializable {


    private static final long serialVersionUID = 1L;
    public JButton Save, Delete, Print;
    public JTextField NameText, ColorText, YearText;
    public JLabel Status;
    Pojazd car;
    String path;
    int type;

    public SamochodEdit(String path, int type) {

        this.path = path;
        this.type = type;
        ReadFromFile();
        initUI();

    }

    void WriteToFile(){

        FileOutputStream fos = null;
        ObjectOutputStream oos = null;
        try {
            fos= new FileOutputStream(this.path); //utworzenie strumienia wyjściowego
            oos = new ObjectOutputStream(fos);  //utworzenie obiektu zapisującego do strumienia

            oos.writeObject(car); //serializacja obiektu

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            // zamykamy strumienie w finally
            try {
                if (oos != null) oos.close();
            } catch (IOException e) {}
            try {
                if (fos != null) fos.close();
            } catch (IOException e) {}
        }
    }

    void ReadFromFile(){

        FileInputStream fis = null;
        ObjectInputStream ois = null;
        try {
            fis = new FileInputStream(this.path); //utworzenie strumienia wejściowego
            ois = new ObjectInputStream(fis); //utworzenie obiektu odczytującego obiekty ze strumienia

            car = (Pojazd) ois.readObject(); //deserializacja obiektu

        } catch (FileNotFoundException e) {
            if(type == 0) {
                car = new Samochod("Default", "Default", 2000);
            }else {
                car = new Tramwaj("Default", "Default", 2000);
            }

        } catch (IOException e) {
            e.printStackTrace();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        } finally {
            // zasoby zwalniamy w finally
            try {
                if (ois != null) ois.close();
            } catch (IOException e) {}
            try {
                if (fis != null) fis.close();
            } catch (IOException e) {}
        }

    }

    public final void initUI()
    {
        Save = new JButton("Zmien dane");
        Delete = new JButton("Zresetuj");
        Print = new JButton("Wypisz");
        Status = new JLabel("Status");


        Save.setBounds(0, 10, 200, 30);
        Delete.setBounds(0, 50, 200, 30);
        Print.setBounds(0, 90, 200, 30);
        Status.setBounds(0, 130, 500, 150);

        this.setLayout(null);

        getContentPane().add(Save);
        getContentPane().add(Delete);
        getContentPane().add(Print);
        getContentPane().add(Status);

        Save.addActionListener(this);
        Delete.addActionListener(this);
        Print.addActionListener(this);

        NameText = new JTextField(car.getName(), 50);
        ColorText = new JTextField(car.getColor(), 50);
        YearText = new JTextField(car.getYear() + "", 50);


        YearText.setBounds(200, 90, 200, 30);
        ColorText.setBounds(200, 50, 200, 30);
        NameText.setBounds(200, 10, 200, 30);

        getContentPane().add(YearText);
        getContentPane().add(NameText);
        getContentPane().add(ColorText);


        setSize(500, 250);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }


    public void actionPerformed(ActionEvent e)
    {
        Object source = e.getSource();

        if( source == Save )
        {

            if( ColorText.getText().isEmpty()){
                Status.setText(" Kolor jest pusty ");
                return;
            }

            if( NameText.getText().isEmpty()){
                Status.setText(" Marka jest pusta ");
                return;
            }


            if( YearText.getText().isEmpty()){
                Status.setText(" Rok jest pusty ");
                return;
            }

            car.setColor(ColorText.getText());
            car.setYear(Integer.parseInt(YearText.getText()));
            car.setName(NameText.getText());

            Status.setText("Obiekt zaktualizowany");

            WriteToFile();
        }

        if( source == Delete )
        {
            Status.setText("Obiekt wyzerowany");

            car.setColor("");
            car.setYear(0);
            car.setName("");

            ColorText.setText("");
            YearText.setText("");
            NameText.setText("");
        }

        if( source == Print )
        {

            Status.setText("Obiekt: " + car);
        }
    }

}
