# Insertion Sort

## Overview



## Characteristics

+ Worst Case Time Complexity => O(n^2)
+ Is adaptive

## Pseudocode Implementation

```

i ← 1
while i < length(A)
    j ← i
    while j > 0 and A[j-1] > A[j]
        swap A[j] and A[j-1]
        j ← j - 1
    end while
    i ← i + 1
end while


```

## C Implementation