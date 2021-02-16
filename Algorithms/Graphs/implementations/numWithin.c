
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"

int numWithin(Graph g, int src, int dist) {
	
	int nV = GraphNumVertices(g);
	int *visited = calloc(nV, sizeof(int));
	int runningDist = 0;
	int numWithin = 1;

	visited[src] = 1;

	Queue q = QueueNew();
	QueueEnqueue(q, src);

	// Explore while threshold not reached
	// store a count of explored nodes
	while (!QueueIsEmpty(q) && runningDist < dist) {
		int levelDistance = QueueSize(q);

		while (levelDistance > 0) {
			Vertex v = QueueDequeue(q);

			// store a pred array here?
			for (Vertex w = 0; w < nV; w++) {
				if (GraphIsAdjacent(g, v, w) && !visited[w]) {
					QueueEnqueue(q, w);
					numWithin++;
					visited[w] = 1;
				}
			}

			levelDistance--;
		}

		runningDist++;
	}

	free(visited);
	QueueFree(q);

	return numWithin;
}

