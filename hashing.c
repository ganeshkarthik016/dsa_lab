#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct entry_t {
    int id;
    char name[20];
    struct entry_t *next;
} entry_t;
entry_t *hasht[MAX_SIZE]={NULL};

int hash(int key){
   return key%MAX_SIZE;
}
void append(int key,char val[])
{
    entry_t *temp = hasht[hash(key)];
    while(temp->next!=NULL) temp = temp->next;
    entry_t *new=malloc(sizeof(entry_t));
    new->id=key;
    strcpy(new->name,val);
    new->next=NULL;
    temp->next = new;
    return;
}
// void append(int key, char val[])
// {
//     int h = hash(key);

//     // If bucket empty, create first node
//     if (hasht[h] == NULL) {
//         entry_t *node = malloc(sizeof(entry_t));
//         node->id = key;
//         strcpy(node->name, val);
//         node->next = NULL;
//         hasht[h] = node;
//         return;
//     }

//     entry_t *temp = hasht[h];

//     while (temp->next != NULL)
//         temp = temp->next;

//     entry_t *node = malloc(sizeof(entry_t));
//     node->id = key;
//     strcpy(node->name, val);
//     node->next = NULL;
//     temp->next = node;
// }

void printll(entry_t *hasht)
{
    entry_t *temp =hasht;
    while(temp!=NULL)
    {
        printf("\n id : %d \n",temp->id);
        printf("\n name : %s \n",temp->name);
        temp = temp->next;
    }
    return;


}
void create_hash(int key,char val[]){
    if(hasht[hash(key)]==NULL)
    {
        entry_t *new=malloc(sizeof(entry_t));
    new->id=key;
    strcpy(new->name,val);
    new->next=NULL;
    hasht[hash(key)] = new;
    }
    else
    append(key,val);
}
int main(){
    for(int i=0;i<5;i++)
    {
        int id;
        char val[20];
        printf(" id : ");
        scanf("%d",&id);
        printf("\nname\n");
        scanf("%s",val);
        create_hash(id,val);
    }
    for(int i=0;i<10;i++)
    {
        if(hasht[i]!=NULL)
        {
            printll(hasht[i]);
        }
    }


}