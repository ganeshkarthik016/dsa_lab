#include "dsa.h"

// ==================== STACK ====================
void pushStack(StackNode **top, int val) {
    StackNode *node = (StackNode*)malloc(sizeof(StackNode));
    node->data = val;
    node->next = *top;
    *top = node;
}

int popStack(StackNode **top) {
    if (*top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    StackNode *temp = *top;
    int val = temp->data;
    *top = (*top)->next;
    free(temp);
    return val;
}

int peekStack(StackNode *top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

int isEmptyStack(StackNode *top) {
    return top == NULL;
}

// ==================== QUEUE ====================
Queue* createQueue() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue *q, int val) {
    QueueNode *node = (QueueNode*)malloc(sizeof(QueueNode));
    node->data = val;
    node->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = node;
        return;
    }

    q->rear->next = node;
    q->rear = node;
}

int dequeue(Queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }

    QueueNode *temp = q->front;
    int val = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return val;
}

int peekQueue(Queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->front->data;
}

int isEmptyQueue(Queue *q) {
    return q->front == NULL;
}

// ==================== VECTOR ====================
Vector* createVector(int capacity) {
    Vector *v = (Vector*)malloc(sizeof(Vector));
    v->arr = (int*)malloc(sizeof(int) * capacity);
    v->size = 0;
    v->capacity = capacity;
    return v;
}

void pushBack(Vector *v, int val) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->arr = (int*)realloc(v->arr, sizeof(int) * v->capacity);
    }
    v->arr[v->size++] = val;
}

int popBack(Vector *v) {
    if (v->size == 0) {
        printf("Vector is empty\n");
        return -1;
    }
    return v->arr[--v->size];
}

int peekVector(Vector *v) {
    if (v->size == 0) {
        printf("Vector is empty\n");
        return -1;
    }
    return v->arr[v->size - 1];
}

int get(Vector *v, int index) {
    if (index < 0 || index >= v->size) {
        printf("Index out of bounds\n");
        return -1;
    }
    return v->arr[index];
}

void set(Vector *v, int index, int val) {
    if (index < 0 || index >= v->size) {
        printf("Index out of bounds\n");
        return;
    }
    v->arr[index] = val;
}

int sizeVector(Vector *v) {
    return v->size;
}
