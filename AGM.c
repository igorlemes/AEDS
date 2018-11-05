#include "AGM.h"

typedef struct lista{
    int Aresta;
    LISTA *proximo;
} LISTA;

typedef struct grafo {
    int tamanho;
    LISTA Vertices[];
} GRAFO;

GRAFO ArvoreGeradoraMinima(GRAFO G){
    GRAFO *A = malloc(sizeof(GRAFO) + G.tamanho);
    A.
}

/* Recebe um valor inteiro e cria um Grafo do tamanho deste inteiro.
Retorna o endereço do Grafo criado */
GRAFO* CriaGrafo(int tamanho){
    GRAFO *A = malloc(sizeof(GRAFO) + sizeof(int)*tamanho);
    for(size_t i = 0; i < tamanho; i++){
        (*A).Vertices[i].proximo = NULL;
    }
    return &A;
}
void IncluirVertice(){

}
void ArestaMenorPeso(){

}
