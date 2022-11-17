#include <stdio.h>

void squeeze(char [], char []);

int main()
{
    char str1[30], str2[30];
    
    printf("Enter string1:");
    scanf("%[^\n]", str1);
    getchar();

    printf("Enter string2:");
    scanf("%[^\n]", str2);
    
    squeeze(str1, str2);
    
    printf("After squeeze s1 : %s\n", str1);
    
}
void squeeze(char str1[],char str2[]){
int len1=0;
int len2=0;
while(str1[len1]!='\0'){
len1++;
}
while(str2[len2]!='\0'){
len2++;
}
for(int i=0;i<len2;i++){
for(int j=0;j<len1;j++){
if(str2[i]==str1[j]){
for(int k=j;k<(len1-1);k++){
str1[k]=str1[k+1];
}
len1--;
str1[len1]='\0';
j=0;
}

}

}
}
