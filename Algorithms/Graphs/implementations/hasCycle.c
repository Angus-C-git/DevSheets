
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Stack.h"


static bool DFS(Graph g, Vertex v, int visited[], Vertex p) {
	visited[v] = 1;

	for (Vertex w = 0; w < GraphNumVertices(g); w++) {
		if (GraphIsAdjacent(g, v, w) && w != p ) {
			// If a node has already been visited 
			// it contains a back edge which means
			// it contains a cycle.
			if (visited[w] || DFS(g, w, visited, v)) 
				return true;
		}
	}

	return false;
}


bool hasCycle(Graph g) {
	// Setup DFS 

	/// if u is already in the beingVisited state, 
	// it clearly means there exists a backward edge and so 
	//a cycle has been detected
	int nV = GraphNumVertices(g);
	int *visited = calloc(nV, sizeof(int));

	for (Vertex v = 0; v < nV; v++) {
		if (visited[v]) continue;

		if (DFS(g, v, visited, -1)) {
			free(visited);
			return true;
		}
	}

	free(visited);

	return false;
}

