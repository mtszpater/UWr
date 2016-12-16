package com.company;

public class Main {
    
    private static Double Bernstein( int n, int i, double t)
    {
        double rest = Math.pow(t, i) * Math.pow(1-t, n-i);
        
        return Newton(n, i) * rest;
        
    }
    
    public static double Newton( int n, int k )
    {
        double  Wynik = 1;      
        int i;

        for(i = 1; i <= k; i++) 
        {
            Wynik = Wynik * ( n - i + 1 ) / i;     
        }

        return Wynik;  
    }
    

    
    public static void main(String[] args) {
        
        int n = 10;

        Double [] x = new Double[] {
                0.0, 3.5, 25.0, 25.0, -5.0, -5.0, 15.0, -0.5, 19.5, 7.0, 1.5
        };
        Double [] y = new Double [] {
                0.0, 36.0, 25.0, 1.5, 3.0, 33.0, 11.0, 35.0, 15.5, 0.0, 10.5
        };
        
        Integer[] waga = new Integer[] {
                1,6,4,2,3,4,2,1,5,4,1
        };
        
        System.out.println("# X   Y");
        
        
        for( int z = 0; z  <= 100; ++z ) {
            double t = z / 100.00;

            double first_x = 0.0;
            double first_y = 0.0;
            
            double current;
            
            for (int i = 0; i <= n; ++i) {
                current = waga[i] * x[i] * Bernstein(n, i, t);
                first_x += current;
            }
            
            for (int i = 0; i <= n; ++i) {
                current = waga[i]  * y[i] * Bernstein(n, i, t);
                first_y += current;

            }

            double podloga = 0.0;
            for (int i = 0; i <= n; ++i) {
                current = waga[i]  * Bernstein(n, i, t);
                podloga += current;

            }
            
            System.out.println( first_x / podloga + " " + first_y / podloga );
        }
        
    }
}