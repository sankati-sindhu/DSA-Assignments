#include <stdio.h>


void displayAltSumPro(int arr[], int size){
	int i,sum=0,product=1;
	printf("Alternate elements\n");
	for(i=0;i<size;i++){
		if(i%2 != 0){
			product += arr[i];	
		}
		else{
			sum += arr[i];
			printf("%d ",arr[i]);
		}
	}
	printf("\nSum of the odd elements = %d\n",sum);
	printf("\nproduct of the even elements = %d\n",product);
}
void divM(int arr[], int size, int m){
	int i =0;
	printf("elements divisible by %d \n",m);
	for(i=0;i<size;i++){
		if(arr[i]%m == 0)
			printf("%d ",arr[i]);
	}
}
void bubbleSort(int arr[], int size) 
{ 
   int i, j,temp; 
   for (i = 0; i < size-1; i++)           
       for (j = 0; j < size-i-1; j++)  
           if (arr[j] > arr[j+1]){
	           	temp = arr[j];
	           	arr[j] = arr[j+1];
	           	arr[j+1] = temp;
           } 
    displayAltSumPro(arr,size);
   	divM(arr, size, m);
} 
int main()
{
	int arr[100], size, i, m;

	printf("\nEnter the size of the array(max 100)");
	scanf("%d",&size);

	printf("\nEnter elements in array\n");
	for(i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	printf("Enter the m\n" );
	scanf("%d",&m);
	bubbleSort(arr, size-1);
	return 0;
}