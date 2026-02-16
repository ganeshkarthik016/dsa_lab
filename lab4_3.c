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
   char p[50],q[50]; scanf("%s %s",p,q);
   struct node* h1;
   struct node* h2;
   h1 = NULL;
   h2 = NULL;
   int n,m;
   n = strlen(p);
   m = strlen(q);
   int i = 0;
   struct node k1[n];
   struct node k2[m];
   while(i<n){
    k1[i].data = p[n-i-1];
    k1[i].next = h1;
     h1 = &k1[i];
   }
   while(i<n){
    k1[i].data = p[n-i-1];
    k1[i].next = h1;
     h1 = &k1[i];
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