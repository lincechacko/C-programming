#include <stdio.h>
#include <stdlib.h>
void magic_square(int,int **);

int main()
{
int num;	
printf("enter a number\n");
scanf("%d",&num);
if(num%2==0){
printf(" Error : Please enter only positive odd numbers");
return 0;
}
else{
int  **ptr;
ptr=calloc(num,sizeof(int *));
for(int i=0;i<num;i++){
*(ptr+i)=calloc(num,sizeof(int));
}
magic_square(num,ptr);
for(int i=0;i<num;i++){
for(int j=0;j<num;j++){
printf("%d  ",ptr[i][j]);
}
printf("\n");
}

return 0;
}
}

void magic_square(int num,int **ptr){
int i=0,j=num/2;
int sqr=num*num;

for(int k=1;k<=sqr;k++){
ptr[i][j]=k;
i=i-1;
j=j+1;

if(k%num==0){
i+=2;
--j;
}
else{
if(i==-1 && j==num){
i=0;
j=num-1;
}

else if(i==-1){
i=num-1;
}

else if(j==num){
j=0;
}

else if(ptr[i][j]!=0){
i=i+2;
j=j-1;
}
}
}
}

