# Breadth First Search

## Overview

## Huristics

## Supporting Data Structures

## Algorithms

### Iterative Queue 

~> [Queue ATD](/Data%20Structures/Queues/Queue.h)

```
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

```