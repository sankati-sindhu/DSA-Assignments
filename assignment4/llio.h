#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next; 

}node;

node* createNode(int data){
    node *n = ((node*)malloc(sizeof(node)));
    n->data = data;
    n->next = NULL;
    return n;
}
node* createList()
{
    int n,data;
    node  *p, *head = NULL;

    printf("\n How many elements to enter?");
    scanf("%d", &n);
    while(n--){
        printf("Enter a number\n");
        scanf("%d",&data);
        if(head == NULL){
            head = createNode(data);
            p = head;
        }
        else{
        p->next = createNode(data);
        p = p->next;
        }
    }
    return head;
    
}
void display(node *head){
    while(head!=NULL){
        printf("%d->",head->data);
        head = head->next;
    }
    printf("NULL\n");
}
