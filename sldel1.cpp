#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node*next;
}*head = NULL;

static int ct = 0;

void display(){
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    struct node*temp = head;
    printf("Elements are: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void DeleteAtBeginning(){
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    struct node*temp = head;
    head = head->next;
    free(temp);
    ct--;
    display();
}

void DeleteAtEnd(){
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    if(head->next==NULL){   // only one node
        free(head);
        head = NULL;
    } else {
        struct node*temp = head;
        struct node*tail = NULL;
        while(temp->next!=NULL){
            tail = temp;
            temp = temp->next;
        }
        tail->next = NULL;
        free(temp);
    }
    ct--;
    display();
}

void DeleteAtPos(){
    int pos;
    printf("Enter position: ");
    scanf("%d",&pos);

    if(pos < 1 || pos > ct){
        printf("Invalid position\n");
        return;
    }

    if(pos==1){
        DeleteAtBeginning();
    }
    else{
        struct node*temp = head;
        struct node*tail = NULL;
        
        for(int i=0; i<pos-1; i++){  // move to that position
            tail = temp;
            temp = temp->next;
        }
        tail->next = temp->next;
        free(temp);
        ct--;
        display();
    }
}

int main(){
    int ch1=1,ch2;
    while(ch1){
        printf("\n--- MENU ---\n");
        printf("1.Delete at beginning\n");
        printf("2.Delete at End\n");
        printf("3.Delete at position\n");
        printf("Enter your choice: ");
        scanf("%d",&ch2);
        
        switch(ch2){
            case 1:   DeleteAtBeginning(); break;
            case 2:   DeleteAtEnd(); break;
            case 3:   DeleteAtPos(); break;
            default:  printf("Invalid choice\n");
        }
        printf("Do you want to continue(1 or 0): ");
        scanf("%d",&ch1);
    }
}

