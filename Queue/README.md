# Queue Implementation in C

Implementations of the Queue data structure in C using arrays and the FIFO (First In, First Out) principle.

## Features

- Enqueue and dequeue elements
- Peek at the front element
- Check if the queue is empty
- Display queue elements

## How to Run

### Requirements
- C compiler (Clang or GCC)

### Steps

1. Download this repository.
2. Open a terminal and navigate to the Queue folder.
3. Compile the program:

   ```bash
   clang Queue.c -o Queue
   ```

4. Run the program:

   ```bash
   ./Queue
   ```

No IDE is required.

## Example Output

```text
10 -> 20 -> 30
20 -> 30
Front: 20
```

-------------------------------------------------------------------------

## Circular Queue

An array-based implementation of a Circular Queue.

Unlike a regular queue, a circular queue reuses empty positions in the array using the modulo operator.

### Features

- Enqueue and dequeue elements
- Peek at the front element
- Check if the queue is empty or full
- Display queue elements
- Circular indexing using modulo

### How to Run

Compile the program:

```bash
clang CircularQueue.c -o CircularQueue
```

Run the program:

```bash
./CircularQueue
```

### Example Output

```text
10 -> 20 -> 30
30
30 -> 40 -> 50 -> 60
Front: 30
```

------------------------------------------------------------------------------

## Recursive Queue Reversal

A recursive algorithm that reverses the order of elements in a Circular Queue.

The algorithm uses recursion to remove elements and insert them back in reverse order.

### Features

- Reverse a queue using recursion
- Reuse existing enqueue and dequeue operations
- Reverse elements without an additional array or explicit stack

### Example Output

```text
Before: 30 -> 40 -> 50 -> 60
After:  60 -> 50 -> 40 -> 30
```

### Complexity

- Time Complexity: O(n)
- Space Complexity: O(n) due to recursive function calls

The recursive reversal is implemented in `CircularQueue.c`.