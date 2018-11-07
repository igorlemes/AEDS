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


void vectorInit(int *binaryVector, int size);
Graph minimumSpanningTree(Graph G);
Graph graphInit(int size);
link newNode(int vertexW, int wheightW, link next);
void insertEdge(Graph A, int vertexV, int vertexW, int wheightW);
int isEdge(Graph A, int vertexV, int vertexW);
Graph graphIn(char *fileAddress);
void printGraph(Graph A);


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
	if(isEdge(A, vertexV, vertexW)) return;
	A->adjacent[vertexV] = newNode(vertexW, wheightW, A->adjacent[vertexV]);
	A->adjacent[vertexW] = newNode(vertexV, wheightW, A->adjacent[vertexW]);
	A->numberOfEdges++;
}

int isEdge(Graph A, int vertexV, int vertexW){
	for (link a  = A->adjacent[vertexV]; a != NULL; a = a->next)
		if(a->vertex == vertexW) return 1;
	return 0;
}

Graph graphIn(char *fileAddress){
	
	FILE *fp;
	fp = fopen(fileAddress, "r");
	if(fp == NULL)
		perror("The file does not have been passed\n");
	
	int numberOfVertex, numberOfEdges;
	fscanf(fp, "%d %d", &numberOfVertex, &numberOfEdges);

	Graph G = graphInit(numberOfVertex);
	int vertexU, vertexV, wheightW;
	while((fscanf(fp, "%d %d %d", &vertexU, &vertexV, &wheightW)) != EOF){
		insertEdge(G , vertexU, vertexV, wheightW);
	}
	fclose(fp);
	return G;
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

// void arestaMenorPeso(grafo *A, int vertice){
// 	for (int i = 0; i < A->tamanhoGrafo; ++i){
// 		if(A->vertices[i]->vertice == vertice){ //Change
// 			lista *aux = listaVazia();
// 			while()
// 		}
// 	}
// }

// int hasEdge(){

// }

//Melhorar
void printGraph(Graph A){
	for (int i = 0; i < A->numberOfVertex; ++i){
		printf("%d\n", i);
		for (link a  = A->adjacent[i]; a != NULL; a = a->next)
			printf("Aresta u: %d\tAresta v:%d\tPeso%d\n", i, a->vertex, a->wheight);

	}
}

int main(int argc, char **argv){
	Graph G = graphIn("entrada.txt");
	printGraph(G);
	free(G);
	return 0;
}