# Dijkstras 


## Shortest Path Between Two Nodes

### Pseudo Code



### C Implementation

```
int getDistance(int prev[], int src, int dest) {

	int dist, current;
	for (dist = 0, current = dest; current != src; dist++){
		current = prev[current];
	}

	return dist;

}

int shortestDistance(Graph g, int src, int dest) {
	
	if (src == dest) return 0;

	int nV = GraphNumVertices(g);
	Queue q = QueueNew();
	int prev[nV];

	for (Vertex v = 0; v < nV; v++) {
		prev[v] = -1;
	}

	prev[src] = src;
	QueueEnqueue(q, src);

	while (!QueueIsEmpty(q)) {
		Vertex u = QueueDequeue(q);
		
		for (Vertex w = 0; w < nV; w++){
			if (GraphIsAdjacent(g, u, w) && prev[w] == -1){
				prev[w] = u;
				if (w == dest) {
					QueueFree(q);
					return getDistance(prev, src, dest);
				}
				
				QueueEnqueue(q, w);
			}
		}
	}
	QueueFree(q);

	// no path
	return -1;
}

```