#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int Aresta;
    int Vertice;
    struct lista *proximo;
} lista;

typedef struct {
    int tamanhoGrafo;
    lista **Vertices;
} grafo;


grafo ArvoreGeradoraMinima(grafo G);