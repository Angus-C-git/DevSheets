
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"


static bool isClique(Graph g, int b) {
	
	for (Vertex v = 0; v < b; v++) {
		for (Vertex w = 0; w < b; w++) {
			if (!GraphIsAdjacent(g, v, w)) {
				return false;
			}
		}
	}
	return true;
}


bool hasClique(Graph g, Vertex src) {
	int nV = GraphNumVertices(g);
	int *visted = calloc(nV, sizeof(int));
	// For all nodes in g check 
	//if they form a clique

	// Starting node +1, number of vertecies -1
	// explore all from source group
	for (Vertex v = src + 1; v < nV - 1; v++) {
		if (visted[v]) continue;

		if (isClique(g, v + 1)) {
			free(visted);
			return true;
		}

	}
	return false;
}

