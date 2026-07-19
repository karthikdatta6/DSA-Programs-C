//program to Insert node at different positions
#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *next;
}*front=NULL, *rear, *newnode;

//to create a node and set its value and pointer to null
struct node* createNewNode(){
	newnode = (struct node*) malloc(sizeof(struct node));
	 printf("Enter the data:\t");
	 scanf("%d", &newnode->data);
	 newnode->next = NULL;
  return newnode;	 
}

void display(){
	struct node *temp = front;
			if(front==NULL)
			 printf("\nQueue underflow/ Queue is empty");
			while(temp != NULL){
				printf("%d->", temp->data);
				temp = temp->next;
			}
}

void enqueue(){ //insertAtEnd
		createNewNode();
	 if(front == NULL){
	 	front = rear = newnode;
	 }
	 else{
	 	rear->next = newnode;
	 	rear = newnode;
	 }
	 
}

void dequeue(){//deleteAtBegining() 
  if(front==NULL)
    printf("\nQueue underflow");
  else{
  	struct node *temp =front;
  	printf("\n The value removed from the list is %d", front->data);
  	front = front ->next;
  	free(temp);
  }

}

int main(){

	int ch=1;
	while(ch){
		printf("1. Enqueue\n2. Dequeue\n3. Exit\n\nEnter your choice:\t");
		scanf("%d", &ch);
		
	 switch(ch){
	    case 1: enqueue(); display() ;break;
	    case 2: dequeue();  display();break;
        case 3: exit(1);
        default: printf("\nInvalid choice");   
	  }
	 printf("\n\nDo you want to continue (0 for no): ");
	 scanf(" %d", &ch);
	}
	
	free(front);
	free(newnode);
	free(rear);
}
