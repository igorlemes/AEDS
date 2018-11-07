#include <stdio.h>
#include <stdlib.h>

struct graph {
    int numberOfVertex;
    int numberOfEdges;
    link *adjacent;
};
typedef struct graph *Graph;

typedef struct node *link
struct node{
	int vertex;
	int wheight;
	link next;
};

// grafo ArvoreGeradoraMinima(grafo G);
// grafo *CriaGrafo(int tamanho);
// void incluirInicio(grafo *A, lista *B);
