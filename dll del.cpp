#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node*prev;
	struct node*next;
}*head = NULL,*tail = NULL,*newnode;

struct node*createnode(){
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("Enter data: ");
	scanf("%d",&newnode->data);
	newnode->prev = NULL;
	newnode->next = NULL;
   return newnode;
}
void display(){
	if(head==NULL){
		printf("List is empty");
	}
	struct node*temp = head;
	printf("List elements are: ");
	while(temp!=NULL){
		printf("%d<-> ",temp->data);
		temp = temp->next;
	}
	
}

void deleteAtBeginning(){
	if(head==NULL){
		printf("List is empty");
	}
	else{
		struct node*temp = head;
		head = head->next;
		head->prev = NULL;
		free(temp);
	}
	display();
}

void deleteAtEnd(){
	if(tail==NULL){
		printf("List is empty");
	}
	else{
		struct node*temp = tail;
		tail = tail->prev;
		tail->next = NULL;
		free(temp);

	}
	display();
}
void deleteAtPos(){
	if(head==NULL){
		printf("List is empty");
	}
	else{
		int pos;
		printf("Enter position: ");
		scanf("%d",&pos);
		struct node*temp = head;
		
		for(int i=0;i<pos-2;i++){
			temp = temp->next;
		}
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
			
	}
	display();
}

int main(){
	int ch1 = 1,ch2;
	struct node*nn;
	
	while(ch1==1){
		nn = createnode();
		if(head==NULL){
			head = tail = nn;
		}
		else{
			tail->next = nn;
			nn->prev = tail;
			tail = nn;
		}
		printf("do you want to continue adding nodes (1 or 0): ");
		scanf("%d",&ch1);
	}
	do{
		printf("1.delete at beginning\n");
		printf("2.delete at end\n");
		printf("3.delete at position\n");
		printf("Enter your choice: ");
		scanf("%d",&ch2);
		
		switch(ch2){
			case 1:   deleteAtBeginning();
			          break;
			          
			case 2:   deleteAtEnd();
			          break;
			  
			case 3:   deleteAtPos();
			          break;        
			default:  printf("Invalid choice");
		}
		printf("do you want to continue (1 or 0): ");
		scanf("%d",&ch1);
		
	}while(ch1==1);
	
}


