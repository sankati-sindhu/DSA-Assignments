#include <stdio.h>

int binarySearch(int arr[],int size,int search){

	int beg = 0, end = size-1, mid;
	while(beg<=end){
		mid = (beg+end)/2;
		if(arr[mid] == search) return mid;
		else if(arr[mid]>search){
			end = mid-1;
		}
		else beg = mid+1;
	}
	
	return -1;
}

int main()
{
	int arr[100], size, search, i, pos;

	printf("\nEnter the size of the array(max 100)");
	scanf("%d",&size);

	printf("\nEnter sorted elements in array\n");
	for(i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}

	printf("\nEnter search element");
	scanf("%d",&search);

	pos = binarySearch(arr, size, search);
	if(pos==-1) printf("Not found\n");
	else printf("\nthe %d search element is found at index %d\n",search,pos);
	
	return 0;
}