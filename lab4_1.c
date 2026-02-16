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
   struct node a,b,c,d,e;
   scanf("%d",&a.data);
   scanf("%d",&b.data);
   scanf("%d",&c.data);
   scanf("%d",&d.data);
   scanf("%d",&e.data);
   struct node* header;
   header = NULL;
   header = &a;
   a.next = NULL;
   b.next = header;
   header = &b;
   c.next = header;
   header = &c;
   d.next = header;
   header = &d;
   e.next = header;
   header = &e;
   struct node* cur;
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