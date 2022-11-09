#include <stdio.h>

int sec_largest(int [], int);

int main()
{
    int size, ret;
    
    //Read size from the user
    printf("Enter the size of the array :");
    scanf("%d", &size);
    
    int arr[size];
    
    //Read elements into the array
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    //funtion call
    ret = sec_largest(arr, size);
    
    printf("Second largest element of the array is %d\n", ret);
}
int sec_largest(int *ptr, int size){
	int temp=*ptr;
	int temp1=*(ptr+1);
    for(int i=1;i<size;i++){
        if(temp < *(ptr+i)){
            temp=*(ptr+i);
        }
    }

for(int i=0;i<size;i++){
if(temp>temp1 && temp1 < *(ptr+i) && temp > *(ptr+i)){
temp1=*(ptr+i);
	
	}
}
return temp1;
}
