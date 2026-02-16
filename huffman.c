#include <stdio.h>
#include <stdlib.h>

struct node {
    char data;
    int freq;
    struct node *left, *right;
};

struct node* newNode(char d, int f) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = d;
    n->freq = f;
    n->left = n->right = NULL;
    return n;
}

struct node* minHeap[200];
int heapSize = 0;

void swap(struct node** a, struct node** b) {
    struct node* t = *a;
    *a = *b;
    *b = t;
}

void heapify(int i) {
    int smallest = i, l = 2*i+1, r = 2*i+2;
    if (l < heapSize && minHeap[l]->freq < minHeap[smallest]->freq) smallest = l;
    if (r < heapSize && minHeap[r]->freq < minHeap[smallest]->freq) smallest = r;
    if (smallest != i) {
        swap(&minHeap[i], &minHeap[smallest]);
        heapify(smallest);
    }
}

void push(struct node* n) {
    int i = heapSize++;
    minHeap[i] = n;
    while (i && minHeap[(i-1)/2]->freq > minHeap[i]->freq) {
        swap(&minHeap[i], &minHeap[(i-1)/2]);
        i = (i-1)/2;
    }
}

struct node* pop() {
    struct node* t = minHeap[0];
    minHeap[0] = minHeap[--heapSize];
    heapify(0);
    return t;
}

void printCode(struct node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCode(root->left, arr, top+1);
    }
    if (root->right) {
        arr[top] = 1;
        printCode(root->right, arr, top+1);
    }
    if (!root->left && !root->right) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++) printf("%d", arr[i]);
        printf("\n");
    }
}

int main() {
    char chars[] = {'a','b','c','d','e','f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int n = 6;

    for (int i = 0; i < n; i++)
        push(newNode(chars[i], freq[i]));

    while (heapSize > 1) {
        struct node *l = pop(), *r = pop();
        struct node* new = newNode('$', l->freq + r->freq);
        new->left = l;
        new->right = r;
        push(new);
    }

    int arr[50];
    printCode(minHeap[0], arr, 0);
    return 0;
}
