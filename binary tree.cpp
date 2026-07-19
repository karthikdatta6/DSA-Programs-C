#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
	char data[3];
	struct Node*left;
	struct Node*right;
}*root = NULL;

struct Node*insert(){
	char val[3];
	struct Node*nn;
	printf("Enter the data to be inserted(-1 for no node): ");
	scanf("%s",&val);
	
	if(strcmp(val,"-1")==0){
		return NULL;
	}
	nn = (struct Node*)malloc(sizeof(struct Node));
	strcpy(nn->data,val);
	
	printf("Enter left child of %s: ",val);
	nn->left = insert();
	
	printf("Enter right child of %s: ",val);
	nn->right = insert();
	
	return nn;
	
}

void display(struct Node*root){
	if(root!=NULL){
		display(root->left);
		printf("%s",root->data);
		display(root->right);
	}
}

int main(){
	root = insert();
	printf("Traversal(inorder): ");
	display(root);
}
