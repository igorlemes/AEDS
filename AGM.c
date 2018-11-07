#include "AGM.h"

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


/*cria um novo node de adjacencia
*/
link newNode(int vertexW, int wheightW, link next){
	link node = malloc(sizeof(struct node));
	node->vertex = vertexW;
	node->wheight = wheightW;
	node->next = next;
	return node;
}

/*Insere uma nova Aresta entre dois vertices, V e W, com o peso W entre eles
	vale ressaltar que a função adiciona de V para W e de W para V
 Ao final, é aumentado em um o numero de arestas no grafo
*/
void insertEdge(Graph A, int vertexV, int vertexW, int wheightW){
	if(isEdge(A, vertexV, vertexW)) return;
	A->adjacent[vertexV] = newNode(vertexW, wheightW, A->adjacent[vertexV]);
	A->adjacent[vertexW] = newNode(vertexV, wheightW, A->adjacent[vertexW]);
	A->numberOfEdges++;
}


/*Verifica se dois vertices possuem arestas ligando-os em um grafo A*/
int isEdge(Graph A, int vertexV, int vertexW){
	for (link a  = A->adjacent[vertexV]; a != NULL; a = a->next)
		if(a->vertex == vertexW) return 1;
	return 0;
}

/**/
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

void printGraph(Graph A){
	printf("%d %d\n", A->numberOfVertex, A->numberOfEdges);
	for (int i = 0; i < A->numberOfVertex; ++i){
		for (link a  = A->adjacent[i]; a != NULL; a = a->next)
			// if(i < a->vertex)
				printf("%d %d %d\n", i, a->vertex, a->wheight);
	}
}

Graph minimumSpanningTree(Graph G){
	return A;
}

