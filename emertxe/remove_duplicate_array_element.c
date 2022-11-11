#include <stdio.h>

void fun(int arr1[], int size, int arr2[], int *new_size);

int main()
{
int size,new_size;
printf("enter the size of the array\n");
scanf("%d",&size);
new_size=size;
int arr1[size] , arr2[new_size];
for(int i=0;i<size;i++){
scanf("%d",&arr1[i]);
}
fun(arr1,size,arr2,&new_size);
printf("After removing duplicates: ");
for(int i=0;i<new_size;i++){
printf("%d ",arr2[i]);
}
printf("\n");
}

void fun(int arr1[], int size , int arr2[] , int *ptr3 ){
int count=0;
int k=0;
int flag=0;
for(int i=0;i<size;i++){
for(int j=0;j<i;j++){
if(arr1[i] != arr1[j]){
flag=0;
}
else{
	flag=1;
	break;
}
}
if(flag==0){
arr2[k]=arr1[i];
k=k+1;
count+=1;
}
}
*ptr3=count;
}
