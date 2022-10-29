#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int count=0,count1=0,count2=0,count3=0,count4=0,count5=0,count6=0,count7=0,count8=0,count9=0,len;
    char str[1000];
    scanf("%s",&str);
    //printf("%s",str);
    len=strlen(str);
    for(int i=0;i<len;i++){
        
        if(str[i]=='0'){
            count+=1;
        }
        
        else if(str[i]=='1'){
            count1+=1;
        }
        
        else if(str[i]=='2'){
            count2+=1;
        }
        
        else if(str[i]=='3'){
            count3+=1;
        }
        
        else if(str[i]=='4'){
            count4+=1;
        }
        
        else if(str[i]=='5'){
            count5+=1;
        }
        
        else if(str[i]=='6'){
            count6+=1;
        }
        
        else if(str[i]=='7'){
            count7+=1;
        }
        
        else if(str[i]=='8'){
            count8+=1;
        }
        
        else if(str[i]=='9'){
            count9+=1;
        }
        
    }  
    printf("%d %d %d %d %d %d %d %d %d %d",count,count1,count2,count3,count4,count5,count6,count7,count8,count9);    
    return 0;
}
