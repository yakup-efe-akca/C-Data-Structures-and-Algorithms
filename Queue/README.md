# Queue Implementation in C

A simple implementation of the Queue data structure in C using arrays and the FIFO (First In, First Out) principle.

## Features

- Enqueue elements
- Dequeue elements
- Peek at the front element
- Check if the queue is empty
- Display queue elements

## How to Run

### Requirements
- C compiler (Clang or GCC)

### Steps

1. Download this repository.
2. Open a terminal and navigate to the project folder.
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
-------------------------------------------------------------------------------------
## Circular Queue

An array-based implementation of a Circular Queue.

Unlike a regular queue, a circular queue reuses empty positions
in the array using the modulo operator.

### Features
- Enqueue and dequeue elements
- Peek at the front element
- Check if the queue is empty or full
- Display queue elements
- Circular indexing using modulo

### Example Output

```text
10 -> 20 -> 30
30
30 -> 40 -> 50 -> 60
Front: 30
```