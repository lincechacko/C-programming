#include<stdio.h> 
void swap(char *,char *);
void combination(char [],int ,int );
int my_strlen(char []);

int main()

{
        char str[100];
        int n;
        int res;
        printf("Enter a string: ");
        scanf("%100[^\n]",str);    
        n = my_strlen(str);
		if(n==0){
		return 0;
		}
        combination(str,0,n-1);                       
        return 0;
}

int my_strlen(char str[]){
int len=0;

while(str[len]!='\0'){
len++;
}
for(int i=0;str[i]!='\0';i++){
for(int j=0;str[j]!='\0';j++){
if(str[i]==str[j]&& i!=j){
printf("Error:please enter distinct character");
return 0;
}
}
}
return len;
}


void combination(char str[],int s,int l){

int i;
if(s>=l){
printf("%s\n",str);
}
else{
for(int i=s;i<=l;i++){
swap(str+s , str+i);
combination(str,s+1,l);
swap(str+s,str+i);
}
}
}


void swap(char *x , char *y){
char  temp;
temp=*x;
*x=*y;
*y=temp;
}
