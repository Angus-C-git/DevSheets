# Tries

## Overview

A trie is a data structure for representing a set of strings. They have the idealistic property of matching queries in O(L) time where L is the length of the sting being searched for.

Each node in a trie:

+ contains one part of a key (typically one character)
+ may have up to 26 children
+ may be tagged as a "finishing" node
+ but even "finishing" nodes may have children
+ may contain other data for application  (e.g. word frequency) 

A "finishing" node marks the end of one key

+ this key may be a prefix of another key stored in trie 

### Depth Of A Trie

+ length of longest key value 


## Searching Tries

```
find(trie,key):
|  Input  trie, key
|  Output pointer to element in trie if key found
|         NULL otherwise
|
|  node=trie
|  for each char c in key do
|  |  if node.child[c] exists then
|  |     node=node.child[c]  // move down one level
|  |  else
|  |     return NULL
|  |  end if
|  end for
|  if node.finish then  // "finishing" node reached?
|     return node
|  else
|     return NULL
|  end if

```