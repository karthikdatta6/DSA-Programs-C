//program to Insert node at different positions in a double linked list
#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *prev;
	struct node *next;
}*head, *temp, *tail, *newnode;
static int ct=0;
//to create a node and set its value and pointer to null
struct node* createNewNode(){
	newnode = (struct node*) malloc(sizeof(struct node));
	 printf("Enter the data:\t");
	 scanf("%d", &newnode->data);
	 newnode->next = NULL;
	 newnode->prev = NULL;
	 ct++;
  return newnode;	 
}

void display(){
	temp = head;
			printf("\nThe elements in the list are:\n");
			while(temp != NULL){
				printf("%d <->", temp->data);
				temp = temp->next;
			}
			printf("null\n");
}

int main(){
	struct node *nn;
	int i, pos, ch1;
	head = NULL;
	char ch='Y';
	while(ch=='Y' || ch=='y'){
		nn=createNewNode();
	 if(head == NULL){
	 	head = tail = nn;
	 }
	 else{
	 	tail->next = nn;//linking to the next node
	 	nn->prev = tail;//linking to the prev node
	 	tail = nn;//and making last node(i.e newnode) as tail node
	 }
	 printf("Do you want to add a node(Y/N): ");
	 scanf(" %c", &ch);
	}
	
	ch='Y';
	
	while(ch=='Y' || ch=='y'){
	printf("1. Insert node at the begining\n");
	printf("2. Insert node at the given position\n");
	printf("3. Insert node at the end of the list.\n");
	scanf("%d", &ch1);
	
	
	switch (ch1){
		
	case 1: 	nn=createNewNode();
				if(head!=NULL){
					nn->next =head;
					head->prev = nn;
					head = nn;
				display();
				}
			break;
	case 2:  //Insert at the given position
	        nn = createNewNode();
	 		temp=head;
	 		printf("\nEnter the position to insert new node:\t");
	 		scanf("%d", &pos);
	 		if(pos<=ct){
			 
			 for(i =0; i<pos-2; i++){
			 	if(temp->next != NULL){
			 		temp = temp->next;
				 }
			 }
			  newnode->next = temp->next;
        	  newnode->prev = temp;

       			 if (temp->next != NULL)
       			     temp->next->prev = newnode;

     		   temp->next = newnode;
	           display();      
		  }
		  else{
		  	printf("\nNot a valid position, \nPosition shoud be between 0-%d",ct-1);
		  }
	        break;
	case 3: //to insert node at the end of the list
	        nn = createNewNode();
	       	tail->next = newnode;
	       	newnode->prev = tail;
	       	tail = newnode;
	        display();
	        break;
	default: printf("\nInvalid choice");
	    
	}
	 printf("\n\nDo you want to continue insert operation(Y/N): ");
	 scanf(" %c", &ch);
	}
	
	free(head);
	free(newnode);
	free(temp);
}
