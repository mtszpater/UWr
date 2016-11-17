/*
 * Copyright (c) 2016.
 * @author Mateusz Pater
 * @email mtszpater@gmail.com
 *
 */
package narzedzia;
/**
 * Klasa rodzicielska opisująca Funkcję
 * @author pater
 */
public class Funkcja extends Symbol implements Funkcyjny{


    public int n;
    public Double[] array = new Double[arnosc()];


    /**
     *
     * @return int arność funkcji
     */
    @Override
    public int arnosc() {
        return 0;
    }

    /**
     * Zwraca ilość brakujących argumentów
     * @return int brakujące argumenty
     */
    @Override
    public int brakujaceArgumenty() {
        return arnosc()-n;
    }

    /**
     * dodaje argumenty do funkcji
     * @param k argument
     * @throws ONP_BłędneWyrażenie w przypadku zbyt wielu argumentów
     */
    @Override
    public void dodajArgument(double k) throws WyjatekONP {

        if( brakujaceArgumenty() == 0 )
            throw new ONP_BłędneWyrażenie("za dużo argumentów do funkcji");

        switch( arnosc() ){
            case 1:
                array[0] = k;
                ++n;
                break;
            case 2:
                if( brakujaceArgumenty() == arnosc() )
                    array[0] = k;
                else
                    array[1] = k;

                ++n;
                break;
            default:
                break;
        }

    }

    /**
     * Funkcja do obliczania wartości wyrażenia zależnie od zainicjowanych argumentów klasy funkcja
     * @return double wartość
     * @throws WyjatekONP w przypadku braku argumentów
     */
    @Override
    public double obliczWartosc() throws WyjatekONP {
        if( this.brakujaceArgumenty() > 0 ) {
            throw new WyjatekONP("Za mało argumentow");
        }

        return 0;
    }



}
