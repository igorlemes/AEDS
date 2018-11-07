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