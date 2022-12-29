#include <stdio.h>
#include "encode.h"
#include "types.h"
#include <string.h>
#include "common.h"
#include "decode.h"
int main(int argc , char *argv[])
{

	int option=check_operation_type(argv);

	if(option==e_encode){
	
		EncodeInfo encInfo;
		printf("selected encoding\n");
	    if((read_and_validate_encode_args(argv,&encInfo))==e_success)
		{
			printf("Read and validate is success\n");
			if(open_files(&encInfo)==e_success)
			{
				printf("Files opening success\n");

				if(check_capacity(&encInfo)==e_success)
				{
					printf("File capacity check success\n");
					if(copy_bmp_header(encInfo.fptr_src_image,encInfo.fptr_stego_image)==e_success)
					{
						printf("header copied successfully\n");
                        if(encode_magic_string(MAGIC_STRING,&encInfo)==e_success)
						{
							printf("Magic string copied succesfully\n");

							if(encode_secret_file_extn_size(strlen(encInfo.extn_secret_file),encInfo.fptr_src_image,encInfo.fptr_stego_image)==e_success)
							{
								printf("Secret file extention size encoded succesfully\n");

								if(encode_secret_file_extn(encInfo.extn_secret_file,&encInfo)==e_success)
								{
									printf("Secret file extention encoded successfully\n");

                                    if(encode_secret_file_size(encInfo.size_secret_file,&encInfo)==e_success)
	                                {
										printf("Secret file size encoded succesfully\n");
                                        //printf("%ld",encInfo.size_secret_file);
										if(encode_secret_file_data(&encInfo)==e_success)
										{
											printf("Secret file data encoded succesfully\n");

											if(copy_remaining_img_data(encInfo.fptr_src_image,encInfo.fptr_stego_image)==e_success)
											{
												printf("Reamaining data copied\n");
											}
											else
											{
												printf("ERROR\n");
											}

										}
										else
										{
											printf("ERROR\n");
										}
										
									}
									else
									{
										printf("error\n");
									}									
								}
								else
								{
									printf("error\n");
								}
								
							}
							else
							{
								printf("error\n");
							}
						}
						else
						{
							printf("Magic string copiying failed \n");
						}
					}
					else
					{
						printf("error\n");
					}
					

				}
			
				else
				{
					printf("File capacity check failed\n");
				}
				
			}
		}
		else
		{
			printf("Read and validation failed\n");
		}

	}
	else if(option ==e_decode)
	{
		DecodeInfo decInfo;
		printf("selected decoding\n");
		if(read_and_validate_decode_args(argv,&decInfo)==e_success)
		{
			printf("Read and validation success\n");
			do_decoding(&decInfo);
		}

	}
	else
	{
		printf("please pass the valid option");
	}

}

OperationType check_operation_type(char *argv[])
{
	
	if(!strcmp(argv[1],"-e"))
	{
      return e_encode;
	}
    
	else if(!strcmp(argv[1],"-d"))
	{
		return e_decode;
	}
	else
	{
		return e_unsupported;
	}

}
