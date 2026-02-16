#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char data;
    struct node *left, *right;
};

int search(char in[], int s, int e, char x) {
    int i;
    for (i = s; i <= e; i++)
        if (in[i] == x) return i;
    return -1;
}

struct node* build(char in[], char pre[], int s, int e, int *i) {
    if (s > e) return NULL;
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = pre[*i];
    (*i)++;
    if (s == e) {
        n->left = n->right = NULL;
        return n;
    }
    int idx = search(in, s, e, n->data);
    n->left = build(in, pre, s, idx - 1, i);
    n->right = build(in, pre, idx + 1, e, i);
    return n;
}

void post(struct node *r) {
    if (r == NULL) return;
    post(r->left);
    post(r->right);
    printf("%c ", r->data);
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    char in[100], pre[100];
    printf("Enter inorder traversal (no spaces): ");
    scanf("%s", in);
    printf("Enter preorder traversal (no spaces): ");
    scanf("%s", pre);

    int i = 0;
    struct node *r = build(in, pre, 0, n - 1, &i);

    printf("Postorder traversal: ");
    post(r);
    printf("\n");

    return 0;
}
