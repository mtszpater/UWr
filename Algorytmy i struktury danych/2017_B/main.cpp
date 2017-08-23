//  straszny syf, ale działa. nie warto zostawiać takich zadań na ostatni dzień xd

#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <stack>
#include <queue>

using namespace std;
int** ary;
int** ulozenia;
int** nastepne;
int** set;
int* set_liczba;

char **input;
int* maska;

bool ustawMaske( int ary1, int input_id ){

    if(ary[ary1][0] == 1 && input[input_id][0] == 'x')
        return false;

    if(ary[ary1][1] == 1 && input[input_id][1] == 'x')
        return false;

    if(ary[ary1][2] == 1 && input[input_id][2] == 'x')
        return false;

    if(ary[ary1][3] == 1 && input[input_id+1][0] == 'x')
        return false;

    if(ary[ary1][4] == 1 && input[input_id+1][1] == 'x')
        return false;

    if(ary[ary1][5] == 1 && input[input_id+1][2] == 'x')
        return false;

    return true;


}

bool wykluczaSie( int ary1, int ary2)
{
    if(ary[ary1][0] == 1 && ary[ary2][1] == 1)
        return true;

    if(ary[ary1][1] == 1 && ( ary[ary2][0] == 1 || ary[ary2][2] == 1 ))
        return true;

    if(ary[ary1][2] == 1 && ary[ary2][1] == 1)
        return true;

    if(ary[ary1][3] == 1 && (ary[ary2][2] == 1 || ary[ary2][4] == 1))
        return true;

    if(ary[ary1][4] == 1 && (ary[ary2][3] == 1 || ary[ary2][5] == 1))
        return true;

    if(ary[ary1][5] == 1 && (ary[ary2][0] == 1 || ary[ary2][4] == 1))
        return true;


    return false;

}

int main() {


    ary = new int *[36];
    maska = new int[36];
    ulozenia = new int *[2];
    set_liczba = new int[36];
    set = new int *[36];
    for (int i = 0; i < 2; ++i) { ulozenia[i] = new int[36]; }

    for (int i = 0; i < 36; ++i) {
        ary[i] = new int[6];
        set[i] = new int[36];
        ulozenia[0][i] = 0;
        ulozenia[1][i] = 0;

    }

    maska[0] = 0;
    maska[1] = 1;
    maska[2] = 1;
    maska[3] = 2;
    maska[4] = 1;
    maska[5] = 2;
    maska[6] = 2;
    maska[7] = 3;
    maska[8] = 1;
    maska[9] = 2;
    maska[10] = 2;
    maska[11] = 3;
    maska[12] = 1;
    maska[13] = 2;
    maska[14] = 2;
    maska[15] = 3;
    maska[16] = 2;
    maska[17] = 3;
    maska[18] = 3;
    maska[19] = 4;
    maska[20] = 2;
    maska[21] = 3;
    maska[22] = 3;
    maska[23] = 4;
    maska[24] = 1;
    maska[25] = 2;
    maska[26] = 2;
    maska[27] = 3;
    maska[28] = 2;
    maska[29] = 3;
    maska[30] = 2;
    maska[31] = 3;
    maska[32] = 3;
    maska[33] = 4;
    maska[34] = 3;
    maska[35] = 4;
    ary[0][0] = 0;
    ary[0][1] = 0;
    ary[0][2] = 0;
    ary[0][3] = 0;
    ary[0][4] = 0;
    ary[0][5] = 0;
    ary[1][0] = 0;
    ary[1][1] = 0;
    ary[1][2] = 0;
    ary[1][3] = 0;
    ary[1][4] = 0;
    ary[1][5] = 1;
    ary[2][0] = 0;
    ary[2][1] = 0;
    ary[2][2] = 0;
    ary[2][3] = 0;
    ary[2][4] = 1;
    ary[2][5] = 0;
    ary[3][0] = 0;
    ary[3][1] = 0;
    ary[3][2] = 0;
    ary[3][3] = 0;
    ary[3][4] = 1;
    ary[3][5] = 1;
    ary[4][0] = 0;
    ary[4][1] = 0;
    ary[4][2] = 0;
    ary[4][3] = 1;
    ary[4][4] = 0;
    ary[4][5] = 0;
    ary[5][0] = 0;
    ary[5][1] = 0;
    ary[5][2] = 0;
    ary[5][3] = 1;
    ary[5][4] = 0;
    ary[5][5] = 1;
    ary[6][0] = 0;
    ary[6][1] = 0;
    ary[6][2] = 0;
    ary[6][3] = 1;
    ary[6][4] = 1;
    ary[6][5] = 0;
    ary[7][0] = 0;
    ary[7][1] = 0;
    ary[7][2] = 0;
    ary[7][3] = 1;
    ary[7][4] = 1;
    ary[7][5] = 1;
    ary[8][0] = 0;
    ary[8][1] = 0;
    ary[8][2] = 1;
    ary[8][3] = 0;
    ary[8][4] = 0;
    ary[8][5] = 0;
    ary[9][0] = 0;
    ary[9][1] = 0;
    ary[9][2] = 1;
    ary[9][3] = 0;
    ary[9][4] = 0;
    ary[9][5] = 1;
    ary[10][0] = 0;
    ary[10][1] = 0;
    ary[10][2] = 1;
    ary[10][3] = 0;
    ary[10][4] = 1;
    ary[10][5] = 0;
    ary[11][0] = 0;
    ary[11][1] = 0;
    ary[11][2] = 1;
    ary[11][3] = 0;
    ary[11][4] = 1;
    ary[11][5] = 1;
    ary[12][0] = 0;
    ary[12][1] = 1;
    ary[12][2] = 0;
    ary[12][3] = 0;
    ary[12][4] = 0;
    ary[12][5] = 0;
    ary[13][0] = 0;
    ary[13][1] = 1;
    ary[13][2] = 0;
    ary[13][3] = 0;
    ary[13][4] = 0;
    ary[13][5] = 1;
    ary[14][0] = 0;
    ary[14][1] = 1;
    ary[14][2] = 0;
    ary[14][3] = 0;
    ary[14][4] = 1;
    ary[14][5] = 0;
    ary[15][0] = 0;
    ary[15][1] = 1;
    ary[15][2] = 0;
    ary[15][3] = 0;
    ary[15][4] = 1;
    ary[15][5] = 1;
    ary[16][0] = 0;
    ary[16][1] = 1;
    ary[16][2] = 0;
    ary[16][3] = 1;
    ary[16][4] = 0;
    ary[16][5] = 0;
    ary[17][0] = 0;
    ary[17][1] = 1;
    ary[17][2] = 0;
    ary[17][3] = 1;
    ary[17][4] = 0;
    ary[17][5] = 1;
    ary[18][0] = 0;
    ary[18][1] = 1;
    ary[18][2] = 0;
    ary[18][3] = 1;
    ary[18][4] = 1;
    ary[18][5] = 0;
    ary[19][0] = 0;
    ary[19][1] = 1;
    ary[19][2] = 0;
    ary[19][3] = 1;
    ary[19][4] = 1;
    ary[19][5] = 1;
    ary[20][0] = 0;
    ary[20][1] = 1;
    ary[20][2] = 1;
    ary[20][3] = 0;
    ary[20][4] = 0;
    ary[20][5] = 0;
    ary[21][0] = 0;
    ary[21][1] = 1;
    ary[21][2] = 1;
    ary[21][3] = 0;
    ary[21][4] = 0;
    ary[21][5] = 1;
    ary[22][0] = 0;
    ary[22][1] = 1;
    ary[22][2] = 1;
    ary[22][3] = 0;
    ary[22][4] = 1;
    ary[22][5] = 0;
    ary[23][0] = 0;
    ary[23][1] = 1;
    ary[23][2] = 1;
    ary[23][3] = 0;
    ary[23][4] = 1;
    ary[23][5] = 1;
    ary[24][0] = 1;
    ary[24][1] = 0;
    ary[24][2] = 0;
    ary[24][3] = 0;
    ary[24][4] = 0;
    ary[24][5] = 0;
    ary[25][0] = 1;
    ary[25][1] = 0;
    ary[25][2] = 0;
    ary[25][3] = 0;
    ary[25][4] = 1;
    ary[25][5] = 0;
    ary[26][0] = 1;
    ary[26][1] = 0;
    ary[26][2] = 0;
    ary[26][3] = 1;
    ary[26][4] = 0;
    ary[26][5] = 0;
    ary[27][0] = 1;
    ary[27][1] = 0;
    ary[27][2] = 0;
    ary[27][3] = 1;
    ary[27][4] = 1;
    ary[27][5] = 0;
    ary[28][0] = 1;
    ary[28][1] = 0;
    ary[28][2] = 1;
    ary[28][3] = 0;
    ary[28][4] = 0;
    ary[28][5] = 0;
    ary[29][0] = 1;
    ary[29][1] = 0;
    ary[29][2] = 1;
    ary[29][3] = 0;
    ary[29][4] = 1;
    ary[29][5] = 0;
    ary[30][0] = 1;
    ary[30][1] = 1;
    ary[30][2] = 0;
    ary[30][3] = 0;
    ary[30][4] = 0;
    ary[30][5] = 0;
    ary[31][0] = 1;
    ary[31][1] = 1;
    ary[31][2] = 0;
    ary[31][3] = 0;
    ary[31][4] = 1;
    ary[31][5] = 0;
    ary[32][0] = 1;
    ary[32][1] = 1;
    ary[32][2] = 0;
    ary[32][3] = 1;
    ary[32][4] = 0;
    ary[32][5] = 0;
    ary[33][0] = 1;
    ary[33][1] = 1;
    ary[33][2] = 0;
    ary[33][3] = 1;
    ary[33][4] = 1;
    ary[33][5] = 0;
    ary[34][0] = 1;
    ary[34][1] = 1;
    ary[34][2] = 1;
    ary[34][3] = 0;
    ary[34][4] = 0;
    ary[34][5] = 0;
    ary[35][0] = 1;
    ary[35][1] = 1;
    ary[35][2] = 1;
    ary[35][3] = 0;
    ary[35][4] = 1;
    ary[35][5] = 0;
    bool nieparzyste = false;
    int m;

    scanf("%d", &m);

    if(m%2 != 0 ) { nieparzyste = true; }

    nastepne = new int *[m / 2 + 1];
    for (int i = 0; i < m / 2 + 1; ++i) { nastepne[i] = new int[36]; }


    input = new char *[m+1];
    for (int i = 0; i < m+1; ++i) { input[i] = new char[5]; }


    int c;

    while ((c = getchar()) != EOF && c != '\n');

    for (int i = 0; i < m; ++i) {
        fgets(input[i], 5, stdin);
    }

    if (m == 1) {
        int licznik = 0;
        if (input[0][0] != 'x') {
            input[0][0] = 'S';
            ++licznik;
        }
        if (input[0][1] != 'x') {
            input[0][1] = 'S';
            ++licznik;
        }
        if (input[0][2] != 'x') {
            input[0][2] = 'S';
            ++licznik;
        }
        printf("%d\n", licznik);
        printf("%c%c%c", input[0][0], input[0][1], input[0][2]);

        return 0;
    }

    if(nieparzyste) {
        m += 1;
        input[m-1][0] = 'x';
        input[m-1][1] = 'x';
        input[m-1][2] = 'x';
    }

    /* PIERWSZY WIERSZ */
    for (int i = 0; i < 36; ++i) {
        if (ustawMaske(i, 0)) {
            ulozenia[0][i] = maska[i];
            nastepne[0][i] = i;
        } else
            nastepne[0][i] = 0;

    }

    for (int i = 0; i < 36; ++i) {
        int k = 0;
        for (int j = 0; j < 36; ++j) {
            if (!wykluczaSie(j, i)) {
                set[i][k] = j;
                ++k;
            }
        }
        set_liczba[i] = k;
    }

    for (int k = 0; k < (m / 2) - 1; ++k) {

        for (int i = 0; i < 36; ++i) {

            int max = -1;
            int max_j = -1;


            if (ustawMaske(i, (2 * k) + 2)) {

                for (int j = 0; j <= set_liczba[i]; ++j) {
                    if (max <= ulozenia[0][set[i][j]]) {
                        max = ulozenia[0][set[i][j]];
                        max_j = set[i][j];
                    }
                }


            }


            if (max_j != -1) {
                ulozenia[1][i] = ulozenia[0][max_j] + maska[i];
                nastepne[k + 1][i] = max_j;

            } else
                ulozenia[1][i] = ulozenia[0][i];


        }
        for (int i = 0; i < 36; ++i) {
            ulozenia[0][i] = ulozenia[1][i];
            ulozenia[1][i] = 0;
        }


    }

    int max = 0;
    int max_j = 0;
    for (int i = 0; i < 36; ++i) {
        if (max < ulozenia[0][i] && ulozenia[0][i] != 0) {
            max = ulozenia[0][i];
            max_j = i;
        }
    }
    printf("%d\n", max);

    std::deque < int > dane;
    dane.push_front(max_j);


    for( int i = m/2 -1; i > 0; --i) {
        max_j = nastepne[i][max_j];
        dane.push_front(max_j);
    }


    for( size_t i = 0; i < dane.size(); i++ )
    {
        if(ary[dane[i]][0] == 1) {
            input[2 * i][0] = 'S';

        }
        if(ary[dane[i]][1] == 1) {
            input[2 * i][1] = 'S';
        }
        if(ary[dane[i]][2] == 1) {
            input[2 * i][2] = 'S';
        }
        printf("%c%c%c\n", input[2*i][0], input[2*i][1], input[2*i][2]);

        if(ary[dane[i]][3] == 1) {
            input[2 * i + 1][0] = 'S';

        }
        if(ary[dane[i]][4] == 1) {
            input[2 * i + 1][1] = 'S';
        }
        if(ary[dane[i]][5] == 1) {
            input[2 * i + 1][2] = 'S';
        }

        if( nieparzyste && 2*i+2 == m ) {
            return 0;
        }
        else{
            printf("%c%c%c\n", input[2 * i + 1][0], input[2 * i + 1][1], input[2 * i + 1][2]);
        }

    }
    return 0;


}