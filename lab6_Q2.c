#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct stack {
    char data;
    struct stack* next;
};
void push(struct stack **header, char a) {
    struct stack *node = (struct stack*)malloc(sizeof(struct stack));
    node->data = a;
    node->next = *header;
    *header = node;
}
char peek(struct stack *header) {
    if (header == NULL) {
        return '\0';
    }
    return header->data;
}
char pop(struct stack **header) {
    if (*header == NULL) {
        return '\0';
    }
    struct stack *temp = *header;
    char ans = temp->data;
    *header = temp->next;
    free(temp);
    return ans;
}
// ==================== Solve Function ====================
int rating(char a,char b){
    if(a=='('&&b==')') return 1;
    else if(a=='{'&&b=='}') return 1;
    else if(a=='['&&b==']') return 1; 
    else return 0;
}
int evaluvate(char exp[]){
 int bl = 1;
 struct stack *st = NULL;
 int n = strlen(exp);
 for(int i = 0;i<n;i++){
    if(exp[i]=='('||exp[i]=='{'||exp[i]=='[') push(&st,exp[i]);
    else{
        char c = peek(st);
        if(rating(c,exp[i])==0||st == NULL) {
            bl = 0;
            break;
        }
        if(rating(c,exp[i])) pop(&st);
    }
 }
 if(st!=NULL) bl = 0;
 return bl;
}
void solve() {
    // Your code here
    char exp[50];
    scanf("%s",exp);
    if(evaluvate(exp)) printf("Balanced");
    else printf("Not Balanced");
}

/////////////////////////////////////////////////////////////////////////////////
// Author: ganesh B. KARTHIK
// Institute: IIIT Jabalpur
/////////////////////////////////////////////////////////////////////////////////

int main() {
    solve();
    return 0;
}