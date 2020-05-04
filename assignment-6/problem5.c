#include <stdio.h>

int binarySearch(int arr[],int beg,int end,int search){

	int mid;
	if(beg<=end){
		mid = (beg+end)/2;
		if(arr[mid] == search) return mid;
		if(arr[mid]>search){
			return binarySearch(arr,beg,mid-1,search);
		}
		return binarySearch(arr,mid+1,end,search);	
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

	pos = binarySearch(arr, 0, size-1, search);
	if(pos==-1) printf("Not found\n");
	else printf("\nthe %d search element is found at index %d\n",search,pos);
	
	return 0;
}