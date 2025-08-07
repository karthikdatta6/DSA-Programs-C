#include <stdio.h>
#define MAX 25

int top = -1;

void push(int stack[], int val){
	if(top==MAX-1){
		printf("Stack is full.\n");
	}
	else{
		stack[++top] = val;
	}
}

int pop(int stack[]){
	if(top==-1){
		printf("Stack is empty\n");
	}
	else{
		int pv = stack[top];
		top--;
		return pv;
	}
}

int peek(int stack[]){
	if(top==-1){
		printf("Stack is empty\n");
	}
	else{
		printf("Top element is: %d\n",stack[top]);
	}
}

void display(int stack[]){
	int i=0;
	while(i<=top){
		printf("%d",stack[i]);
		i++;
	}
}

int main(){
	int stack[MAX], val;
	push(stack, 10);
	push(stack, 15);
	push(stack, 20);
	display(stack);
	printf("\n Display the values \n");
	pop(stack);
	display(stack);
	
}
