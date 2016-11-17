package narzedzia;


class node
{
    Zmienna data;
    node prev,next;
    public node(Zmienna x)
    {
        data=x;
        next=null;
    }
}
public class SLL
{
    node start=null;
    public void insertFirst(Zmienna x)
    {
        if (isEmpty())
        {
            node p=new node(x);
            start=p;
        }
        else
        {
            node p=new node(x);
            p.next=start;
            start=p;
        }
    }
    public void insertLast(Zmienna x)
    {
        if (isEmpty())
        {
            node p=new node(x);
            start=p;
        }
        else
        {
            node p=new node(x);
            node current=start;
            while(current.next!=null)
                current=current.next;
            current.next=p;
            p.next=null;
        }
    }
    public void insertAt(Zmienna x,int pos)
    {
        if (isEmpty())
        {
            node p=new node(x);
            start=p;
        }
        else
        {
            int i=1;
            node current=start;
            if (pos>0)
            {
                while (current!=null)
                {
                    if (i==pos-1)
                    {
                        node p=new node(x);
                        p.next=current.next;
                        current.next=p;
                        return ;
                    }
                    else
                    {
                        current=current.next;
                        i++;
                    }
                }
            }
            else
                System.out.println("Wrong position!");
        }
    }
    public boolean isEmpty()
    {
        if(start==null)
            return true;
        else
            return false;
    }
    public Zmienna removeFirst()
    {
        if (isEmpty())
        {
            System.out.println("The list is empty");
            return null;
        }
        else
        {
            Zmienna x=start.data;
            start=start.next;
            return x;
        }
    }
    public Zmienna removeLast()
    {
        if (isEmpty())
        {
            System.out.println("The list is empty");
            return null;
        }
        else
        {
            node current=start;
            while (current.next.next!=null)
                current=current.next;
            Zmienna x=current.next.data;
            current.next=null;
            return x;
        }
    }
    public Zmienna removeAt(int pos)
    {
        if (isEmpty())
        {
            return null;
        }
        else
        {
            if(pos == 1) {
                Zmienna d = start.data;
                removeFirst();
                return d;
            }


            int i=0;
            node current=start;
            if (pos>0)
            {
                while(current!=null)
                {
                    if(i==pos-2)
                    {
                        Zmienna d = current.next.data;
                        current.next=current.next.next;
                        return d;
                    }
                    else
                    {
                        current=current.next;
                        i++;
                    }
                }
            }
            else
            {
                return null;
            }
        }
        return null;
    }
    public int search(String x)
    {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            node current=start;
            int c=1;
            while (current!=null)
            {
                if(current.data.identyfikator.equals(x))
                    return c;
                else
                    current=current.next;
                c++;
            }
        }
        return -1;
    }

    public double searchToValue(String x) throws WyjatekONP {

        int pos = search(x);

        if (isEmpty())
        {
            return 0.00;
        }
        else
        {
            int i=0;
            node current=start;
            if (pos>0)
            {
                while(current!=null)
                {
                    if(i==pos-2)
                    {
                        Zmienna d = current.next.data;
                        return d.obliczWartosc();
                    }
                    else
                    {
                        current=current.next;
                        i++;
                    }
                }
            }
            else
            {
                return 0.00;
            }
        }
        return start.data.obliczWartosc();
    }

    public void display()
    {
        if (isEmpty())
        {

        }
        else
        {
            node current=start;
            while (current!=null)
            {
                System.out.print(current.data+" ");
                current=current.next;
            }
        }
    }
}