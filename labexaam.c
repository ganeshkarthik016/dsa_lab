#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct node{
  int data;
  struct node* next;
};
struct node* newnode(int id){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new -> data = id;
    new -> next = NULL;
    return new;
}
void add(int id,struct node* arr[],int m){
    int in = id%m;
    struct node* new = newnode(id);
    if(arr[in]==NULL){
        arr[in] = new;
    }
    else{
        struct node* cur = arr[in];
        while(cur->next!=NULL) cur =  cur->next;
        cur->next = new;
    }
}
void delete(int id,struct node* arr[],int m){
    int in = id%m;
    struct node* cur = arr[in];
        while(cur->data!=id) cur =  cur->next;
   if(cur -> next == NULL) cur = NULL;
   else{
    struct node* temp  = cur->next;
    cur->data = cur->next->data;
    cur->next = cur->next->next;
    free(temp);
   }
}
void list(int box,struct node* arr[]){
    struct node* cur = arr[box];
    int a[50];int z=0;
    if(cur == NULL) {printf("EMPTY\n");
    return;}
    else{
        while(cur!=NULL){
            a[z] = cur->data;
            z++;
            cur = cur->next;
        }
    }
        for(int i=0;i<z;i++){
            for(int  j=i;j<z;j++){
              if(a[i]>a[j]){
                int t = a[j];
                a[j] = a[i];
                a[i] = t;
              }
            }
        }
        for(int  j=0;j<z;j++){
              printf("%d ",a[j]);
            }
        printf("\n");
    
}
void check(int id,struct node* arr[],int m){
    int in = id%m;
    int fon = 0;
    struct node* cur = arr[in];
    if(cur == NULL){
        printf("NOT FOUND\n");
        return;
    }
        while(cur->next!=NULL) {
            if(cur->data==id){ fon = 1;
            break;}
            cur =  cur->next;
        }
    if(fon==1) printf("EXISTS\n");
    else printf("NOT FOUND\n");
}
void max(struct node* arr[],int m){
  int maxi = -10000;
  for(int i=0;i<m;i++){
     struct node* cur = arr[i];
     while(cur !=NULL) { if((cur->data)>maxi) maxi = cur->data;
        else maxi  = maxi;
    cur = cur->next;}
  }
  printf("%d\n",maxi);
}
void solve() {
    int m,k; printf("Enter m and k: "); scanf("%d %d",&m,&k);
    struct node* arr[m];
    for(int i=0;i<m;i++){
        arr[i] = NULL;
    }
   while(k--){
    printf("1.ADD\n");
    printf("2.CHECK\n");
    printf("3.LIST\n");
    printf("4.MAX\n");
    printf("Enter : ");
    int n; scanf("%d",&n);
    switch (n)
    {
     case 1:
      printf("Enter the id: "); int id; scanf("%d",&id);
      add(id,arr,m);
      break;
    case 2:
       printf("Enter the id: ");int idd; scanf("%d",&idd);
       check(idd,arr,m);
       break;
    case 3:
     printf("Enter the box: ");int box; scanf("%d",&box);
     list(box,arr);
     break;
    case 4:
     printf("MAX: ");max(arr,m);
     break;
   }
}}

/////////////////////////////////////////////////////////////////////////////////
// Author: ganesh B. KARTHIK
// Institute: IIIT Jabalpur
/////////////////////////////////////////////////////////////////////////////////

int main() {
    solve();
    return 0;
}