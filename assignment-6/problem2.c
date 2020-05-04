#include<stdio.h>
#define ms 100
int a[ms];
void merge(int l1,int u1,int l2,int u2)
{
  int i,j,k,temp[ms];
  k = 0;
  i = l1;
  j = l2;
  while((i<=u1)&&(j<=u2)){
    if(a[i]<a[j]){
      temp[k]=a[i];i++;k++;
    }
    else{
      temp[k]=a[j];j++;k++;
    }
  }
  while(i<=u1){
    temp[k]=a[i];i++;k++;
  }
  while(j<=u2){
    temp[k]=a[j];j++;k++;
   }
  for(i=l1, k=0;i<=u2;i++,k++){
    a[i]=temp[k];
  }
}
void mergesort(int lb,int ub){
  if(lb<ub)
  {
    int mid=(ub+lb)/2;
    mergesort(lb,mid);
    mergesort(mid+1,ub);
    merge(lb,mid,mid+1,ub);
  }
}
int main(){
  int i,n,product = 1,k; 

  printf("\n Enter the size of the array max(100) ");
  scanf("%d",&n);
  for(i = 0;i<n;i++){
     printf("a [%d ]\t = ",i);
     scanf("%d",&a[i]);
  }
  mergesort(0,n-1);
  printf("Enter K\n");
  scanf("%d",&k);
  for(i=0;i<k;i++){
     product *= a[i];
  }
  printf("\n The product till the k th element is %d\n",product);
  return 0;
}
