#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include"dsa.h"
struct node{
  int data;
  struct node* lchild;
  struct  node* rchild;
};
void insert(struct node **root,int data){
    if((*root)==NULL){
        struct node* nd = (struct node*)malloc(sizeof(struct node));
    nd->data = data;
    nd->lchild = NULL;
    nd->rchild = NULL;
    *root = nd;
 }
 else{
    if((*root)->data>data){
      insert(&((*root)->lchild),data);
    }
    else{
        insert(&((*root)->rchild),data);
    }
 }
}
int search(struct node* root,int target){
    if(root==NULL) return 0;
   if(root->data == target) return 1;
   if(target>root->data){
    root = root->rchild;
    return search(root,target);
   }
   else{
    root = root->lchild;
    return search(root,target);
   }
   
}
void preorder(struct node* root){
 if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root-> lchild);
    preorder(root->  rchild);
}
void postorder(struct node *root) {
    if (root == NULL) return;
    postorder(root -> lchild);
    postorder(root->  rchild);
    printf("%d ", root->data);
}
void inorder(struct node* root){
 if (root == NULL) return;
    inorder(root -> lchild);
    printf("%d ", root->data);
    inorder(root->  rchild);
}
void solve() {
    // Your code here
    struct node* root = (struct node*)malloc(sizeof(struct node));
    root = NULL;
    while(1){
        printf("1. To insert\n");
        printf("2. To search\n");
         printf("3. To print postorder\n");
        printf("4. To print preorder\n");
         printf("5. To print inorder\n");
        printf("6. To exit\n");
        int n; scanf("%d",&n);
        if(n==6) break;
        switch (n)
        {
        case 1:
            printf("Enter number :");
             int data;scanf("%d",&data);
            insert(&root,data);
            break;
        case 2:
           printf("Enter number :");
            int data1;scanf("%d",&data1);
            if(search(root,data1)) printf("Yes the number is present in tree");
            else printf("No the number is not present in tree\n");
            break;
        case 3:
           printf("Postorder :");
           postorder(root);
           printf("\n");
           break;
        case 4:
          printf("Preoorder :");
         preorder(root);
         printf("\n");
         break;
        case 5:
          printf("Inorder :");
          inorder(root);
          printf("\n");
          break;
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