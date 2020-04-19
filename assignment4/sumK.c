#include <stdio.h>
#include <limits.h>
#define  max 1000

typedef struct STACK
{
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


void display(stack *s){
	int i;
	for(i =s->top;i>-1;i--){
		printf("%d ",s->ar[i]);
	}
	printf("stack end\n");
}
void sumK(stack *s1, stack v, int k ){
	if (k==0){
		display(&v);
		return;
	}
	if(s1.top == 0) return;
	sumK(s1, n-1, v, k);
	stack v1 = v;
	int temp = s1->ar[n-1];
	push(&v1, temp);
	sumK(s1,n-1, v1, k-temp);
}
int main(int argc, char const *argv[])
{
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
	sumK(&arr,n, v, expected);
	return 0;
}





