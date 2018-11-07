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
link smallerWheight(Graph A, int vertice, int *binaryVector);

void vectorInit(int *binaryVector, int size){
	for (int i = 0; i < size; ++i)
		binaryVector[i] = 0;
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

/*Funcão que recebe um ponteiro de Grafo, um vertice e um vetor binario
Atravez de um struct auxiliar, guardamos  o primeiro node
Ela percorre a lista de adjacencia do vertice passado,
Se o vertice adjacente não foi adicionado no Segundo Grafo (verifica no vetor binário)
ele compara os valores com o node auxiliar, ao chegar no final, o auxiliar tem o node com menor peso, que ainda não foi adicionado
*/
link smallerWheight(Graph A, int vertice, int *binaryVector){
	link aux = malloc(sizeof(struct node)); 
	aux = A->adjacent[vertice];s
	for (link a = A->adjacent[vertice]; a != NULL; a = a->next)	{		
		if (!binaryVector[a->vertex])
			if ((a->wheight) < (aux->wheight)){
				printf("w %d\n", a->wheight);				
				aux = a;
	}
	return aux;
}


/*Insere uma nova adjacencia a lista 


*/
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


void printGraph(Graph A){
	printf("%d %d\n", A->numberOfVertex, A->numberOfEdges);
	for (int i = 0; i < A->numberOfVertex; ++i){
		for (link a  = A->adjacent[i]; a != NULL; a = a->next)
			// if(i < a->vertex)
				printf("%d %d %d\n", i, a->vertex, a->wheight);

	}
}

Graph minimumSpanningTree(Graph G){
	Graph A = graphInit(G->numberOfVertex);
		
	int binaryVector[G->numberOfVertex];
	vectorInit(binaryVector, G->numberOfVertex);
	
	binaryVector[0] = 1;
	link aux = smallerWheight(G, 0, binaryVector);
	insertEdge(A, 0, aux->vertex, aux->wheight);

	binaryVector[1] = 1;

	int aux2;
	while(A->numberOfEdges < (A->numberOfVertex-1)){
		for(int i = 0; i < A->numberOfVertex; ++i){
			if(binaryVector[i])
				aux = smallerWheight(G, i, binaryVector);
				aux2 = i;
		}
		insertEdge(A, aux2, aux->vertex, aux->wheight);
		binaryVector[aux2] = 1;
	}

	return A;
}

int main(int argc, char **argv){
	Graph G = graphIn("entrada.txt");
	Graph A = graphInit(G->numberOfVertex);
	// printGraph(G);

	int binaryVector[G->numberOfVertex];
	vectorInit(binaryVector, G->numberOfVertex);
	
	binaryVector[0] = 1;
	link aux1 = malloc(sizeof(struct node)); 
	link aux2 = malloc(sizeof(struct node)); 

	aux1 = smallerWheight(G, 0, binaryVector);
	insertEdge(A, 0, aux1->vertex, aux1->wheight);
	binaryVector[aux1->vertex] = 1;	

	
	// aux1 = smallerWheight(G, 0, binaryVector);
	// aux2 = smallerWheight(G, 1, binaryVector);
	// if(aux1->wheight <= aux2->wheight && !binaryVector[aux1->vertex]){
	// 	insertEdge(A, 0, aux1->vertex, aux1->wheight);
	// 	binaryVector[aux1->vertex] = 1;
	// 	printf("a %d\n", aux1->wheight);
	// } else {
	// 	insertEdge(A, 1, aux2->vertex, aux2->wheight);
	// 	binaryVector[aux2->vertex] = 1;
	// 	printf("b %d\n", aux2->wheight);
	// }

	
	

	// for (int i = 0; i < G->numberOfVertex; ++i)
	// {
	// 	printf("%d\n", binaryVector[i]);	
	// }
		
	// A = minimumSpanningTree(G);
	
	// printf("\n\n");
	printGraph(A);
	// free(G);
	// free(A);
	return 0;
}

