
#include <stdio.h>
int main()
{
	int num;
	printf("enter the number\n");
	scanf("%d",&num);
	for(int i=1;i<=num;i++){
		for(int s=1;s<=num-i;s++){
			printf("  ");
		}
		for(int j=1;j<=2*i-1;j++){
			printf("* ");
		}
	    printf("\n");	
	}
	for (int i=num-1;i>=1;i--){
		for(int s=1;s<=num-i;s++){
			printf("  ");
		}
		for(int j=1;j<=2*i-1;j++){
			printf("* ");
		}
		printf("\n");
	}
	return 0;
}
