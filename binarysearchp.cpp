#include <stdio.h>
int binarySearch(int a[],int low,int high,int key){
	int mid,i;
	for(i=0;i<high;i++){
		printf("%d",&a[i]);
	}
	
	while(low<=high){
		mid = (low+high)/2;
		
		if(a[mid]==key){
			return mid;
		}
		if(key>a[mid]){
			low = mid+1;
		}
		else if(key<a[mid]){
			high = mid-1;
		}
	}
}

int main(){
	int n,i,key,result = 0;
	
	int a[] = {1,2,3,4,5};
	key = 5;
	n = sizeof(a)/sizeof(a[0]);
	
	int ch=1;
	while(ch){
		int result = binarySearch(a,0,n,key);
		
		printf("\n Element %d found in %d position",key,result+1);
		
		if(result==0){
			printf("\n Element %d not found",key);
		}
		
		printf("\nDo you want to continue(0 for exit): ");
		scanf("%d",&ch);
	}
}
