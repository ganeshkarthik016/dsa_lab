#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

 struct student {
char name [20];
int age;
int marks;
struct student *next;
 };

// ==================== Solve Function ====================
void solve() {
    // Your code here
    struct student s1,s2,s3;
    scanf("%s %d %d",s1.name,&s1.age,&s1.marks);
    scanf("%s %d %d",s2.name,&s2.age,&s2.marks);
    scanf("%s %d %d",s3.name,&s3.age,&s3.marks);
    s1.next = &s2;
    s2.next = &s3;
    s3.next = NULL;
    struct student *p = &s1;
    while(p!=NULL){
        // char name[50];
        // strcpy(name, p->name);
        // int age = p->age;
        // int marks = p->marks;
        printf("Name : %s\n",p->name);
        printf("Age : %d\n",p->age);
        printf("Marks : %d\n",p->marks);
        p = p->next;
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