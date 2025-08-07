#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node*next;
};

struct node*top = NULL;

void push(int val){
	struct node*nn = (struct node*)malloc(sizeof(struct node));
	if(nn==NULL){
		printf("Memory allocation failed.\n");
		
	}
	nn->data = val;
	nn->next = top;
	top = nn;
}

int pop(){
	if(top==NULL){
		printf("Stack underflow\n");
	}
	struct node*temp = top;
	int pv = temp->data;
	top = top->next;
	free(temp);
	return pv;
}

int peek(){
	if(top==NULL){
		printf("Stack underflow\n");
	}
	else{
		printf("Top element is:%d\n",top->data);
	}
	
}
	
void display(){
	struct node*temp = top;
	printf("Stack elements are: ");
	while(temp!=NULL){
		printf("%d",temp->data);
		temp = temp->next;
	}
}
int main(){
	push(10);
	push(20);
	push(30);
	
	printf("Initial stack:");
	display();
	
	peek();
	
	printf("Values after pop operation: \n");
	pop();
	
	display();
	
	return 0;
}

