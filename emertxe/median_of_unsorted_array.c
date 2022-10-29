/*
Name:
date:
Description:
sample input:
sample output:
*/

#include <stdio.h>

int main()
{

	int n,m,temp,n1,n2;
	float temp1,temp2,temp3,med2,med,med1;
	printf("enter n value of array A\n");
	scanf("%d",&n);
	printf("enter m value of array B\n");
	scanf("%d",&m);
	int arr1[n],arr2[m];

	printf("enter the element of array A \n");
	for(int i=0;i<n;i++){
		scanf("%d",&arr1[i]);
	}

	printf("enter the element of array B \n");
	for(int i=0;i<m;i++){
		scanf("%d",&arr2[i]);
	}
    
    for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr1[j]>arr1[j+1]){
				temp=arr1[j];
				arr1[j]=arr1[j+1];
				arr1[j+1]=temp;

			}

		}

	}

    for(int i=0;i<m-1;i++){
		for(int j=0;j<m-i-1;j++){
			if(arr2[j]>arr2[j+1]){
				temp=arr2[j];
				arr2[j]=arr2[j+1];
				arr2[j+1]=temp;
			}
		}
	}

    if(n%2){
		temp=n/2;
		med1=arr1[temp];
		printf("Median of array1 : %g\n",med1);
	}
	else{
		n1=n/2;
		n2=(n/2)-1;
		temp1=arr1[n1];
		temp2=arr1[n2];
		temp3=(temp1+temp2)/2;
		med1=temp3;
		printf("Median of array1 : %g\n",med1);
	}
	
	
    if(m%2){
		temp=m/2;
		med2=arr2[temp];
		printf("Median of array2 : %g\n",med2);
	}
	else{
		n1=m/2;
		n2=(m/2)-1;
		temp1=arr2[n1];
		temp2=arr2[n2];
		temp3=(temp1+temp2)/2;
		med2=temp3;
		printf("Median of array2 : %g\n",med2);
	}
	med=(med1+med2)/2;
    printf("Median of both arrays :  %g",med);
	return 0;
}
