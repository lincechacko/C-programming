/*
Name:Lince Kuruvila Chacko
date:
Description:
sample input:
sample output:
*/

#include <stdio.h>
#include <stdlib.h>
int main_menu(void){

	int res;
	printf("Menu :\n1.Add element\n2.Remove element\n3.Display elements\n4.Exit from the program\n");
	scanf("%d",&res);
	return res;
}
		

int main()
{
	void *ptr=malloc(8);
	int input,choice,val,index;
	char char1,char2;
	int char1_flag=0,char2_flag=0,int_flag=0,float_flag=0,short_flag=0,double_flag=0,flag_int=0,flag_float=0;
	float flvalue;
	double dlvalue;
	short shvalue;
menu:
	input=main_menu();

	if(input==1){	

		printf("Enter the type you have to insert:\n1.int\n2.char\n3.float\n4.double\n5.short\n");
        scanf("%d",&choice);
		if(choice==1){
	     
			if(int_flag==0){
				printf("enter the integer\n");
				scanf("%d",&val);
			*((int*)ptr+1)=val;
			int_flag=1;
			float_flag=1;
			flag_int=1;
			}
			else if(int_flag==1){
				printf("integer already existed\n");
				goto menu;
			}
		}
	
	else if(choice==2){
	
		if(char1_flag==0){
		    printf("enter the character\n");
			getchar();
			scanf("%c",&char1);
			*((char *)ptr+0)=char1;
			char1_flag=1;
			goto menu;
		}
		
		else if(char2_flag==0){
		printf("enter the character\n");
		getchar();
		scanf("%c",&char2);
		*((char*)ptr+1)=char2;
		char2_flag=1;
		goto menu;
		}
		else if(char1_flag==1 && char2_flag==1){
		
			printf("character already existed\n");
			goto menu;
		}
	}
	else if(choice==3){
	
		if(float_flag==0){
		
			printf("enter the float value\n");
			scanf("%f",&flvalue);
			*((float *)ptr+1)=flvalue;
			float_flag=1;
			int_flag=1;
			flag_int=1;
			goto menu;
		}
		else if(float_flag==1){
		
			printf("float value already existed\n");
				goto menu;
		}
		
	}
	else if(choice==4){
		
			if(double_flag==0 && float_flag==0 && short_flag==0 && int_flag==0 && char1_flag==0 && char2_flag==0){
			
				printf("enter the double value\n");
				scanf("%lf",&dlvalue);
				*((double *)ptr)=dlvalue;
				double_flag=1;
				goto menu;
			}
			else if(double_flag==1 || int_flag==1 || char1_flag==1 || char2_flag==1 || float_flag==1 || short_flag==1){
			
				printf("double space already occupied \n");
				goto menu;
			}
		}

		else if(choice==5){
		
			if(short_flag==0){
			
				printf("enter the short value\n");
				scanf("%hd",&shvalue);
				*((short *)ptr+1)=shvalue;
				short_flag=1;
				goto menu;
			}
			else if(short_flag==1){
			
				printf("short value already existed\n");
				goto menu;
			}
		}
}


else if(input==2){

	 
	if(double_flag==1){
	
		printf("0.double %lf \n",*((double *)ptr));
	}
	if(char1_flag==1){
	
		printf("0.character %c \n",*((char*)ptr+0));
	}
	if(char2_flag==1){
	
		printf("1.character %c \n",*((char*)ptr+1));
	}
	if(short_flag==1){
	    printf("2.short %hd\n",*((short *)ptr+1));
	}
	if(int_flag==1 && flag_int==1){
	
		printf("3.integer %d\n",*((int *)ptr+1));
	}
	if(float_flag==1 && flag_float==1){
	
		printf("3.float %f \n",*((float*)ptr+1));
	}

		printf("Enter the index value to be deleted");
		scanf("%d",&index);

		if(index==0){
		
			if(double_flag==1){
			*((double*)ptr)=0;
			double_flag=0;
			}
			else if(char1_flag==1){
			*((char*)ptr)='0';
			char1_flag=0;
			}
		}
		else if(index==1){
			
				*((char*)ptr+1)='0';
				char2_flag=0;
		}
		else if(index==2){
		
			*((short *)ptr+1)=0;
			short_flag=0;
		}

		else if(index==3){
		
			if(int_flag==1 && flag_int==1){
			
				*((int *)ptr+1)=0;
				int_flag=0;
				flag_int=0;
				float_flag=0;
				float_flag=0;
			}
			else if(float_flag==1 && flag_float==1){
			
				*((float *)ptr+1)=0;
				int_flag=0;
				flag_int=0;
				float_flag=0;
				flag_float=0;
			}
		}


}

else if(input==3){

	if(double_flag==1){
	
		printf("0.double %lf \n",*((double *)ptr));
	}
	if(char1_flag==1){
	
		printf("0.character %c \n",*((char*)ptr+0));
	}
	if(char2_flag==1){
	
		printf("1.character %c \n",*((char*)ptr+1));
	}
	if(short_flag==1){
	    printf("2.short %hd\n",*((short *)ptr+1));
	}
	if(int_flag==1 && flag_int==1){
	
		printf("3.integer %d\n",*((int *)ptr+1));
	}
	if(float_flag==1 && flag_float==1){
	
		printf("3.float %f \n",*((float*)ptr+1));
	}
	
	}

else if(input==4){
return 0;
}
	goto menu;
}
