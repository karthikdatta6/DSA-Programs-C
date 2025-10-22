#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node*next;
}*head = NULL,*newnode;

static int ct = 0;

void createNode(){
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("Enter the value: ");
	scanf("%d",&newnode->data);
	newnode->next = NULL;
	ct++;
}
void display(){
	if(head==NULL){
		printf("List is empty\n");
	}
	else{
		struct node*temp = head;
		printf("elements in the list are: ");
		while(temp->next!=head){
			printf("%d->",temp->data);
			temp = temp->next;
		}
		printf("%d->%d",temp->data,head->data);
	}
}

void insertAtBeginning(){
	createNode();
	if(head==NULL){
		head = newnode;
		newnode->next = head;
	}
	else{
		struct node*temp = head;
		newnode->next = head;
		while(temp->next!=head){
			temp = temp->next;
		}
		temp->next = newnode;
		head = newnode;
	}
	display();
}

void insertAtEnd(){
	createNode();
	if(head==NULL){
		head = newnode;
		newnode->next = head;
	}
	else{
		struct node*temp = head;
		while(temp->next!=head){
			temp = temp->next;
		}
		temp->next = newnode;
		newnode->next = head;
	}
	display();
}

void insertAtPos(){
	
		int pos;
		printf("Enter the position to insert:");
		scanf("%d",&pos);
		
		if(pos==1){
			insertAtBeginning();
		}
		else if(pos==ct){
			insertAtEnd();
		}
		else{
			createNode();
			struct node*temp = head;
			for(int i=0;i<pos-1;i++){
				temp = temp->next;
			}
			newnode->next = temp->next;
			temp->next = newnode;
		}
	
	display();
}

int main(){
	int ch1=1,ch2;
	
	while(ch1){
		printf("1.insert at beginning\n");
		printf("2.insert at end\n");
		printf("3.insert at a position\n");
		scanf("%d",&ch2);
		
		switch(ch2){
			case 1:   insertAtBeginning();
			          break;
			          
			case 2:   insertAtEnd();
			          break;
			          
			case 3:   insertAtPos();
			          break;
			          
			default:  printf("Invalid choice");
			
		}
		
		printf("Do you want to continue(0 to end 1 to continue): ");
		scanf("%d",&ch1);
	}
}
