# Custom Standard Template Library (STL) in C

---

## Overview

This project provides a custom implementation of a Standard Template Library (STL) in C. It includes various data structures and utility functions that are essential for efficient programming. The library offers implementations of arrays, vectors, linked lists, stacks, queues, heaps, maps, binary search trees (BST), binary trees, and utility types like pairs, triplets, and quartets.

## Data Structures Included

1. **Array**: A dynamic array implementation that can resize as needed.
2. **Vector**: A versatile vector that supports dynamic resizing and various utility functions.
3. **Linked List**: A singly linked list implementation for efficient insertions and deletions.
4. **Stack**: A last-in, first-out (LIFO) stack data structure.
5. **Queue**: A first-in, first-out (FIFO) queue data structure.
6. **Min Heap**: A binary heap that maintains the minimum element at the root.
7. **Max Heap**: A binary heap that maintains the maximum element at the root.
8. **Ordered Map**: A map implementation that maintains order based on keys.
9. **Unordered Map**: A hash map implementation for key-value pairs with average constant time complexity for lookups.
10. **Binary Search Tree (BST)**: A tree data structure that maintains sorted order of elements for efficient searching, insertion, and deletion.
11. **Binary Tree**: A general binary tree implementation for various tree-related operations.
12. **Pair**: A utility structure for holding two related values.
13. **Triplet**: A utility structure for holding three related values.
14. **Quartet**: A utility structure for holding four related values.

## Utility Functions

### Number Utilities

The library includes utility functions for basic numerical operations:

- **Max**: Find the maximum value among two numbers.
- **Min**: Find the minimum value among two numbers.
- **Swap**: Swap the values of two variables.

### Array Utilities

The library also provides utility functions for common array operations, such as:

- **Sum**: Calculate the sum of elements in an array.
- **Maximum**: Find the maximum value in an array.
- **Minimum**: Find the minimum value in an array.
- **Mapping**: Apply a function to each element of an array.
- **Filtering**: Filter elements of an array based on a condition.
- **Reduction**: Reduce an array to a single value based on a binary operation.
- **Reverse**: Reverse the order of elements in an array.
- **Sort**: Sort an array using a specified sorting algorithm.

## Installation

To use this library, follow these steps:

1. Clone the repository:
   ```bash
   git clone https://your-repo-url.git
   cd your-repo-name
   ```

2. Compile the library and your program:
   ```bash
   gcc -o your_program src/your_program.c src/vector.c src/linked_list.c src/stack.c src/queue.c src/min_heap.c src/max_heap.c src/map.c src/bst.c src/binary_tree.c -I include
   ```

## Usage

Include the respective header files in your C source files. Here’s a simple example of how to use the utility functions and the `Vector` implementation:

### Using Number Utilities

```c
#include "../include/utils.h"

int main() {
    int a = 5, b = 10;
    printf("Max: %d\n", max(a, b)); // Outputs 10
    printf("Min: %d\n", min(a, b)); // Outputs 5
    swap(&a, &b);
    printf("After Swap: a = %d, b = %d\n", a, b); // Outputs a = 10, b = 5
    return 0;
}
```

### Using Array Utilities

```c
#include "../include/array_utils.h"

int main() {
    int arr[] = {3, 1, 4, 1, 5, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Sum: %d\n", array_sum(arr, size)); // Outputs sum of array
    array_reverse(arr, size);
    // Print reversed array
    return 0;
}
```

### Using a Vector

```c
#include <stdio.h>
#include "../include/vector.h"

int main() {
    Vector *arr = constructFill(5, -1);  // Create a new vector filled with values
    print(arr);
    arr = constructLen(5); // Create a new vector of given length
    print(arr);
    print(arr1);
    set(arr1, 0, 5);
    set(arr1, 1, 4);
    set(arr1, 2, 3);
    set(arr1, 3, 2);
    set(arr1, 4, 1);
    print(arr1);
    sort(arr1);     // sort vector
    print(arr1);    // Print vector contents: [1, 2, 3, 4, 5]
    swap(arr, 0, arr->length - 1); // swap elements
    print(arr);
    printf("\nsum: %d", sum(arr)); // find sum
    printf("\nmax: %d", max(arr)); // find max
    destruct(arr1); // Free vector memory
    return 0;
}
```

io
```commandline
PS C:\Users\KIIT\CLionProjects\STL> gcc -o test test/test.c src/vector.c -I include
PS C:\Users\KIIT\CLionProjects\STL> ./test                                         

[-1, -1, -1, -1, -1]

[0, 0, 0, 0, 0]

[5, 4, 3, 2, 1]

[1, 2, 3, 4, 5]

[5, 2, 3, 4, 1]

sum: 15
max: 5
PS C:\Users\KIIT\CLionProjects\STL>
```
## Examples

Provide code examples demonstrating how to use different data structures and utility functions.

### Using a Stack

```c
Stack *stack = createStack();
push(stack, 1);
push(stack, 2);
printf("%d\n", pop(stack)); // Outputs 2
destroyStack(stack);
```

### Using a Min Heap

```c
MinHeap *heap = createMinHeap();
insert(heap, 3);
insert(heap, 1);
insert(heap, 2);
printf("%d\n", extractMin(heap)); // Outputs 1
destroyMinHeap(heap);
```

## Contributing

Contributions are welcome! Feel free to submit issues or pull requests. Please ensure your code adheres to the existing style and conventions used in the project. The name's Mishra, Divyanshu Mishra ;)

---