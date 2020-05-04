#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 100
int top = -1;
char infix[size], postfix[size], stack[size];

int precedence(char ch){
	switch(ch){
		case '^': return 5;
		case '*': return 4;
		case '/': return 4;
		case '+': return 3;
		case '-': return 3;
		default : return 0;
	}
}

char pop(){

	if(top == -1)
		return '#';
	char res = stack[top];
	top--;
	return res;

}
char topEle(){
	if(top == -1){
		return '#';
	}
	return stack[top];
}
void push(char data){
	if(top == size-1)
		printf("overflow\n");
	top++;
	stack[top] = data;
}

int main()
{
	char ele, elem, st[2];
	int prep, pre, popped, j=0,i;
	strcpy(postfix," ");
	printf("assumtion: in format ([expression](operator)[expression]) example a+(b*c)\nwhere a valid expression is a single variable\nor (variable <operator> variable)\n");
	printf("enter infix expression");
	gets(infix);
	for( i = 0; infix[i] != '\0'; i++){
		if(infix[i]!= '(' && infix[i] != ')' && infix[i] != '^' && infix[i] != '*'
			&& infix[i] != '/' && infix[i]!= '+' && infix[i] != '-') postfix[j++] = infix[i];
		else if(infix[i] == '('){
			elem = infix[i];
			push(elem);
		}
		else if(infix[i] == ')'){
			while((popped = pop()) != '(') postfix[j++] = popped;
		}
		else{
			elem = infix[i];
			pre = precedence(elem);
			ele = topEle();
			prep = precedence(ele);
			if(pre > prep ) push(elem);
			else{
				while(prep >= pre){
					if (ele == '#'){
						break;
					}
					ele = topEle();
					postfix[j++] = popped;
					prep = precedence(ele);
				}
				push(ele);
			}
		}
	}
	while((popped = pop()) != '#') postfix[j++] = popped;
	postfix[j] = '\0';
	printf("post fix %s \n",postfix);
	return 0;
}