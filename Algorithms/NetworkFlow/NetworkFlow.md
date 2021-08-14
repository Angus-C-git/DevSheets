# Network Flow

A flow network `G = (V, E)` is a directed graph in which each edge `e = (u, v) \in E` has a positive integer capacity `c(u, v) > 0`. There are two distinguished vertices a source `s` and a sink `t` no edge leaves the sink and no edge enters the source.


## Terms/Definitions

+ **Flow Network**
    + A directed graph `G(V,E)` with a set of vertices (V) and edges (E)
+ **Capacity**
    + Each weighted edge in the graph `Ce`
+ **Starting Vertex**
    + Vertex with in degree 0, `indegree(0)`
+ **Sink**
    + A vertex with no outward edges, `outdegree(0)`
+ **cut**
    + Partitioning of the vertices into two disjoint subsets
+ **Augmenting path**
    + Is a path of edges in a residual flow graph with unused capacity greater than zero from the source `s` to the sink `t`
    + An augmenting path can only flow through edges which are not fully saturated
+ **Bottleneck**
    + The "smallest" edge on an augmenting path 


## Visualising Flow Networks

+ Think about all the edges as two parallel pipes which can route a liquid in opposing directions only
+ Each pipe can only push at max the capacity for a particular pipe
+ Thus initially the maximum capacity we can push at the start is the sum of all the capacities that leave the starting vertex 


![Flow Network Diagram](https://i.imgur.com/pZrRSum.png)


## Flow

+ Each edge has a flow associated with it
    + It cannot be less than 0 
    + It cannot be greater than the capacity of that edge

## Max Flow

+ The maximal flow is the largest amount with regards to capacity that can be pushed through the network
+ The maximal flow through the whole network can never exceed the total capacity of edges leaving the starting vertex 
+ We can easily tell in some cases if max flow has been achieved by examining the total flow inbound on the sink vertex in comparison with the total flow leaving the starting vertex
    + If they are equal then we can be certain we have max flow in the network 


## Residual Flow Network

+ A residual flow network represents the amount of flow that can be bargained with for each edge in a greedy path
+ That is we can construct the residual graph by following a greedy path through the network flow graph where we take the edge with the greatest capacity starting at the starting vertex
+ We also store that path `P`
+ We then consider each edge we selected for our greedy path as an amount that we can reverse based on its capacity and the amount inbound (feeding) that edge 
+ We can then follow a path through the residual graph to optimise max flow globally 

![Residual Flow](https://i.imgur.com/Gb4dKcD.png)


+ We see that by following residual graph from `s` our starting vertex we can trace the paths that lead to the most optimised flow globally by considering what amount of flow can be redirected at each edge to maximise flow
+ For example from `v` to `u` we see that we can redirect one unit of flow since from `s` to `v` we only have one unit of inbound flow 
+ In turn this means that we have one extra unit of flow at `u` that we to redirect so we optimise by utilising the edge `u-t`
+ We can confirm that this is the optimal flow by observing that the net capacity outbound from the sink vertex `t` in the residual graph is the same as the net capacity inbound on the starting vertex `s`


### Pseudo Code

```
FF():
    let f(e) = 0 : for all e in E
    while s - t is path in Gres
        let P be simple path in Gres
        augment along path P
        update f to be f'
        update Gres
    
```

## Max-Flow Min-Cut Theorem (Ford-Fulkerson Algorithm)

The max-flow min-cut theorem is the relationship between the cut with the smallest capacity in a network flow and the maximum flow in that network. That is the capacity of the minimum cut is going to be the maximum flow possible for the network.

When considering a cut we only take into account edges moving in the forwards direction I.E through the cut downwards.