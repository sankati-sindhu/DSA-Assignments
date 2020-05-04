#include <stdlib.h> 
#include <stdio.h>

int comparator (const void * p1, const void * p2)
{
  return (*(int*)p1 - *(int*)p2);
}
int binarySearch(int arr[],int size,int search){
	int beg = 0, end = size-1, mid;
	while(beg<=end){
		mid = (beg+end)/2;
		printf("%d\n",arr[mid] );
		if(arr[mid] == search){ 
			return mid;
		}
		else if(arr[mid]>search){
			end = mid-1;
		}
		else beg = mid+1;
	}
	
	return -1;
}
int main ()
{
 	int arr[100], size, search, i, pos=-1, loc1, loc2;

	printf("\nEnter the size of the array(max 100)");
	scanf("%d",&size);

	printf("\nEnter elements in array\n");
	for(i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}

    qsort(arr, size, sizeof(int), comparator);
    printf("\nThe sorted array is: \n");

	for(i = 0; i < size; i++)
    {   
	printf("%d ", arr[i]);
	}
	
	printf("\nEnter search element");
	scanf("%d",&search);
	pos = binarySearch(arr, size, search);
	if(pos==-1) printf("Not found\n");
	else printf("\nthe %d search element is found at index %d\n",search,pos);
	printf("Enter two indexes\n");

	scanf("%d%d",&loc1,&loc2);
	printf("sum is %d\n",arr[loc1] + arr[loc2] );
	printf("product is %d\n",arr[loc1] * arr[loc2] );

  	
}