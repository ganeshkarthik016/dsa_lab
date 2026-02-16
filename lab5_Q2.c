#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct node {
    char data;
    struct node* next;
};

struct node* create(char* str) {
    struct node* head = NULL;
    struct node* tail = NULL;
    for (int i = 0; str[i]; i++) {
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp->data = str[i];
        temp->next = NULL;
        if (!head) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }
    if (tail) tail->next = head;
    return head;
}

int compare(struct node* s1, int l1, struct node* s2, int l2) {
    struct node* c1 = s1;
    struct node* c2 = s2;
    for (int i = 0; i < l1 && i < l2; i++) {
        if (c1->data < c2->data) return -1;
        if (c1->data > c2->data) return 1;
        c1 = c1->next;
        c2 = c2->next;
    }
    if (l1 == l2) return 0;
    return l1 < l2 ? -1 : 1;
}

void solve() {
    char a[100], b[100];
    scanf("%s %s", a, b);
    int l1 = strlen(a), l2 = strlen(b);
    struct node* s1 = create(a);
    struct node* s2 = create(b);
    printf("%d", compare(s1, l1, s2, l2));
}

/////////////////////////////////////////////////////////////////////////////////
// Author: ganesh B. KARTHIK
// Institute: IIIT Jabalpur
/////////////////////////////////////////////////////////////////////////////////

int main() {
    solve();
    return 0;
}
