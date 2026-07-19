//implementation of linear search (sequential search of O(n))
#include <stdio.h>

int main(){
	int n, i, key;
	
	printf("\n Enter the array Size:\t");
	scanf("%d", &n);
	
	int a[n];
	
	printf("\n Enter any %d element to the array:\t", n);
	for(i=0; i<n; i++)
	 scanf("%d", &a[i]);
	
	int ch=1;
	 while(ch){
	 
	//searching the key element linearly
	printf("\nEnter the key value to be searched:\t");
	scanf("%d", &key);
	
	for(i=0; i<n; i++)
	  if(key == a[i]){
	  	printf("\n The element %d found at position %d", key, i+1);
	  	break;
	  }
	  
	if(i>=n)
	  printf("\n The search key %d not found ", key);
	
	printf("\n Do you want to continue the search process (0 to exit):  ");
	scanf("%d", &ch);
  }
}
