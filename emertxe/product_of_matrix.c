#include <stdio.h>
#include <stdlib.h>

int matrix_mul(int **, int, int, int **, int, int, int **, int, int);

int main()
{
	int row1,col1,row2,col2;
	int **mat_a,**mat_b,**res;
    printf("enter number of rows\n");
    scanf("%d",&row1);
    printf("enter the number of columns :\n");
    scanf("%d",&col1);
	mat_a=calloc(row1,sizeof(int *));
	for(int i=0;i<row1;i++){
	*(mat_a+i)=calloc(col1,sizeof(int));
	}

printf("enter values of %d x %d matrix\n",row1,col1);
for(int i=0;i<row1;i++){
for(int j=0;j<col1;j++){
scanf("%d",&mat_a[i][j]);
}
}
printf("enter number of rows\n");
scanf("%d",&row2);
if(col1==row2){
printf("enter the number of column\n");
scanf("%d",&col2);
	mat_b=calloc(row2,sizeof(int*));
	for(int i=0;i<row2;i++){
	*(mat_b+i)=calloc(col2,sizeof(int));
	}
printf("enter values of %d x %d matrix\n",row2,col2);
for(int i=0;i<row2;i++){
for(int j=0;j<col2;j++){
scanf("%d",&mat_b[i][j]);
}
}



res=calloc(row1,sizeof(int*));
for(int i=0;i<row1;i++){
*(res+i)=calloc(row1,sizeof(int));
}

matrix_mul(mat_a,row1,col1,mat_b,row2,col2,res,row1,col2);
}
else{
printf("Matrix multiplication is not possible");
}
return 0;
}

int matrix_mul(int **mat1,int row1,int col1,int **mat2,int row2,int col2,int **res,int row,int col){

	int k;
	for(int i=0;i<row1;i++){
for(int j=0;j<col2;j++){
	for(k=0;k<col1;k++){
res[i][j]+=mat1[i][k]*mat2[k][j];
	}
}
}
printf("Product of two matrix :\n");
for(int i=0;i<row1;i++){
for(int j=0;j<col2;j++){
printf("%d   ",res[i][j]);
}
printf("\n");
}
}
