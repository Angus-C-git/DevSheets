# Selection Sort

## Overview



## Characteristics

+ Worst Case Time Complexity => O(n^2)
+ Is adaptive

## Pseudocode Implementation

```
// todo
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