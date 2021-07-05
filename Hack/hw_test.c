#include <stdio.h>
#include <stdlib.h>

#define ERROR_FILE_OPEN -3

int main(void)
{
    long long int address = 0x00000000004011d2;
    unsigned char *sd;
    FILE *output = NULL;    
    char number = '1';

    output = fopen("output.bin", "wb");
    if (output == NULL) {
        printf("Error opening file");
        exit(ERROR_FILE_OPEN);
    }
 
    for(int i = 0; i < 20; i++)
    {
        fwrite(&number, sizeof(char), 1, output);
    }
    
    sd = (char*)&address;
    for(int i = 0; i < 8; i++)
    {
        fwrite(sd,sizeof(char), 1, output);
        sd++;
    }
    fclose(output);
}
