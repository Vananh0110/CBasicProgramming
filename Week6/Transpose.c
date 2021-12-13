#include <stdio.h>
int A[10];
int B;

void input()
{
    FILE *fp = fopen("test1_1.txt","r");
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

int search(int key, int r[], int n)
{
    int i;
    int tempr;
    for(i = 0; i < n-1 && r[i]!=key;i++)
        if(key == r[i])
            {
                if(i>0)
                {
                    tempr = r[i];
                    r[i] = r[i-1];
                    r[--i] = tempr;
                };
                return i;
            }
        else return(-1);
}


void main()
{   
    input();
    printf("%d",search(B, A, 10));
}
