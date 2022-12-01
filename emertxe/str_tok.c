#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>

char *my_strtok(char str[], const char delim[]);
int is_delim(char , char *);
int main()
{
    char str[50], delim[50];
    
    printf("Enter the string  : ");
    scanf("%s", str);
    
    __fpurge(stdout);
 
    printf("Enter the delimeter : ");
    scanf("\n%s", delim);
    __fpurge(stdout);
    
    char *token = my_strtok(str, delim);
    printf("Tokens :\n");
    
    while (token)
    {
        printf("%s\n", token);
        token = my_strtok(str, delim);
    }
}


char *my_strtok(char str[],const char delim[]){
static int backup=0;
int start;
start=backup;
int flag=0;
int flag1=0;


for(start;str[start]!='\0';start++){
for(int d=0;delim[d]!='\0';d++){
if(str[start]==delim[d]){
flag1=1;
break;
}
else{
flag1=0;
}
}
if(flag1==0){
backup=start;
break;
}
}


if(str[start]=='\0'){
return 0;
}

for(int i=start;str[i]!='\0';i++){
for(int j=0;delim[j]!='\0';j++){
if(str[i]==delim[j]){
str[i]='\0';
backup=i;
backup++;

for(int x=backup;str[x]!='\0';x++){
for(int y=0;delim[y]!='\0';y++){
if(str[x]==delim[y]){
	flag=1;
	break;
}
else{
flag=0;
}
}
if(flag==0){
backup=x;
return str+start;
}
}

}

}
backup++;
}

return str+start;
}
