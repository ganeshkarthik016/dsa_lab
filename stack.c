#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct stack{
    int data;
    struct stack* next;
};
void push(struct stack **header, int a){
  struct stack *node = (struct stack*)malloc(sizeof(struct stack));
  node->data = a;
  node->next = *header;
  *header = node;
}
void peek(struct stack *header){
    if(header == NULL){
        printf("The stack is empty\n");
    }
    else{
        printf("%d\n",header->data);
    }
}
void pop(struct stack **header){
    struct stack *temp;
    if (*header == NULL) {
        printf("The stack is empty\n");
        return;
    }
    temp = *header;
    *header = (*header)->next;
    free(temp);
}
int main(){
 struct stack *header = NULL;
 push(&header,10);
 push(&header,15);
 push(&header,5);
 push(&header,17);
 push(&header,13);
 pop(&header);
 peek(header);
  pop(&header);
 peek(header);

}