# Kruskals Algorithm

Kruskal's MST algorithm is an algorithm used to find the minimum spanning tree of a graph.

This algorithm effectively constructs the MST by gradually joining together the connected graphs in a forest that starts with each subgraph being a single node. On each iteration, it add a new edge to the forest, and reduces the number of subgraphs by one.

## C Implementation

```
typedef Graph MSTree;

MSTree kruskalFindMST(Graph g)
{
	MSTree mst = GraphNew(); // MST initially empty
	Edge eList[g->nV]; // sorted array of edges
	edges(eList, g->nE, g);
	sortEdgeList(eList, g->nE);
	for (int i = 0; mst->nE < g->nV - 1; i++) {
		Edge e = eList[i];
		GraphAddEdge(mst, e);
		if (GraphHasCycle(mst)) GraphRemoveEdge(mst, e);
	}
	return mst;
}

```