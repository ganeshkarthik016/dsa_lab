#ifndef DSA_H
#define DSA_H

#include <stdio.h>
#include <stdlib.h>

// ==================== STACK ====================
typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

void pushStack(StackNode **top, int val);
int popStack(StackNode **top);
int peekStack(StackNode *top);
int isEmptyStack(StackNode *top);

// ==================== QUEUE ====================
typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode *front;
    QueueNode *rear;
} Queue;

Queue* createQueue();
void enqueue(Queue *q, int val);
int dequeue(Queue *q);
int peekQueue(Queue *q);
int isEmptyQueue(Queue *q);

// ==================== VECTOR ====================
typedef struct Vector {
    int *arr;
    int size;
    int capacity;
} Vector;

Vector* createVector(int capacity);
void pushBack(Vector *v, int val);
int popBack(Vector *v);
int peekVector(Vector *v);
int get(Vector *v, int index);
void set(Vector *v, int index, int val);
int sizeVector(Vector *v);

#endif
