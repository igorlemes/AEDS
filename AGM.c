#include <stdio.h>
#include <stdlib.h>

grafo ArvoreGeradoraMinima(grafo G){
//    grafo *A = malloc(sizeof(grafo) + G.tamanho);
//    A.
}

/* Recebe um valor inteiro e cria um Grafo do tamanho deste inteiro.
Retorna um ponteiro do Grafo criado */
grafo *CriaGrafo(int tamanho){
    grafo *A = malloc(sizeof(grafo));
    A->tamanhoGrafo = tamanho;
    A->vertices = malloc(A->tamanhoGrafo*sizeof(lista*));
    int i;
    for(i = 0; i < tamanho; i++){
        A->vertices[i] = listaVazia();
    }
    return A;
}

void incluirInicio(grafo *A){}

void arestaMenorPeso(){}

void imprimeAresta(){}

int removeMeio(){}

void listaVazia(){}

void organizarLista(){}