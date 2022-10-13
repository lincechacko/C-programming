#include <stdio.h>
#include <string.h>

/*
5 5 5 5 5 5 5 5 5 
5 4 4 4 4 4 4 4 5 
5 4 3 3 3 3 3 4 5 
5 4 3 2 2 2 3 4 5 
5 4 3 2 1 2 3 4 5 
5 4 3 2 2 2 3 4 5 
5 4 3 3 3 3 3 4 5 
5 4 4 4 4 4 4 4 5 
5 5 5 5 5 5 5 5 5
*/

#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    int start=0,end=0,len;
    scanf("%d", &n);
    len=2*n-1;
    end=len-1;
  	int a[len][len];
    while(n!=0){
       
       for(int i=start;i<=end;i++){
           for(int j=start;j<=end;j++){
               if(start==i||end==i||start==j||end==j){
                   a[i][j]=n;
               }
           }
       }
       start++;
       end--;
       n--;   
      }
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }  

    return 0;
}
