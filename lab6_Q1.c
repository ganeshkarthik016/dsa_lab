#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
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

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

void postfix(char exp[], char post[]) {
    struct stack* pstp = NULL;
    int n = strlen(exp);
    int j = 0;
    for (int i = 0; i < n; i++) {
        char ch = exp[i];
        if ((ch >= '0' && ch <= '9')) {
            post[j] = ch;
            j++;
        } 
        else if (ch == '(') {
            push(&pstp, ch);
        } 
        else if (ch == ')') {
            while (peek(pstp) != '(' && pstp != NULL) {
                post[j] = pop(&pstp);
                j++;
            }
            pop(&pstp); 
        } 
        else {
            while (pstp != NULL && precedence(peek(pstp)) >= precedence(ch)) {
                post[j] = pop(&pstp);
                j++;
            }
            push(&pstp, ch);
        }
    }
    while (pstp != NULL) {
        post[j] = pop(&pstp);
        j++;
    }
    post[j] = '\0';
}
int evaluvation(char post[]){
    struct stack *st = NULL;
    int n = strlen(post);
    for(int i = 0;i<n;i++){
      char ch = post[i];
        if ((ch >= '0' && ch <= '9')){
            push(&st,ch);
        }
        else {
            int a = pop(&st) - '0';
            int b = pop(&st) - '0';
            switch (ch)
            {
            case '+':
                a = b + a;
                char c = (char)(a + (int)'0');
                push(&st,c);
                break;
            case '-':
                a = b - a;
                char c1 = (char)(a + (int)'0');
                push(&st,c1);
                break;
            case '*':
                a = b * a;
                char c2 = (char)(a + (int)'0');
                push(&st,c2);
                break;
            case '/':
                a = b / a;
                char c3 = (char)(a + (int)'0');
                push(&st,c3);
                break;
            case '^':
                a = pow(b,a);
                char c4 = (char)(a + (int)'0');
                push(&st,c4);
                break;
            default:
                break;
            }
        }
    }
    int ans = pop(&st) - '0';
    return ans;
}
// ==================== Solve Function ====================
void solve() {
    char stri[50];
    printf("Enter infix expression: ");
    scanf("%s", stri);
    char post[100];
    postfix(stri, post);
    printf("Postfix expression: %s\n", post);
    int ans = evaluvation(post);
    printf("Answer : %d",ans);
}
/////////////////////////////////////////////////////////////////////////////////
// Author: ganesh B. KARTHIK
// Institute: IIIT Jabalpur
/////////////////////////////////////////////////////////////////////////////////

int main() {
    solve();
    return 0;
}