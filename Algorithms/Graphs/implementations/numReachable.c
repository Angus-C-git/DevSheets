
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

/**
* Recursively explore adjacent nodes.
*/
static int searchReachable(Graph g, int visted[], Vertex v) {
	visted[v] = 1;
	int numReached = 1;

	for (Vertex w = 0; w < GraphNumVertices(g); w++) {
		if (GraphIsAdjacent(g, v, w) && visted[w] == 0) {
			visted[w] = w; 
			numReached += searchReachable(g, visted, w);
		}
	}

	return numReached;
}

int numReachable(Graph g, int src) {
	
	int nV = GraphNumVertices(g);
	// count the src node
	int numReached = 1;

	// no nodes reachable in 
	// a single node or empty graph
	if (nV <= 1)  return numReached;

	int *visted = calloc(nV, sizeof(int));
	visted[src] = src;
	numReached = searchReachable(g, visted, src);
	
	free(visted);
	return numReached;
}



