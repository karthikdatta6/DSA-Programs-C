#include <stdio.h>

void displaydata(int a[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d",a[i]);
		
	}
	printf("\n");
}

void insertionsort(int a[],int n){
	int i,j,temp;
	for(i=1;i<n;i++){
		
		temp = a[i];
	
		j = i;
	    
	    while(j>0&&a[j-1]>temp){
	    	a[j] = a[j-1];
	    	j--;
		}
		a[j] = temp;
}

int main() {
	int n;
	int a[] = {2,34,5,67,8};
	n = sizeof(a)/sizeof(a[0]);
	displaydata(a,n);
	insertionsort(a,n);
	displaydata(a,n);
	return 0;
}

