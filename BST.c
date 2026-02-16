#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct node{
    int data;
    struct node* lchild;
    struct node* rchild;
};
void insert(struct node **root,int data){
    if((*root)==NULL){
        struct node* nd = (struct node*)malloc(sizeof(struct node));
    nd->data = data;
    nd->rchild = NULL;
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
struct node* search(struct node* root,int key){
    if(root == NULL) return NULL;
    if(key == root->data) return root;
    else if(root->data>key) return search(root->lchild,key);
    else return search(root->rchild,key);
}
struct node* maximum(struct node* root){
    while((root)->rchild!=NULL) (root) = (root)->rchild;
    return (root);
}
struct node* minimum(struct node* root){
    while((root)->lchild!=NULL) (root) = (root)->lchild;
    return (root);
}
struct node* pred(struct node *root){
    if(root->lchild==NULL) return NULL;
    else return maximum(root->lchild);
}
struct node* sucss(struct node *root){
    if(root->rchild==NULL) return NULL;
    else return minimum(root->rchild);
}
void delete(struct node** root,int key){
  struct node* current = search((*root),key);
  if(current != NULL){
    if(current->lchild==NULL){
        struct node* temp= current->rchild;
        current = current->rchild;
        free(temp);
    }
    else if(current->rchild==NULL){
        struct node* temp= current->lchild;
        current = current->lchild;
        free(temp);
    }
    else{
        struct node* pre = pred(*root);
        current->data = pre->data;
        delete(current->lchild,pre->data);
        }
  }
}
// ==================== Solve Function ====================
void solve() {
    // Your code here
}



int main() {
    solve();
    return 0;
}