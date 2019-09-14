#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Pessoa{
    char nome[100];
    int idade;
    float peso;
}Pessoa;

typedef struct Conjunto{
    Pessoa *v[100];
    int top;

}Conjunto;

Pessoa* newPessoa(char * nome, int idade, float peso){
    Pessoa *p;
    p = (Pessoa*)malloc(sizeof(Pessoa));
    p->idade = idade;
    p->peso = peso;
    strcpy(p->nome, nome);

    return p;
}
Conjunto * newConjunto(){
    Conjunto *c;
    c = (Conjunto*)malloc(sizeof(Conjunto));
    c->top = 0;
    return c;
}
void imprimePessoa (Pessoa *pessoa){
    printf("Nome: %s - Idade: %d - Peso: %.2f\n", pessoa->nome, pessoa->idade, pessoa->peso);
}
void imprimeConjunto (Conjunto *conjunto){
    for(int i=0; i<conjunto->top; i++){
        imprimePessoa(conjunto->v[i]);
    }

}
int cmp(const void *x, const void *y) {
    Pessoa* xa = *(Pessoa**)x;
    Pessoa* ya = *(Pessoa**)y;

    return strcmp(xa->nome , ya->nome);
}
void addPessoa(Conjunto *x, Pessoa *p){
    x->v[x->top++] = p;
    qsort(x,x->top, sizeof(Pessoa*), cmp);
}
void persiste(Conjunto *x, char *fname){
    FILE *file;
    file = fopen(fname, "w");
    fprintf(file, "%d\n" ,x->top);
    for(int i=0; i<x->top; i++){
        fprintf(file, "Nome: %s - Idade: %d - Peso: %.2f\n", x->v[i]->nome, x->v[i]->idade, x->v[i]->peso);
    }
    fclose(file);
}
Conjunto *carrega(char *fname){
    FILE *file;
    int t;
    char nome[100];
    int idade;
    float peso;


    file = fopen(fname, "r");

    if(file == NULL){
        printf("ERRO");
        exit(0);
    }

    Conjunto *x =  newConjunto();



    fscanf(file, "%d\n", &t);
    for(int i=0; i<t; i++){
        fscanf(file, "Nome: %s - Idade: %d - Peso: %f\n", nome, &idade, &peso);
        addPessoa(x, newPessoa(nome, idade, peso));
    }

    fclose(file);
    return x;
}
int main()
{
    Pessoa *tiago = newPessoa("Tiago", 18, 63.3);
    Pessoa *gilberto = newPessoa("Gilberto", 27, 75);
    Pessoa *andreoli = newPessoa("Andreoli" , 28 , 75);
    Conjunto *amigos = newConjunto();
    addPessoa(amigos, tiago);
    addPessoa(amigos, gilberto);
    addPessoa(amigos, andreoli);
    imprimeConjunto(amigos);
    persiste(amigos, "amigospersistentes.txt");
    Conjunto *amigospers = carrega("amigospersistentes.txt");
    imprimeConjunto(amigospers);




    return 0;
}
