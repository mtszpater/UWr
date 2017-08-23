#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <stack>
#include <queue>

#define A 65
#define B 66
#define C 67
#define D 68
#define E 69
#define F 70


char **array;
bool **array_city;
int lines, columns;
int count;


void readData();
void createArrays();
void deleteArrays();

struct punkt
{
    int x;
    int y;
};

std::queue<punkt> kolejka;

bool hasTopEdge(const punkt &v);

bool hasBottomEdge(const punkt &v);

bool isUnvisited(const punkt &v);

bool hasLeftEdge(const punkt &v);

bool hasRightEdge(const punkt &v);

void visit(const punkt &z);

punkt wolnyPunkt;

void BFS(punkt p)
{

    kolejka.push(p);

    while(!kolejka.empty())
    {
        punkt v;
        punkt z;
        v = kolejka.front();
        kolejka.pop();

        array_city[v.x][v.y] = true;


        if (v.x > 0){

            z.x = v.x - 1;
            z.y = v.y;

            if(isUnvisited(z)) {
                if (hasTopEdge(v)) {
                    if (hasBottomEdge(z)) {
                        visit(z);
                        kolejka.push(z);
                    }
                }
            }
        }


        if (v.x+1 < lines){

            z.x = v.x + 1;
            z.y = v.y;


            if(isUnvisited(z)) {
                if(hasBottomEdge(v)) {
                    if (hasTopEdge(z)){
                        visit(z);
                        kolejka.push(z);
                    }
                }
            }
        }


        if (v.y > 0){

            z.x = v.x;
            z.y = v.y - 1;

            if(isUnvisited(z)) {
                if (hasLeftEdge(v)) {
                    if (hasRightEdge(z)) {
                        visit(z);
                        kolejka.push(z);
                    }
                }
            }
        }



        if (v.y+1 < columns) {

            z.x = v.x;
            z.y = v.y + 1;

            if(isUnvisited(z)) {
                if (hasRightEdge(v)) {
                    if(hasLeftEdge(z)) {
                        {

                            visit(z);
                            kolejka.push(z);
                        }
                    }
                }
            }
        }
    }




}

void visit(const punkt &z) { array_city[z.x][z.y] = true; }

bool hasRightEdge(const punkt &v) { return array[v.x][v.y] == D || array[v.x][v.y] == E || array[v.x][v.y] == F; }

bool hasLeftEdge(const punkt &v) { return array[v.x][v.y] == B || array[v.x][v.y] == C || array[v.x][v.y] == F; }

bool isUnvisited(const punkt &v) { return array_city[v.x][v.y] == false; }

bool hasBottomEdge(const punkt &v) { return array[v.x][v.y] == B || array[v.x][v.y] == E || array[v.x][v.y] == F; }

bool hasTopEdge(const punkt &v) { return array[v.x][v.y] == D || array[v.x][v.y] == C || array[v.x][v.y] == F; }

punkt wolny(){
    punkt p;


    for (int j = wolnyPunkt.y; j < columns; ++j) {
        if (array_city[wolnyPunkt.x][j] == false && array[wolnyPunkt.x][j] != A) {
            p.x = wolnyPunkt.x;
            p.y = j;
            return p;
        }
    }


    for(int i = wolnyPunkt.x+1; i < lines; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (array_city[i][j] == false && array[i][j] != A) {
                p.x = i;
                p.y = j;
                return p;
            }
        }
    }


    p.x = -1;
    p.y = -1;
    return p;

}
int main() {

    scanf("%d %d", &lines, &columns);



    createArrays();
    readData();

    wolnyPunkt.y = 0;
    wolnyPunkt.x = 0;

    count = 0;

    while( wolnyPunkt.y != -1) {
        wolnyPunkt = wolny();
        if( wolnyPunkt.y >= 0) {
            BFS(wolnyPunkt);
            ++count;
        }

    }

    printf("%d", count);


    deleteArrays();


    return 0;
}

void readData(){
    int c;

    while ((c = getchar()) != EOF && c != '\n');

    for( int i = 0; i < lines; ++i ){
        fgets(array[i], columns+2, stdin);
    }
}

void createArrays(){

    array = new char*[lines];
    for(int i = 0; i < lines; ++i) {
        array[i] = new char[columns+1];
    }


    array_city = new bool*[lines];
    for(int i = 0; i < lines; ++i) {
        array_city[i] = new bool[columns];
    }

    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < columns; ++j) {
            array_city[i][j] = 0;
        }
    }

}


void deleteArrays(){
    for(int i = 0; i < lines; ++i) {
        delete [] array[i];
        delete [] array_city[i];
    }
    delete [] array;
    delete [] array_city;
}