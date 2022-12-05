#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>
int is_delim(char c, char *delim);
char *my_strtok(char *str, char *delim);
int main()
{
    char srcString[50] , delim[50];
    
    printf("Enter the string  : ");
    scanf("%s", srcString);
    
    __fpurge(stdout);
 
    printf("Enter the delimeter : ");
    scanf("\n%s", delim);
    __fpurge(stdout);
    
    char *token = my_strtok(srcString, delim);
    printf("Tokens :\n");
    
    while (token)
    {
        printf("%s\n", token);
        token = my_strtok(NULL, delim);
    }
    
    
    return 0 ;
}

char *my_strtok(char *str, char *delim)
{
    static char *backup;
    char *ret;

    if(!str)
    {
        str = backup;
    }


    while(1)
    {
        if(is_delim(*str, delim))
        {
            str++;
            continue;
        }
        if(*str == '\0')
        {
            return NULL; 
        }
        break;
    }
    
    ret = str;
    
    while(1)
    {
        if(*str == '\0')
        {
          
            backup = str;
            return ret;
        }
        if(is_delim(*str, delim))
        {
            *str = '\0';
            backup = str + 1;
            return ret;
        }
        str++;
    }
}



 int is_delim(char c, char *delim)
{
    while(*delim != '\0')
    {
        if(c == *delim)
            return 1;
        delim++;
    }
    return 0;
}
