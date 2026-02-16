#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct node{
 int data;
 struct node* next;
};

void insertion(struct node **rare,int i){
 struct node* point = (struct node*)malloc(sizeof(struct node));
 printf("Enter data to insert: ");
 scanf("%d",&point->data);
 if((*rare)==NULL){
    (*rare) = point;
    (*rare)->next = (*rare);
    return;
 }
 struct node* cur = (*rare);
 while(i--){
    cur = cur->next;
 }
 point->next  =  cur->next;
 cur->next = point;
 if(cur==(*rare)) *rare = point;
}

void deletion(struct node **rare,int i){
    if((*rare)==NULL) return;
    struct node* cur = (*rare);
    if((*rare)->next == (*rare)){
        free(*rare);
        (*rare) = NULL;
        return;
    }
    while(i--){
        cur = cur->next;
    }
    struct node* temp = cur->next;
    cur->data = temp->data;
    cur->next = temp->next;
    if(temp==(*rare)) *rare = cur;
    free(temp);
}

void update(struct  node *rare,int i ){
    if(rare==NULL) return;
    struct node* cur = rare;
    while(i--){
        cur =  cur->next;
    }
    int c;
    printf("Enter new data: ");
    scanf("%d",&c);
    cur->data = c;
}

void display(struct  node *rare){
    if(rare==NULL){
        printf("List is empty\n");
        return;
    }
    struct node* cur = rare->next;
    printf("Current List: ");
    do{
        printf("%d ",cur->data);
        cur = cur->next;
    }while(cur!=rare->next);
    printf("\n");
}
// ==================== Solve Function ====================
void solve() {
    struct node* rare = NULL;
    int choice,pos;
    while(1){
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Update\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter position to insert: ");
                scanf("%d",&pos);
                insertion(&rare,pos);
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d",&pos);
                deletion(&rare,pos);
                break;
            case 3:
                printf("Enter position to update: ");
                scanf("%d",&pos);
                update(rare,pos);
                break;
            case 4:
                display(rare);
                break;
            case 5:
                return;
            default:
                printf("Invalid choice\n");
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////
// Author: ganesh B. KARTHIK
// Institute: IIIT Jabalpur
/////////////////////////////////////////////////////////////////////////////////

int main() {
    solve();
    return 0;
}
