#include <stdio.h>
#include <stdlib.h>

struct node {
    int data, height;
    struct node *lchild, *rchild;
};

int max(int a,int b){ return a>b?a:b; }
int height(struct node* n){ return n ? n->height : 0; }
int balance(struct node* n){ return n ? height(n->lchild) - height(n->rchild) : 0; }

void rightRotate(struct node **root){
    struct node* y = *root;
    struct node* x = y->lchild;
    struct node* t = x->rchild;
    x->rchild = y;
    y->lchild = t;
    y->height = max(height(y->lchild), height(y->rchild)) + 1;
    x->height = max(height(x->lchild), height(x->rchild)) + 1;
    *root = x;
}

void leftRotate(struct node **root){
    struct node* x = *root;
    struct node* y = x->rchild;
    struct node* t = y->lchild;
    y->lchild = x;
    x->rchild = t;
    x->height = max(height(x->lchild), height(x->rchild)) + 1;
    y->height = max(height(y->lchild), height(y->rchild)) + 1;
    *root = y;
}

struct node* minNode(struct node* root){
    while(root->lchild) root = root->lchild;
    return root;
}

void insert(struct node **root, int data){
    if(*root == NULL){
        struct node *nd = (struct node*)malloc(sizeof(struct node));
        nd->data = data;
        nd->lchild = nd->rchild = NULL;
        nd->height = 1;
        *root = nd;
        return;
    }
    if(data < (*root)->data) insert(&(*root)->lchild, data);
    else if(data > (*root)->data) insert(&(*root)->rchild, data);
    else return;

    (*root)->height = 1 + max(height((*root)->lchild), height((*root)->rchild));
    int b = balance(*root);

    if(b > 1 && data < (*root)->lchild->data)
        rightRotate(root);
    else if(b < -1 && data > (*root)->rchild->data)
        leftRotate(root);
    else if(b > 1 && data > (*root)->lchild->data){
        leftRotate(&(*root)->lchild);
        rightRotate(root);
    }
    else if(b < -1 && data < (*root)->rchild->data){
        rightRotate(&(*root)->rchild);
        leftRotate(root);
    }
}

void delete(struct node **root, int key){
    if(*root == NULL) return;
    if(key < (*root)->data) delete(&(*root)->lchild, key);
    else if(key > (*root)->data) delete(&(*root)->rchild, key);
    else {
        if((*root)->lchild == NULL || (*root)->rchild == NULL){
            struct node *temp = (*root)->lchild ? (*root)->lchild : (*root)->rchild;
            free(*root);
            *root = temp;
        } else {
            struct node *temp = minNode((*root)->rchild);
            (*root)->data = temp->data;
            delete(&(*root)->rchild, temp->data);
        }
    }
    if(*root == NULL) return;

    (*root)->height = 1 + max(height((*root)->lchild), height((*root)->rchild));
    int b = balance(*root);

    if(b > 1 && balance((*root)->lchild) >= 0)
        rightRotate(root);
    else if(b > 1 && balance((*root)->lchild) < 0){
        leftRotate(&(*root)->lchild);
        rightRotate(root);
    }
    else if(b < -1 && balance((*root)->rchild) <= 0)
        leftRotate(root);
    else if(b < -1 && balance((*root)->rchild) > 0){
        rightRotate(&(*root)->rchild);
        leftRotate(root);
    }
}

void preorder(struct node* root){
    if(root==NULL) return;
    printf("%d ",root->data);
    preorder(root->lchild);
    preorder(root->rchild);
}

void solve(){
    struct node* root = NULL;
    insert(&root,10);
    insert(&root,20);
    insert(&root,30);
    insert(&root,40);
    insert(&root,50);
    insert(&root,25);
    preorder(root);
    printf("\n");
    delete(&root,40);
    preorder(root);
    printf("\n");
}

int main(){
    solve();
    return 0;
}
