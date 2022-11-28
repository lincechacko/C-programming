#include <stdio.h>

void replace_blank(char []);

int main()
{
    char str[200];
    
    //printf("Enter the string with more spaces in between two words\n");
    scanf("%[^\n]", str);
    
    replace_blank(str);
    
    printf("%s\n", str);
}
void replace_blank(char ch[]){
char prev;
int len=0;
while(ch[len]!='\0'){
    len++;
}
	for(int i=0;i<len;i++){ 

    if(ch[i]== 32 && ch[i+1]== 32){

	for(int j=i;j<(len-1);j++){

	ch[j]=ch[j+1];
	}
	len--;	
	ch[len]='\0';
	i--;
	}
}
ch[len]='\0';
}
