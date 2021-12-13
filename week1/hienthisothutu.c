#include <stdio.h>

enum {SUCCESS, FAIL, MAX_LEN = 81};

void LineReadWrite(FILE *fin, FILE *fout)
{
    int c;
    char buff[MAX_LEN];
    int count = 0;
    while (fgets(buff, MAX_LEN, fin) != NULL) {
        count++;
        fputs(buff, fout);
        printf("%d %s", count, buff);
    }
}

int main(void)
{
    FILE *fptr1, *fptr2;

    char filename1[] = "lab4.txt";
    char filename2[] = "lab1.txt";
    int reval = SUCCESS;

    if((fptr1 = fopen(filename1, "w"))==NULL) {
        printf("Cannot open %s.\n", filename1);
        reval = FAIL;
    }
    else if((fptr2 = fopen(filename2, "r"))==NULL)
    {
        printf("Cannot open %s.\n", filename2);
        reval = FAIL;
    }
    else
    {
        LineReadWrite(fptr2, fptr1);
        fclose(fptr1);
        fclose(fptr2);
    }
    return reval;
}