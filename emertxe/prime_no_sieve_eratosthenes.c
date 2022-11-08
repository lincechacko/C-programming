

#include <stdio.h>

int main()
{
	int n,m=2,new;
	float temp=0,sqrt;
	printf("enter the value of 'n'\n");
	scanf("%d",&n);
	if(n>1){
		int arr[n-1];
		for(int i=0;i<n-1;i++){
				arr[i]=m;
				m=m+1;
		}

		//sqrt=n/2;
		//while(temp!=sqrt){
		//temp=sqrt;
		//sqrt=(n/temp+temp)/2;
		//}

		//new=sqrt;
 
			for(int i=0;i<n;i++){
				
				for(int j=2;j*j<=n;j++){
				if(arr[i]%j==0 && arr[i]!=j){
				arr[i]=0;
				}
				}


		
		}
		    printf("The primes less than or equal to %d are : ",n);
			for(int i=0;i<n-1;i++){
			if(arr[i]!=0){
				printf("%d,",arr[i]);
			}
	}
	}
	else{
		printf("Please enter a positive number which is > 1");
	}
	return 0;
}
