#include <stdio.h>
void merge(int [], int, int, int);
void merge_sort (int a[], int l, int r )
{
	int mid;
	if (l != r) {
		mid = (l+r)/2;
		merge_sort (a, l, mid);//left sub-array
		merge_sort (a, mid+1, r);//right sub-array
		merge (a, l, mid, r);//merge the partitioned array and sort 
	}
}
void merge (int a[], int low, int mid, int high)
{
	int i, j, k, left, right, result[20];
	left = low;
	right = mid+1;
	i = low;
	while (left <= mid && right <= high) {
		if (a [left] <= a[right] && a[left] != 0) {
			result[i] = a[left];
			left++;
				}
		else {
			result[i] = a[right];
			right++;
			}
		i++;
	 }
		while (left <= mid){
			result[i] = a[left];
			left++;
			i++;
		}
		while (right <= high) {
			result[i] = a[right];
			right++;
			i++;
		}
		for (i=low; i<=high; i++){
		 a[i] = result[i];
	 	}
	}
int main () {
	int a [] = {4,12, 5,1}, n, i;
	merge_sort (a, 0, 3);
	for(i=0;i<4;i++)
		printf ("%d ", a[i]);
}

