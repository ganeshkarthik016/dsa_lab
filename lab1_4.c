#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



void solve() {
    char a[100],ans[100];
    printf("Enter the string : ");scanf("%s",a);
    char b;  
    printf("Enter the char : "); 
    scanf(" %c",&b);
    char *p = a;
    int i = 0;
    while(*p!='\0'){
       if(*p!=b){
        ans[i] = *p;
        i++;
       }
       p++;
    }
    printf("%s",ans);
}

/////////////////////////////////////////////////////////////////////////////////
// Author: ganesh KARTHIK Bhanupanthula
// Institute: IIITDM Jabalpur
/////////////////////////////////////////////////////////////////////////////////

int main() {
    solve();
    return 0;
}