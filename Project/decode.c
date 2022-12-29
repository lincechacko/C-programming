/*
Name:Lince Kuruvila Chacko
date:
Description:
sample input:
sample output:
*/

#include <stdio.h>
#include "decode.h"
#include "types.h"
#include <string.h>
#include "common.h"
#include <stdlib.h>


Status read_and_validate_decode_args(char *argv[], DecodeInfo *decInfo)
{
	char *ptr;
	if(strstr(argv[2],".bmp"))
	{
		decInfo->d_src_image_fname=argv[2];

		if(argv[3]!=NULL)
		{
			ptr=strchr(argv[3],'.');
			decInfo->d_secret_fname=argv[3];
			return e_success;
		}
		else
		{
			decInfo->d_secret_fname="secretfile.txt";
			return e_success;
		}
	}
	else
	{
		return e_failure;
	}
}

Status open_files_dec(DecodeInfo *decInfo)
{

    decInfo->fptr_d_src_image = fopen(decInfo->d_src_image_fname, "r");

    
    if (decInfo->fptr_d_src_image == NULL)
    {
        perror("fopen");
        fprintf(stderr, "ERROR: Unable to open file %s\n", decInfo->d_src_image_fname);
        return e_failure;
    }
    
   /* decInfo->fptr_d_secret = fopen(decInfo->d_secret_fname, "w");

    
    if (decInfo->fptr_d_secret == NULL)
    {
        perror("fopen");
        fprintf(stderr, "ERROR: Unable to open file %s\n", decInfo->d_secret_fname);
        return e_failure;
    }*/

    return e_success;

}

Status decode_magic_string(DecodeInfo *decInfo)
{
fseek(decInfo->fptr_d_src_image,54,SEEK_SET);
int size;
size=strlen(MAGIC_STRING);
decInfo->magic_data=malloc(size+1);
decode_data_from_image(size,decInfo->fptr_d_src_image,decInfo);
decInfo->magic_data[size]='\0';
//printf("%s\n",decInfo->magic_data);
if(strcmp(decInfo->magic_data,MAGIC_STRING)==0)
{
	return e_success;
}
else
{
	return e_failure;
}

}

Status decode_data_from_image(int size,FILE *fptr_d_src_image,DecodeInfo *decInfo)
{
	char str[8];
	for(int i=0;i<size;i++)
	{
		fread(str,8,1,fptr_d_src_image);
		decode_byte_from_lsb(&decInfo->magic_data[i],str);
	}
	return e_success;
}

Status decode_byte_from_lsb(char *data,char *str)
{
    int bit = 7;
    unsigned char ch = 0x00;
    for (int i = 0;i < 8;i++)
    {
        ch = ((str[i] & 0x01) << bit) | ch;
        bit--;
    }
    *data = ch;
    return e_success;
}

Status decode_file_extn_size(int size,FILE *fptr_d_src_image,DecodeInfo *decInfo)
{
char str[32];
int size1;
fread(str,32,1,fptr_d_src_image);
decode_size_from_lsb(str,&size1);
if(size1==size)
{
	//printf("same size\n");
	decInfo->size_extn=size1;
	return e_success;
}
else
{
	printf("different size\n");
	return e_failure;
}
}

Status decode_size_from_lsb(char *str,int *size)
{
	int j=31;
	unsigned int num=0x00;
	for(int i=0;i<32;i++)
	{
	 num = ((str[i] & 0x01) << j--) | num;
	}
	*size=num;
}

Status decode_secret_file_extn(char *sec_ext,DecodeInfo *decInfo)
{
	//printf("%d",decInfo->size_extn);
	int size1=decInfo->size_extn;
	decInfo->d_extn_secret_file=malloc(size1+1);
	decode_extension_data_from_image(size1,decInfo->fptr_d_src_image,decInfo);
	decInfo->d_extn_secret_file[size1]='\0';
	//printf("%s",decInfo->d_extn_secret_file);
	open_file_1(decInfo);
	return e_success;
}
void open_file_1(DecodeInfo *decInfo)
{
    decInfo->fptr_d_secret = fopen(decInfo->d_secret_fname, "w");

    //Do Error handling
    if (decInfo->fptr_d_secret == NULL)
    {
        perror("fopen");
        fprintf(stderr, "ERROR: Unable to open file %s\n", decInfo->d_secret_fname);
       
    }
}

Status decode_extension_data_from_image(int size,FILE *src_image,DecodeInfo *decInfo)
{
    char str[8];	
	for(int i=0;i<size;i++)
	{
		fread(str,8,1,src_image);
        decode_byte_from_lsb(&decInfo->d_extn_secret_file[i],str);

	}
	return e_success;
}

Status decode_secret_file_size(int file_size,DecodeInfo *decInfo)
{
	char str[32];
	fread(str,32,1,decInfo->fptr_d_src_image);
	decode_size_from_lsb(str,&file_size);
	//printf("%d",file_size);
	decInfo->size_secret_file=file_size;
	return e_success;
}

Status decode_secret_file_data(DecodeInfo *decInfo)
{
	printf("%d",decInfo->size_secret_file);
	char ch;
	char str[8];
	for(int i=0;i<25/*decInfo->size_secret_file*/;i++)
	{
		fread(str,8,1,decInfo->fptr_d_src_image);
		decode_byte_from_lsb(&ch,str);
		fputc(ch,decInfo->fptr_d_secret);
	}
	return e_success;
}

Status do_decoding(DecodeInfo *decInfo)
{
	if(open_files_dec(decInfo)==e_success)
	{
		printf("Opening files Success\n");
		if(decode_magic_string(decInfo)==e_success)
		{
			printf("magic string decode success\n");
			if(decode_file_extn_size(4,decInfo->fptr_d_src_image,decInfo)==e_success)
			{
				printf("file extension size decoded\n");
				if(decode_secret_file_extn(decInfo->d_extn_secret_file,decInfo)==e_success)
				{
					printf("secret file extension decoded\n");
					if(decode_secret_file_size(decInfo->size_secret_file,decInfo)==e_success)
					{
						printf("secret file size decoded\n");

						if(decode_secret_file_data(decInfo)==e_success)
						{
							printf("secret file data decoded\n");
						}
						else
						{
							printf("secret file data decode failed\n");
						}
					}
					else
					{
						printf("secret file size decode failed\n");
					}
				}
				else
				{
					printf("secret file extension decoded failed\n");
				}
			}
			else
			{
				printf("file extension size decoded error\n");
			
			}
			
		}
		else
		{
			printf("magic string decode failure\n");
		}
	}
	else
	{
		printf("Opening files failed\n");
	}
}


