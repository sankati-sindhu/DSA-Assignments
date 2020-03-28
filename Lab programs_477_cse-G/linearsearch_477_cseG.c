#include <stdio.h>

int linearSearch(int arr[],int size,int search){

	int i;
	for(i=0;i<size;i++){
		if(search == arr[i]) return i;
	}
	return -1;
}

int main()
{
	int arr[100], size, search, i, pos;

	printf("\nEnter the size of the array(max 100)");
	scanf("%d",&size);

	printf("\nEnter elements in array\n");
	for(i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}

	printf("\nEnter search element");
	scanf("%d",&search);

	pos = linearSearch(arr, size, search);
	if(pos==-1) printf("Not found\n");
	else printf("\nthe %d search element is found at index %d\n",search,pos);

	return 0;
}