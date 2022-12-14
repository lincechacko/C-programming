#include <stdio.h>

int main()
{
	int size;
	char *ptr,temp;
	printf("enter the size\n");
	scanf("%d",&size);
    if(size==2){
	char temp;	
	short num;
	printf("Enter the number in Hexadecimal :\n");
	scanf("%hX",&num);
    ptr=(char *)&num;
	for(int i=0;i<size/2;i++){
	temp=ptr[i];
	ptr[i]=ptr[size-1];
	ptr[size-1]=temp;
	}
	printf("After conversion %hX",num);
	}
	else if(size==4){
	int num;
	printf("Enter the number in Hexadecimal :\n");
	scanf("%X",&num);
	ptr=(char *)&num;
	for(int i=0;i<size/2;i++){
	    temp=ptr[i];
		ptr[i]=ptr[size-i-1];
		ptr[size-i-1]=temp;

	}
	printf("After conversion %X",num);
	}
}
