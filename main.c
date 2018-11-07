#include <stdio.h>
#include <stdlib.h>
#include "AGM.h"

int main(int argc, char **argv){

	/*Recebe os argumentos do terminal*/
	/*Cria um grafo G com as arestas e vertices passadas pelo terminal*/
	Graph G = graphIn(argv[1]);

	/*Cria um grafo A como uma arvore geradora mínima de G*/	
	Graph A = minimumSpanningTree(G);

	/*imprime o Grafo no terminal*/ 
	//Colocar o graphOut(argv[2]);
	// graphOut(A);
}