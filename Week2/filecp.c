#include <stdio.h>
enum {SUCCESS, FAIL, MAX_LEN = 80};
void BlockReadWrite(FILE *fin, FILE *fout)
{
    int num;
    char buff[MAX_LEN+1];

    while(!feof(fin))
    {
        num = fread(buff, sizeof(char), MAX_LEN, fin);
        buff[num* sizeof(char)] = '\0';
        fwrite(buff, sizeof(char), num, fout);
    }
}
int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        printf("Wrong number of arguments\n");
        printf("Correct syntax: <file_name1.txt> <file_name2.txt>\n");
        return 1;
    }
    FILE *fptr1, *fptr2;
    int reval = SUCCESS;
    if((fptr1 = fopen(argv[1], "r"))== NULL)
    {
        printf("Cannot open %s for reading.\n", argv[1]);
        return reval = FAIL;
    }
    else if((fptr2 = fopen(argv[2],"w"))== NULL)
    {
        printf("Cannot open %s for writing.\n",argv[2]);
        reval = FAIL;
    }
    else{
        BlockReadWrite(fptr1, fptr2);
        fclose(fptr2);
        fclose(fptr1);
    }
    return reval;
}