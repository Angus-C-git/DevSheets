
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Graph.h"
#include "Queue.h"

/***
* TODO: Doesn't work we need to store
* 		preds.
*/

int furthestReachable(Graph g, int src) {
	
	int nV = GraphNumVertices(g);
	int *visted = calloc(nV, sizeof(int));
	int furthestNode = -1;

	Queue q = QueueNew();
	QueueEnqueue(q, src);

	// int currRing[nV];
	// int dex;

	int changed = 0;
	int tmp;
	while (!QueueIsEmpty(q)) {
		// peak ahead somehow
		if (changed) {
			tmp = furthestNode;
			furthestNode = 0;
			changed = 0;
		}


		Vertex v = QueueDequeue(q);
		if (visted[v]) continue;

		visted[v] = 1;

		for (Vertex w = 0; w < nV; w++) {
			//printf("Died here: %d\n", w);
			if (GraphIsAdjacent(g, v, w) && !visted[w]) {
				QueueEnqueue(q, w);
				changed = 1;
				printf("Looking at: %d\n", w);
				furthestNode = (w > furthestNode) ? w : furthestNode;
				
				printf("fN ~> %d\n", furthestNode);
			}
		}
		//printf("Current Furthest ~> %d\n", currRing[0]);
	}

	QueueFree(q);
	free(visted);

	if (!changed && furthestNode != -1) {
		furthestNode = tmp;
	}



	//free(currRing);
	// if src is not connected
	// to any nodes
	if (furthestNode == -1) 
		return src;

	return furthestNode;
}

