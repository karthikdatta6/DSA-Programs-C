#include <stdio.h>
#include <string.h>
#define MAX 20

int top = -1;
int stack[MAX];

void push(char ch){
	if(top == MAX-1)
	   printf("\nStack Overflow");
	else
		stack[++top]=ch;
}

void pop(){
	if(top == -1)
	   printf("\nStack Underflow");
	else
		printf("%c", stack[top--]);
}

int main(){
	int i=0;
	char str1[20];
	printf("Enter the string: ");
	gets(str1);
	
	//n=sizeof(str1)/sizeof(str1[0]);
	while(str1[i] != '\0'){
		push(str1[i]);
		i++;
	}
	
	while(top != -1){
		pop();
	}
}
