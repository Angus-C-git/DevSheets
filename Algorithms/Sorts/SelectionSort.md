# Selection Sort

## Overview



## Characteristics

+ Worst Case Time Complexity => O(n^2)
+ Can be made stable (gneral implementation is not)
+ Not adaptive

## Pseudocode Implementation

```
// SelectionSort sorts the elements of a in ascending order.
func SelectionSort(a []int) {
    for j := 0; j < len(a)-1; j++ {
        // Invariant: a[:j] contains the first j elements
        // of the final sorted slice.
        minPos := j
        for i := j + 1; i < len(a); i++ {
            if a[i] < a[minPos] {
                minPos = i
            }
        }
        a[j], a[minPos] = a[minPos], a[j]
    }
}
```

## C Implementation

```
/* a[0] to a[aLength-1] is the array to sort */

int i,j;

int aLength; // initialise to a's length


/* advance the position through the entire array */

/*   (could do i < aLength-1 because single element is also min element) */

for (i = 0; i < aLength-1; i++)

{

    /* find the min element in the unsorted a[i .. aLength-1] */


    /* assume the min is the first element */

    int jMin = i;

    /* test against elements after i to find the smallest */

    for (j = i+1; j < aLength; j++)

    {

        /* if this element is less, then it is the new minimum */

        if (a[j] < a[jMin])

        {

            /* found new minimum; remember its index */

            jMin = j;

        }

    }


    if (jMin != i) 

    {

        swap(a[i], a[jMin]);

    }

}

```