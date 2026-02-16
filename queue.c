#include <stdio.h>
#include <stdlib.h>

struct queue {
    int data;
    struct queue* next;
};

void enqueue(struct queue **front, struct queue **rear, int val) {
    struct queue *node = (struct queue*)malloc(sizeof(struct queue));
    node->data = val;
    node->next = NULL;

    if (*rear == NULL) { 
        *front = *rear = node;
    } else {
        (*rear)->next = node;
        *rear = node;
    }
}
int dequeue(struct queue **front, struct queue **rear) {
    if (*front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    struct queue *temp = *front;
    int val = temp->data;

    *front = (*front)->next;
    if (*front == NULL) 
        *rear = NULL;

    free(temp);
    return val;
}
int peek(struct queue *front) {
    if (front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    return front->data;
}

void display(struct queue *front) {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    while (front != NULL) {
        printf("%d ", front->data);
        front = front->next;
    }
    printf("\n");
}

int main() {
    struct queue *front = NULL, *rear = NULL;

    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 20);
    enqueue(&front, &rear, 30);

    display(front);

    printf("Peek: %d\n", peek(front));

    printf("Dequeued: %d\n", dequeue(&front, &rear));
    printf("Dequeued: %d\n", dequeue(&front, &rear));

    display(front);

    printf("Peek: %d\n", peek(front));

    printf("Dequeued: %d\n", dequeue(&front, &rear));
    printf("Dequeued: %d\n", dequeue(&front, &rear)); 

    return 0;
}
