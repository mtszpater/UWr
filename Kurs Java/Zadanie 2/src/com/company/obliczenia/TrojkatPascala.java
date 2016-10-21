package com.company.obliczenia;

/**
 * author @pater
 */
public class TrojkatPascala {

    private final static int MAX = 67; // 10 to na pewno zbyt mało!
    private static long[][] trojkat = new long[MAX][MAX];

    public static long[][] getTrojkat() {
        return trojkat;
    }

    static {

        for (int L = 0;(L<MAX);L++) {
            for (int C = 0; (C <= L); C++) {
                if ((C == 0) || (L == C))
                    trojkat[L][C] = 1;
                else
                    trojkat[L][C] = trojkat[L - 1][C] + trojkat[L - 1][C - 1];
            }
        }

    }

    public static long czytaj(int n, int k) throws IllegalArgumentException {

        /* Jakies male zabezpieczenia */
        if( n > MAX-1 || n < 0 ) n = 0;
        if( k > n ) k = 0;

        return trojkat[n][k];
    }
}
