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
	int wheight;
	int vertex;
	int added;
	link next;
};

Graph minimumSpanningTree(Graph G);
Graph graphInit(int size, int initiate);
Graph graphIn(char *fileAddress);
link leastWheight(Graph G, Graph A, int *binaryVector);
link newNode(int vertexW, int wheightW, link next);
void insertEdge(Graph A, int vertexV, int vertexW, int wheightW, int *binaryVector);
void graphOut(Graph A);
void initVector(int *vector, int size);
int isEdge(Graph A, int vertexV, int vertexW);