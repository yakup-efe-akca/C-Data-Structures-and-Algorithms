# Singly Linked List in C

A simple implementation of a singly linked list in C using
dynamic memory allocation and pointers.

## Description

A singly linked list is a linear data structure consisting of nodes. Each node contains data and a pointer to the next node. Unlike arrays, linked list nodes do not need to be stored in contiguous memory locations.

This project implements a singly linked list in C. It supports insertion, deletion, searching, traversal, and memory management.

## Features

- **createNode()** - Creates a new node using dynamic memory allocation.
- **insertAtBeginning()** - Inserts a new node at the beginning of the list.
- **insertAtEnd()** - Inserts a new node at the end of the list.
- **deleteNode()** - Deletes the first node containing the specified value.
- **search()** - Searches for a value in the list.
- **printList()** - Displays all elements of the list.
- **freeList()** - Frees all dynamically allocated memory used by the list.

## How to Run

Compile:
```bash
clang LinkedList.c -o LinkedList
```

Run:
```bash
./LinkedList
```

## Example Output

1
0
10 -> 30 -> NULL
30 -> NULL
NULL
That value does not exist.

## What I Learned

Through this project, I practiced:

- Working with pointers and structures in C.
- Using dynamic memory allocation with malloc() and free().
- Implementing insertion, deletion, and search operations.
- Traversing a linked list using pointers.
- Handling NULL pointers and empty lists.
- Managing memory to prevent memory leaks.