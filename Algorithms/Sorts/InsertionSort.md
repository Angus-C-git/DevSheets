# Insertion Sort

## Overview



## Characteristics

+ Worst Case Time Complexity => O(n^2)
+ Simple sort
+ Adaptive sort
+ Stable sort

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

```
#include <math.h> 
#include <stdio.h> 

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n) { 
	int i, key, j; 
	for (i = 1; i < n; i++) { 
		key = arr[i]; 
		j = i - 1; 

		/* Move elements of arr[0..i-1], that are 
		greater than key, to one position ahead 
		of their current position */
		while (j >= 0 && arr[j] > key) { 
			arr[j + 1] = arr[j]; 
			j = j - 1; 
		} 
		arr[j + 1] = key; 
	} 
} 

```