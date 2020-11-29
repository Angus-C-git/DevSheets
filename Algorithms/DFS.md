# Depth First Search (DFS)

## Overview


## Huristics

## Supporting Data Structures

## Algorithms

### Iteratively
```
void depthFirst(Graph g, Vertex src) {

	int *visited = calloc(g->nV, sizeof(int));
	Stack s = StackNew();
	StackPush(s, src);
	while (!StackIsEmpty(s)) {
		Vertex v = StackPop(s);
		if (visited[v])
			continue;
		
		visited[v] = 1;
		printf("%d\n", v);
		for (Vertex w = g->nV - 1; w >= 0; w--) {
			if (g->edges[v][w] && !visited[w])
				StackPush(q, w);
		}
	}
	
	StackFree(s);
	free(visited);
}

```

### Recursive

```
#define DISCOVERED 1

/**
* 	procedure DFS(G, v) is
*	label v as discovered
*	for all directed edges from v to w that are in G.adjacentEdges(v) do
*   	if vertex w is not labeled as discovered then
*       	recursively call DFS(G, w)
*/

static void dfs(Graph g, Vertex v, int *visited) {

	// label v as discovered
	visited[v] = DISCOVERED;

	// print discovered vertex
	printf("%d ", v);

	// for edges in graph adjacent to v explore
	// if adjacent node has not already been explored
	// explore it and its neighbours.
	for (Vertex w = 0; w < GraphNumVertices(g); w++) {
		if (GraphIsAdjacent(g, v, w) && visited[w] != DISCOVERED)
			dfs(g, w, visited);
	}
}


void depthFirstSearch(Graph g, int src) {
	// <-- recursively exlpore -->

	// mark all nodes as undiscovered (zero them).
	int *visited = calloc(GraphNumVertices(g), sizeof(int));
	dfs(g, src, visited);
	free(visited);
}
```