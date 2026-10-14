# Stack Implementation in C

A simple implementation of the Stack data structure in C using arrays and the LIFO (Last In, First Out) principle.

## Features

- Push and pop elements
- Peek at the top element
- Check if the stack is empty
- Display stack elements
- Check balanced parentheses using Stack 

## How to Run

### Requirements
- C compiler (Clang or GCC)

### Steps

1. Download this repository.
2. Open a terminal and navigate to the project folder.
3. Compile the program:

   ```bash
   clang Stack.c -o Stack
   ```

4. Run the program:

   ```bash
   ./Stack
   ```

No IDE is required.

## Example Output

The balanced parentheses checker returns `1` for balanced expressions and `0` for unbalanced expressions.

```text
Input: {[()]}  -> 1
Input: {[(])}  -> 0
Input: ((()))  -> 1
Input: (()     -> 0
Input: )       -> 0
```
--------------------------------------------------------------------------------------

## Minimum Stack

An extended stack implementation that supports finding the minimum element in O(1) time.

### Features
- Push elements
- Pop elements
- Find the minimum element in O(1) time
- Track minimum values using an auxiliary array

### How to Run

```bash
clang MinStack.c -o MinStack
./MinStack
```

### Example Output

```text
Minimum: 2
Minimum after pop: 3
```