#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



// ==================== Solve Function ====================
struct vector{
    float x;
    float y;
    float z;
};
void solve() {
    // Your code here
    struct vector a,b,c;
    printf("Enter vector a : \n");
    scanf("%f %f %f",&a.x,&a.y,&a.z);
    printf("Enter vector b : \n");
    scanf("%f %f %f",&b.x,&b.y,&b.z);
    printf("vector a : (%d)i + (%d)j + (%d)k\n",(int)a.x,(int)a.y,(int)a.z);
    printf("vector b : (%d)i + (%d)j + (%d)k\n",(int)b.x,(int)b.y,(int)b.z);
    c.x = a.x + b.x;
    c.y = a.y + b.y;
    c.z = a.z + b.z;
    printf("vector a + b : (%d)i + (%d)j + (%d)k\n",(int)c.x,(int)c.y,(int)c.z);
    printf("vector (a + b)/10 : (%f)i + (%f)j + (%f)k\n",c.x/10,c.y/10,c.z/10);
}

/////////////////////////////////////////////////////////////////////////////////
// Author: ganesh KARTHIK Bhanupanthula
// Institute: IIITDM Jabalpur
/////////////////////////////////////////////////////////////////////////////////

int main() {
    solve();
    return 0;
}