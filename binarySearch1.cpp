//implementation of binary search (random search of O( log n))
#include <stdio.h>
int binarySearch(int a[], int low, int high, int key){
	int mid, i;
	for(i=0; i<high; i++)
	   printf("%d ", a[i]);
	while(low <= high){
		mid = (low+high)/2;
		if(a[mid] == key)
		  return mid;
		if(key > a[mid] )
	  	  low = mid + 1;
		else if (key < a[mid])
	  		high = mid - 1;
   }
	
}
int main(){
	int n, i, key, result=0;
	
//	printf("\n Enter the array Size:\t");
//	scanf("%d", &n);
	
	int a[]={1,2,3,4,5};
	//key = 78;
	key=55;
	n = sizeof(a)/sizeof(a[0]);
	
//	printf("\n Enter any %d element to the array in ascending order:\t", n);
//	for(i=0; i<n; i++)
//	 scanf("%d", &a[i]);
	
	int ch=1;
	 while(ch){

	result = binarySearch(a, 0, n,key);
	
	printf("\n\n The element %d found at position %d", key, result+1);

	if(result == 0)
	  printf("\n\n The search key %d not found ", key);
	
	printf("\n Do you want to continue the search process (0 to exit):  ");
	scanf("%d", &ch);
  }

 }

