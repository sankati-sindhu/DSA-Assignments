#include <stdio.h> 
#include <stdlib.h> 

typedef struct Node { 
	int data; 
	struct Node* next; 
}node; 

typedef struct Queue { 
	node *front, *rear; 
}queue; 

node* newNode(int k) 
{ 
	node* temp = (node*)malloc(sizeof(node)); 
	temp->data = k; 
	temp->next = NULL; 
	return temp; 
} 

queue createQueue() 
{ 
	queue q;
	q.front = q.rear = NULL;
	return q; 
} 

void enQueue(queue *q, int k) 
{ 
	node* temp = newNode(k); 

	if (q->rear == NULL) { 
		q->front = q->rear = temp; 
		return; 
	} 
	q->rear->next = temp; 
	q->rear = temp; 
} 

void displayAlt(queue q){
	while(q.front != NULL){
		printf("%d ->->",q.front->data );
		if(q.front->next != NULL) q.front = q.front->next->next;
		else break;
	}
	printf("NULL\n");
}
void displayRev(queue q){
	if(q.front == NULL){
		printf("NULL");
		return;
	}
	int temp = q.front->data;
	q.front = q.front->next;
	displayRev(q);
	printf("<- %d",temp);
}
int main() 
{ 
	queue q = createQueue(); 
	int n, num;
	printf("enter the number of element you want in the queue\n");
	scanf("%d",&n);
	while(n--){
		printf("number\n");
		scanf("%d",&num);
		enQueue(&q, num);
	}
	
	displayRev(q);
	printf("\n");
	displayAlt(q);
	return 0; 
} 
