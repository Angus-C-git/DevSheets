
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"

void breadthFirstSearch(Graph g, int src) {
	
	int *visited = calloc(GraphNumVertices(g), sizeof(int));
	Queue q = QueueNew();
	QueueEnqueue(q, src);

	while (!QueueIsEmpty(q)) {
		Vertex v = QueueDequeue(q);

		if (visited[v]) continue;

		visited[v] = 1;
		printf("%d ", v);

		for (Vertex w = 0; w < GraphNumVertices(g); w++) {
			if (GraphIsAdjacent(g, v, w) && !visited[w])
				QueueEnqueue(q, w);
		}
		
	}

	QueueFree(q);
	free(visited);
}

