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
void vectorInit(int *binaryVector, int size){
	for (int i = 0; i < size; ++i)
		binaryVector[i] = 0;
}
Graph minimumSpanningTree(Graph G){
	Graph A = graphInit(G->numberOfVertex);
	
	int added = 0;
	int binaryVector[G->numberOfVertex];
	vectorInit(binaryVector, G->numberOfVertex);

	while(added != G->numberOfVertex){

	}   
}

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
link newNode(int vertexW, int wheightW, link next){
	link node = malloc(sizeof(struct node));
	node->vertex = vertexW;
	node->wheight = wheightW;
	node->next = next;
	return node;
}

void insertEdge(Graph A, int vertexV, int vertexW, int wheightW){
	if(isEdge(vertexV, vertexW)) return;
	A->adjacent[vertexV] = newNode(vertexW, wheightW, A->adjacent[vertexV]);
	A->adjacent[vertexW] = newNode(vertexV, wheightW, A->adjacent[vertexW]);
	A->numberOfEdges++;
}

int isEdge(int vertexV, vertexW){
	for (link a  = A->adjacent[vertexV]; a != NULL; a = a->next)
		if(a->vertex == vertexW) return 1;
	return 0;
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

int hasEdge(){

}

void imprimeAresta(){}

Graph graphIn(char *fileAddress){
	FILE *fp;
	fp = fopen(fileAddress, "r");
	if(fp == NULL)
		perror("The file does not have been passed\n");
		return -1;
	
	char str[9];
	

	fgets(line, )
	while(fgets(line, ))
	
} 