#include <stdio.h>
#include <stdlib.h>
float variance(int *, int);

int main()
{
    int size;
    printf("Enter the no.of elements\n");
	scanf("%d\n",&size);
    int *ptr=calloc(size,sizeof(int));
	for(int i=0;i<size;i++){
	scanf("%d",ptr+i);
	}
	variance(ptr,size);
	free(ptr);
	return 0;
}

float variance(int *ptr1,int size){
float mean;
int sum=0;
int sum1=0;
float var;
for(int i=0;i<size;i++){
sum=sum+ptr1[i];
}
mean=(float)sum/size;

for(int i=0;i<size;i++){
ptr1[i]=ptr1[i]-mean;
ptr1[i]=ptr1[i]*ptr1[i];
sum1=sum1+ptr1[i];
}
var=(float)sum1/size;
printf("Variance is %f",var);
}
