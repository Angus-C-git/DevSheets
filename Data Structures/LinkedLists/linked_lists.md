# Linked Lists

## Overview

Linked lists are a unique way to represent a sequence of connected or sequential items without storing each item one after another in memory. This is achived by each item in the list pointing to the next item in the list. In the case of doubly linked lists the node preceding the current item is also pointed to.

## Singly Linked Lists

A singly linked list will typically be represented in the following manner.

```
list {
	Key : Val,
	Next : item
}
```

In C a typical representation is as follows.

```
typedef struct node *Node;
struct node {
	int key;
	Node next;
}

typedef struct list *List;
struct list {
	Node head;
}
```

## Doubly Linked List


A typical representation in C is.

```
typedef struct node *Node;
struct node {
	int value;
	Node next;
	Node prev;
};

typedef struct list *List;
struct list {
	Node first;
	Node last;
	int size;
};

```
