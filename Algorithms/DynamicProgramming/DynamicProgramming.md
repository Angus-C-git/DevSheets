# Dynamic Programming

The idea of dynamic programming (DP) is to find the optimal solution to a optimization problem by solving a series of carefully selected subproblem which are smaller in size. Such subproblems allow for a recursive definition of their own optimal solutions allowing for the construction of a tree of ever decreasing subproblem size, eventually leading to the solving of a 'base subproblem' which we refer to as the base case.

At its core DP harnesses the power of memoization, solving each subproblem only once and using that result further up in the recursion. 

## Memoisation in DP

Consider a recursive definition of the fibonacci sequence.

```
int fib(int n)
{
    if (n <= 1)
        return n;
    
    return fib(n - 2) + fib(n - 1);
}
```

If we visualise the steps that the recursive function will take as a tree we end up with something like the following:


![DP_recursion_tree](https://i.imgur.com/NJXub2t.png)


If we look at the call stack we see that some calls are being repeated several times. For example:

+ fib(1)
+ fib(0)

This wastes computation by performing the same calculations and lookups over and over again which will grow exponentialy with the size of `n`.

Thus we introduce memoization into the solution. Memoization is esentially the process of storing a *newly* computed result in a table such that the next time that particular result is required a lookup on the table for the value is performed instead of recomputing the result. 

In the fibonacci example we would store a table (array) similar to the following:




| Index    | Value   | 
| -------- | --------|
| 0        |    0    |
| 1        |    1    |
| 2        |    1    |
| 3        |    2    |
| 4        |    3    |
| 5        |    5    |

Which would collapse the number of calls to `6`. Reducing the complexity to `O(n)` linear time.

> *Without memoization we are simply bruteforcing the problem.*


## Components of Dynamic Programming Problems

All DP problems and their associated solutions involve a series of distinct stages which define the way the problem should be solved with the chosen DP strategy. These stages are:

+ Defining the Subproblems
+ Defining the Base Case
+ The Recursive Definition
+ Obtaining the Final Solution

### Defining the Subproblems

In this stage we identify the subproblems we will solve to arrive at the optimal solution. This is probably the most important aspect of solving DP problems since it defines how our recursion will proceed and weather we will arrive at the optimal solution after solving all subproblems. 

Subproblems are selected based on the specific metric which is trying to be achieved. Typically the subproblem definition will resemble a reworded version of the problem definition. They usually involve considering a 'slice' or the problem such as considering up to the `ith` position in a sequence or indices `i` through `j` in an array. 


### Defining the Basecase


The base case defines where our recursive solution will terminate. Since we typically recurse backwards from something this is often the beginning of a list or sequence or 1/0.

In our fibonacci example the base case is when n reaches the starting value in the sequence 1/0 (depending on the definition). Thus it is defined as bellow. 

```C
if (n <= 1)
    return n;
```

### The Recursive Definition

The recursive definition is where we define how the subproblems will be solved to arrive at the 'optimal' or desired solution. Typically this will look like a formula where `min` and/or `max` functions are employed to represent the optimal choice for that particular recursive step or set of recursive steps. A broad example of this is the following recursive definition.

`opt(i) = max{opt(i - 1), opt(j - 1)}`


### Obtaining Solutions

In this stage we explicitly define how the final optimal solution is obtained. In many cases this will simply be the value produced by the recursive definition, I.E `opt(i)`, but it can also involve selecting the optimal from a set of solutions.

## Examples

### Timber Milling

*Suppose we have a large piece of timber that we wish to cut down into smaller planks.*


// TODO :)


