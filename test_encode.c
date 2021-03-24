#include <stdio.h>
#include <string.h>
#include "encode.h"
#include "decode.h"
#include "types.h"

int main(int argc, char **argv)
{
    /* Check if user is opted for Encoding or Decoding*/
    if (check_operation_type(argv) == e_encode) // if encoding enter
    {
        printf("Chosen Encoding\n");
        EncodeInfo encInfo; // Declare struct variable
        if (read_and_validate_encode_args(argv, &encInfo) == e_success) //Test check_operation_type and read_and_validate_encode_args
        {
            printf("Read and Validate is successful\n");
            printf("Start encoding\n");
            if (do_encoding(&encInfo) == e_success)
            {
                printf("Completed Encoding\n");
            }
            else
            {
                printf("Encoding was a Failure\n");
                return 1;
            }
        }
        else
        {
            printf("Read and Validate was not successful\n");
            return 1;
        }
    }

    else if ( check_operation_type(argv) == e_decode) // if decoding enter
    {
        printf("Chosen Decoding\n");
        DecodeInfo decInfo;
        if (read_and_validate_decode_args(argv, &decInfo) == e_success)
        {
            printf("Read and Validate is successful\n");
            printf("Start decoding\n");
            if (do_decoding(&decInfo) == e_success)
            {
                printf("Completed Decoding\n");
            }
            else
            {
                printf("Decoding was a Failure\n");
                return 1;
            }

        }
        else
        {
            printf("Read and Validate was not successful\n");
            return 1;
        }

    }
 
    else // if either chosen enter
    {
        printf("Invalid input\nPlease pass\nEncoding: ./a.out -e beautiful.bmp secret.txt stego.bmp\nDecoding: ./a.out -d stego.bmp decode.txt\n");
    }
}

/*
    Check type of operation
    Input:Array of command line arguments
    Ouput:Integer indicating type of operation
*/
OperationType check_operation_type(char *argv[])
{
   if (strcmp( argv[1], "-e") == 0) //check if user is opted for Encoding
   {
       return e_encode;
   }
   else if (strcmp( argv[1], "-d") == 0) //check if user is opted for Decoding
   {
       return e_decode;
   }
   else
   {
       return e_unsupported;
   }
}
