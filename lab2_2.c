#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include"dsa.h"
// ==================== Solve Function ====================
struct employee
{
    int employeeid;
    char employeename[100];
    int basicsalary;
};

void solve() {
    // Your code here
    struct employee emp[5];
    for(int i=0;i<5;i++){
        printf("Enter the id of employee %d : ",i+1);
        scanf("%d",&emp[i].employeeid);
        printf("Enter the name of employee %d : ",i+1);
        scanf("%s",emp[i].employeename);
        printf("Enter the basic salary of employee %d : ",i+1);
        scanf("%d",&emp[i].basicsalary);
    }
    int diff[4];
    for(int i=0;i<5;i++){
        printf("id of employee %d is %d\n",i+1,emp[i].employeeid);
        printf("name of employee %d is %s\n",i+1,emp[i].employeename);
        printf("basic salary of employee %d is %d\n",i+1,emp[i].basicsalary);
        printf("Size of employee record is %d\n",(sizeof(emp[i])));
        if(i>0) {diff[i-1] = sizeof(emp[i]) - sizeof(emp[i-1]);
         printf("The diff of  size of record %d and record %d is %d\n",i+1,i,diff[i-1]);}
    }
    struct employee *p = emp;
    printf("adddress of record of employee 1 : %p\n",p);
    printf("adddress of record of employee 2 : %p\n",p+1);
    printf("difference bw adddress of record of employee 1 and employee 2 : %p\n",(p+1) -  p);
    for(int i = 0;i<5;i++){
        printf("adddress of record of employee %d : %p\n",i+1,p);
        p++;
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