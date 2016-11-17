package narzedzia;
/**
 * Klasa opisująca Element stos
 */
class Elem {
    Double wartosc;
    Elem next;

    public Elem(Double x, Elem n){
        next=n;
        wartosc=x;
    }

    public Elem getNext(){
        return next;
    }

    public double getWartosc(){
        return wartosc;
    }

}

/**
 * Klasa opisująca stos
 */
public class Stos {

    Elem start;

    Stos() {
        start = null;
    }

    public Elem getStart() {
        return start;
    }

    public void push(Double x) {
        Elem temp = new Elem(x, start);
        start = temp;
    }

    public void pop() throws ONP_PustyStos {
        if (start != null) {
            start = start.getNext();
        } else {
            throw new ONP_PustyStos("Stos jest pusty");
        }

    }

    public double value()
    {
        return start.getWartosc();

    }

    public int zlicz() {
        if (start != null) {
            Elem temp = start;
            int licznik = 0;
            while (temp != null) {
                licznik++;
                temp = temp.getNext();
            }
            return licznik;
        } else return 0;
    }

    public void show(){
        if(start!=null){
            Elem temp = start;
            while(temp!=null){
                System.out.print(temp.getWartosc() + " ");
                temp=temp.getNext();
            }
            System.out.println();
        } else {
            System.out.println("Stos jest pusty");
        }
    }


}