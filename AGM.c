#include <stdio.h>
#include <stdlib.h>


typedef struct node *link;
struct graph {
    int numberOfVertex;
    int numberOfEdges;
    link *adjacent;
};
typedef struct graph *Graph;

struct node{
	int vertex;
	int wheight;
	link next;
};

// Graph ArvoreGeradoraMinima(grafo G){
   // grafo *A = malloc(sizeof(grafo) + G.tamanho);
   // A.
// }

/* Recebe um valor inteiro e cria um Grafo do tamanho deste inteiro.
Retorna um ponteiro do Grafo criado */
Graph graphInit(int size){
    Graph A = malloc(sizeof(struct graph));
    A->numberOfVertex = size;
    A->numberOfEdges = 0;
    A->adjacent = malloc(size*sizeof(link));
    for(int i = 0; i < size; i++){
        A->adjacent[i] = NULL;
    }
    return A;
}
link newNode(int vertexV, int wheightW, link next){
	link node = malloc(sizeof(struct node));
	node->vertex = vertexW;
	node->wheight = wheightW;
	node->next = next;
	return node;
}
void insertEdge(Graph A, int vertexV, int vertexW){
	for (int i = 0; i < count; ++i){
		
	}
}

// void insertFirst(Graph A, int vertex, ){
// 	lista *aux = listaVazia(0);
// 	for (int i = 0; i < A->tamanhoGrafo; ++i){
// 		if(A->vertices[i] == vertice){
// 			aux = A->vertices[i];
// 			A->vertices[i] = B;
// 			B->proximo = aux;
// 			break;
// 		}
// 	}
// }

void arestaMenorPeso(grafo *A, int vertice){
	for (int i = 0; i < A->tamanhoGrafo; ++i){
		if(A->vertices[i]->vertice == vertice){ //Change
			lista *aux = listaVazia();
			while()
		}
	}
}

void imprimeAresta(){}

int removeMeio(){}

void organizarLista(){}