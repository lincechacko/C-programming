#include <stdio.h>

int main()
{
	int num,t1=0,t2=1,next_term=0; //initialising the variables
	printf("enter the number\n"); 
	scanf("%d",&num); //taking the input 
	if(num>=0){ //checking wheather the input is positive

	while(next_term<=num) //while the next term is less than input number the while loop will run
	{
		printf("%d ",next_term); //printing the nextterm
		t1=t2; //second term is given to first term
		t2=next_term; //next term is given to second term
		next_term=t1+t2; //next term will be the sum of first and second term
	}
	}else{
		printf("Invalid input");}
	return 0;
}
