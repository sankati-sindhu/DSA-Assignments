#include <stdio.h>
#include <stdlib.h>
#include "llio.h"
node* insertAtPos(node *head,int pos, int data){

	if(pos == 0){
		node *newNode = createNode(data);
		newNode->next = head;
		return newNode;
	}
	if(head == NULL){
		printf("error\n");
		return head;
	}
	head->next = insertAtPos(head->next, pos-1, data);
	return head;

}
node* deleteAtPos(node *head, int pos){
	if(pos == 0){
		return head->next;
	}
	if(head == NULL){
		printf("error\n");
		return head;
	}
	head->next = deleteAtPos(head->next, pos-1);
	return head;
}

int main()
{
	int data,n, k;
    node *head = createList();

    printf("\nenter n ,index of where you want to add a node");
    scanf("%d",&n);
    printf("\nenter data of the node");
    scanf("%d", &data);
    head = insertAtPos(head,n, data);
    printf("\nafter entering, list looks like\n");
    display(head);

    printf("\nenter k, index of where you want to delete a node\n");
    scanf("%d",&k);
    head = deleteAtPos(head, k);
    printf("\nafter deleting, list looks like\n");
    display(head);

	return 0;
}