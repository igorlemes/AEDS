#include "AGM.h"

/*Uma função para iniciarlizar vetores com zeros*/
void initVector(int *vector, int size){
	for (int i = 0; i < size; ++i)
		binaryVector[i] = 0;
}
/* Recebe um valor inteiro e cria um Grafo do tamanho deste inteiro.
Retorna um ponteiro do Grafo criado */
Graph graphInit(int size, int initiate){

	/*Aloca memória para o grafo*/
    Graph A = malloc(sizeof(struct graph));
    
    /*Caso seja um grafo recebido do terminal, ele será totalmente inicializado*/
    if(initiate)
    	A->numberOfVertex = size;
    /*Caso contrario, ele não terá vertices nem arestas*/
    else
    	A->numberOfVertex = 0;
    

    /*O Grafo começa com nenhuma aresta, então alocamos memória para as listas de adjacencia*/
    A->numberOfEdges = 0;
    A->adjacent = malloc(size*sizeof(link));
 	
 	/*definimos todas as adjacências dos vertices como nulas*/   
    for(int i = 0; i < size; i++){
        A->adjacent[i] = NULL;
    }
    /*retornamos o grafo*/
    return A;
}


/*cria uma nova lista de adjacencia*/
link newNode(int vertexW, int wheightW, link next){
	/*Aloca memória para a lista*/
	link node = malloc(sizeof(struct node));
	/*Define o vertice com o numero passado como argumento*/
	node->vertex = vertexW;
	/*Define o peso da aresta*/
	node->wheight = wheightW;
	/*Aponta para o proximo item da lista*/
	node->next = next;
	/*Retorna a nova lista de adjacencia*/
	return node;
}

/*Insere uma nova Aresta entre dois vertices, V e W, com o peso W entre eles
	vale ressaltar que a função adiciona de V para W e de W para V
 Ao final, é aumentado em um o numero de arestas no grafo
*/
void insertEdge(Graph A, int vertexV, int vertexW, int wheightW){
	/*Verifica se já não possuem uma aresta, caso possua, simplesmente retorna*/
	if(isEdge(A, vertexV, vertexW)) return;
	/*caso não haja uma aresta, ela é criada, nas duas direções*/
	A->adjacent[vertexV] = newNode(vertexW, wheightW, A->adjacent[vertexV]);
	A->adjacent[vertexW] = newNode(vertexV, wheightW, A->adjacent[vertexW]);
	/*O numero de arestas é atualizado*/
	A->numberOfEdges++;
}


/*Verifica se dois vertices possuem arestas ligando-os em um grafo A*/
int isEdge(Graph A, int vertexV, int vertexW){
	/*Itera sobre a lista de adjacencia de um vertice e verifica se ele possui aresta com o outro vertice*/
	for (link a  = A->adjacent[vertexV]; a != NULL; a = a->next)
		if(a->vertex == vertexW) return 1;
	return 0;
}

/**/
Graph graphIn(char *fileAddress){
	/*Abre o arquivo*/
	FILE *fp;
	fp = fopen(fileAddress, "r");
	if(fp == NULL)
		perror("The file does not have been passed\n");
	
	int numberOfVertex, numberOfEdges;
	fscanf(fp, "%d %d", &numberOfVertex, &numberOfEdges);

	Graph G = graphInit(numberOfVertex, 1);
	int vertexU, vertexV, wheightW;
	while((fscanf(fp, "%d %d %d", &vertexU, &vertexV, &wheightW)) != EOF){
		insertEdge(G , vertexU, vertexV, wheightW);
	}
	fclose(fp);
	return G;
}

void graphOut(Graph A){
	printf("%d %d\n", A->numberOfVertex, A->numberOfEdges);
	for (int i = 0; i < A->numberOfVertex; ++i){
		for (link a  = A->adjacent[i]; a != NULL; a = a->next)
			if(i < a->vertex)
				printf("%d %d %d\n", i, a->vertex, a->wheight);
	}
}

link leastWheight(Graph G, Graph A, int *binaryVector){
	/*Aloca memória de um link auxiliar*/
	link aux = malloc(sizeof(struct node));

	/*Define um peso grande, para que seja facilmente substituido*/
	aux->wheight = 2000000;
	
	/*Itera sobre os vertices do Grafo G*/
	for (int i = 0; i < G->numberOfVertex; ++i){
	
		/*Verifica que o Vertice já está na AGM*/
		if(binaryVector[i]){
	
			/*Itera sobre os adjacentes ao Vertice i*/
			for (link a = A->adjacent[i]; a != NULL; a = a->next){
	
				/*Verifica se o peso do adjacente atual é menor que o segurado pelo auxiliar*/
				if(a->wheight < aux->wheight){
					
					/*Verifica se será criada uma aresta com um vertice até então fora da AGM.*/
					if(!binaryVector[a->vertex]){
						/*Atribui a para o auxiliar*/
						aux = a;
						aux->added = i;
					}
				}
			}
		}
	}
	/*Retorna o auxiliar, com o menor peso e as informações dos vertices que serão ligados*/
	return aux;
}

/*Recebe o Grafo G e cria um grafo A, que é uma Arvore Geradora Mínima de G*/
Graph minimumSpanningTree(Graph G){

	/*Cria Grafo A, com o numero de vértices de G*/
	Graph A = graphInit(G->numberOfVertex, 0);

	/*Cria node e binaryVector que será adicionado à arvore geradora e usado para gerenciamento, respectivamente*/
	link aux = malloc(sizeof(struct node));
	int binaryVector[G->numberOfVertex];
	initVector(binaryVector, G->numberOfVertex);

	/*Inicia o Grafo adicionando o vertice 0*/
	binaryVector[0] = 1;
	A->numberOfVertex++;

	/*Um laço para que a função continue até adicionar todos os Vertices do Grafo G*/
	while(A->numberOfVertex != G->numberOfVertex){
		
		/*Atribuindo o aux como uma representação da aresta mais barata conectando um Vertice dentro da arvore e um vertice fora*/
		aux = leastWheight(G, A, binaryVector);
		
		/*Insere uma aresta na AGM*/
		insertEdge(A, int vertexV, int vertexW, int wheightW)
	}
	
}


