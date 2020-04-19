#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define  max 1000

typedef struct STACK{
	int ar[max];
	int top;
}stack;

void push(stack *s, int data){
	if(s->top >= max-1){
		exit(0);
	}
	s->top++;
	s->ar[s->top] = data;
}
int pop(stack *s){
	if(s->top < 0) return INT_MIN;
	int temp = s->ar[s->top];
	s->top--;
	return temp;
}

void display(stack s){
	int i;
	for(i =s.top;i>-1;i--){
		printf("%d ",s.ar[i]);
	}
	printf("\n");
}
void sumK(stack s1, stack v, int k ){
	if (k==0){
		display(v);
		return;
	}
	if(s1.top == -1) return;
	int temp = pop(&s1);
	sumK(s1, v, k);
	stack v1 = v;
	push(&v1, temp);
	sumK(s1,v1, k-temp);
}
int main(int argc, char const *argv[]){
	stack arr, v;
	arr.top = -1;
	v.top = -1;
	int expected,n,num;
	printf("enter the number of element you want in the stack\n");
	scanf("%d",&n);
	while(n--){
		printf("number\n");
		scanf("%d",&num);
		push(&arr, num);
	}
	printf("enter expected value\n");
	scanf("%d",&expected);
	n = arr.top+1;
	sumK(arr, v, expected);
	return 0;
}





