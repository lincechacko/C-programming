#include <stdio.h>

int iota(int num, char str[]);

int main()
{
	int num=0;
    char str[10];
    
    printf("Enter the number:");
    scanf("%d", &num);
    
    iota(num, str);
    
    printf("Integer to string is %s", str);
}
int iota(int num,char str[]){
int dig,res;
int temp;
int j=1;
int i=0;
int flag=0;
int len=0;
if(num<0){
num=num*-1;
flag=1;
str[0]='-';
while(num !=0){
dig=num%10;
temp=dig+48;
str[j]=temp;
j++;
num=num/10;
}
str[j]='\0';
}
else if(num>0){
while(num !=0){
dig=num%10;
temp=dig+48;
str[i]=temp;
i++;
num=num/10;
}
str[i]='\0';
}
else{
str[0]='0';
str[1]='\0';
}
while(str[len]!='\0'){
len++;
}
if(flag==1){
for(int i=1;i<=(len-1)/2;i++){
temp=str[i];
str[i]=str[len-i];
str[len-i]=temp;
}
}
else{
for(int i=0;i<len/2;i++){
temp=str[i];
str[i]=str[len-i-1];
str[len-i-1]=temp;
}


}
return j;
}
