#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stddef.h>



// ==================== Solve Function ====================
void solve() {
    char a[100], b[100];
    scanf("%s", a);
    scanf("%s", b);
    int n = strlen(a);
    int m = strlen(b);
    char *p = a;
    char *q = b;
    int same = 1;
    if(n==m){
    while (*p != '\0' && *q != '\0') {
        if (*p != *q) {
            same = 0;
            break;
        }
        p++;
        q++;
    }} 

    if (same && n==m) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    printf("%d %d",n,m);
}

/////////////////////////////////////////////////////////////////////////////////
// Author: ganesh KARTHIK Bhanupanthula
// Institute: IIITDM Jabalpur
/////////////////////////////////////////////////////////////////////////////////

int main() {
    solve();
    return 0;
}