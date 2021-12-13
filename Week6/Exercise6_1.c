#include <stdio.h>
int A[10];
int B;

void input()
{
    char filename[256];
    printf("Input file's name: ");
    scanf("%s", filename);
    FILE *fp = fopen(filename,"r");
    if(fp == NULL)
    {
        printf("Can't open input file.\n");
    }
    else
    {
        for(int i = 0; i < 10; i++)
        {
            fscanf(fp,"%d ",&A[i]);
        }
        fscanf(fp,"%d",&B);
        fclose(fp);
    }
}
void printinfor()
{
    printf("Mang so duoc dua vao la:\n");
    for(int i = 0; i < 10; i++) printf("%d ",A[i]);
    printf("\nSo nguyen thu 11 la: %d\n",B);
}

void main()
{   
    input();
    printinfor();
    int count = 0;
    for(int i = 0; i < 10; i++)
    {
        if(A[i] ==B)
        {
            count++;
            printf("%d ", i+1);
        }
    }
    if(count == 0) printf("0");
}
