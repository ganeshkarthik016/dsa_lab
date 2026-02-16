#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct queue {
    int data;
    struct queue* next;
};
void enqueue(struct queue **front, struct queue **rear, int val) {
    struct queue *node = (struct queue*)malloc(sizeof(struct queue));
    node->data = val;
    node->next = NULL;

    if (*rear == NULL) { 
        *front = node;
        *rear = node;
    } 
    else {
        (*rear)->next = node;
        *rear = node;
        node->next = *front;
    }
}
int dequeue(struct queue **front, struct queue **rear) {
    if (*front == NULL) {
        return -1;
    }
    struct queue *temp = *front;
    int val = temp->data;
    *front = (*front)->next;
    if ((*front)->next == (*front))  {*rear = NULL;
    *front = NULL;}
    else (*rear)->next = *front;
    free(temp);
    return val;
}
int peek(struct queue *front) {
    if (front == NULL) {
        return -1;
    }
    return front->data;
}
void display(struct queue **front) {
    if (*front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    struct queue *cur = (*front);
    do {
        printf("%d ", cur->data);
        cur = cur->next;
    } while(cur!=(*front));
    printf("\n");
}
int count(struct queue *front){
    int i =0;
    if (front == NULL) {
       return 0;
    }
    struct queue *cur = (front);
    do {
        i++;
        cur = cur->next;
    } while(cur!=(front));
    return i;
}

struct stack {
    int data;
    struct stack* next;
};
void push(struct stack **header, int a) {
    struct stack *node = (struct stack*)malloc(sizeof(struct stack));
    node->data = a;
    node->next = *header;
    *header = node;
}
int stpeek(struct stack *header) {
    if (header == NULL) {
        return '\0';
    }
    return header->data;
}
int pop(struct stack **header) {
    if (*header == NULL) {
        return '\0';
    }
    struct stack *temp = *header;
    int ans = temp->data;
    *header = temp->next;
    free(temp);
    return ans;
}

void reverse(struct queue **front,struct queue **rear){
    int k; printf("Enter the number of elements : "); scanf("%d",&k);
    struct stack* st = NULL;
    int i = k;
    while(i--){
        push(&st,dequeue(front,rear));
    }
    i = k;
    while(i--){
        enqueue(front,rear,pop(&st));
    }
    int n = count(*front);
    i = n-k;
    while(i--){
        enqueue(front,rear,dequeue(front,rear));
    }
}
// ==================== Solve Function ====================
void solve() {
    struct queue *front = NULL, *rear = NULL;

    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 20);
    enqueue(&front, &rear, 30);
    display(&front);
    (peek(front)!=-1) ? printf("Peek: %d\n", peek(front)) : printf("Queue is empty\n");
    (peek(front)!=-1) ? printf("Dequeued: %d\n", dequeue(&front, &rear)): printf("Queue is empty\n");
    (peek(front)!=-1) ? printf("Dequeued: %d\n", dequeue(&front, &rear)): printf("Queue is empty\n");
    (peek(front)!=-1) ? printf("Peek: %d\n", peek(front)): printf("Queue is empty\n");
    (peek(front)!=-1) ? printf("Dequeued: %d\n", dequeue(&front, &rear)): printf("Queue is empty\n");
    (peek(front)!=-1) ? printf("Dequeued: %d\n", dequeue(&front, &rear)): printf("Queue is empty\n"); 
    (peek(front)!=-1) ? printf("Peek: %d\n", peek(front)): printf("Queue is empty\n");
    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 20);
    enqueue(&front, &rear, 30);
    enqueue(&front, &rear, 40);
    printf("Before reverse : ");display(&front);
    reverse(&front,&rear);
    printf("After reverse : ");display(&front);
}

/////////////////////////////////////////////////////////////////////////////////
// Author: ganesh B. KARTHIK
// Institute: IIIT Jabalpur
/////////////////////////////////////////////////////////////////////////////////

int main() {
    solve();
    return 0;
}