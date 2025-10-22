#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node*next;
}*head = NULL,*newnode;

static int ct = 0;

struct node*createnode(){
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data: ");
	scanf("%d",&newnode->data);
	newnode->next = NULL;
	ct++;
    return newnode;
	
}

void display(){
	if(head==NULL){
		printf("List is empty\n");
	}
	struct node*temp = head;
	printf("Elements are: ");
	while(temp!=NULL){
		printf("%d",temp->data);
		temp = temp->next;
	}
}

void insertAtBeginning(){
	createnode();
	if(head==NULL){
		head = newnode;
	}
	else{
		newnode->next = head;
		head = newnode;
	}
	display();
}

void insertAtEnd(){
	createnode();
	if(head==NULL){
		head = newnode;
	}
	else{
		struct node*temp = head;
		while(temp->next!=NULL){
			temp = temp->next;
		}
		temp->next = newnode;
		newnode->next = NULL;
	}
	display();
}

void insertAtPos(){
	int pos;
	printf("Enter position: ");
	scanf("%d",&pos);
	
	if(pos==1){
		insertAtBeginning();
	}
	else if(pos==ct){
		insertAtEnd();
	}
	else{
		createnode();
		struct node*temp = head;
		for(int i=0;i<pos-2;i++){
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
		printf("1.Insert at beginning\n");
		printf("2.Insert at End\n");
		printf("3.Insert at position");
		printf("Enter your choice: ");
		scanf("%d",&ch2);
		
		switch(ch2){
			case 1:   insertAtBeginning();
			          break;
			          
			case 2:   insertAtEnd();
			          break;
			          
			case 3:   insertAtPos();
			          break;
			          
			default: printf("Invalid choice");
		}
		printf("Do you want to continue(1 or 0): ");
		scanf("%d",&ch1);
	}
}
