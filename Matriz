#include <stdio.h>
#include <stdlib.h>

typedef struct Matriz {
    int li,co,**m;
}Matriz;


Matriz *criaMatriz(int li, int co) {
    int i, j;
    int *p;
    int *q;
    Matriz matrix;

    matrix.li = li;
    matrix.co = co;
    matrix.m = p;


    p = malloc(li * co * sizeof(int*));
    q = p;
    for (i=0; i<(li*co); i++, q++)
		*q = 0;

    return(p);

}



int main() {

    Matriz matrix;
    int li, co, i, j,*m;
    criaMatriz(2,2);
    imprimeMatriz(m,li,co);


    return 0;
}




