#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct node
{
    int data;
    struct node* next;
};
void solve() {
   // Your code here
   int n; scanf("%d",&n);
   struct node * header;
   struct node a;
   scanf("%d",&a.data);
   a.next = NULL;
   header = &a;
   n--;
   struct node* cur;
   while(n--){
    struct node* k = (struct node*)malloc(sizeof(struct node));
    scanf("%d",&k->data);
    if(header->next==NULL){
        k->next = NULL;
        header->next = k;
    }
    else{
        k->next = header->next;
        header->next = k;
    }
   }
   cur = header;
   while(cur!=NULL){
    printf("%d ",cur->data);
    cur = cur->next;
   }
}

/////////////////////////////////////////////////////////////////////////////////
// Author: ganesh KARTHIK Bhanupanthula
// Institute: IIITDM Jabalpur
/////////////////////////////////////////////////////////////////////////////////

int main() {
    solve();
    return 0;
}