//Sắp xếp sử dụng merge sort

#include <stdio.h>
#include <string.h>
#define MAX 100
typedef struct Address
{
    char name[MAX];
    char telephone_number[MAX];
    char email_address[MAX]; 
}Address;

Address A[MAX];

void input()
{
    FILE *f = fopen("fileinput.txt","r");
    if(f == NULL)
    {
        printf("Can't open input file.\n");
    }
    else
    {
        for(int i = 0; i < 10; i++)
        {
            fscanf(f,"%s %s %s\n", A[i].name, A[i].telephone_number, A[i].email_address );
        }
        fclose(f);
    }
}

void printinfor()
{   
    printf("Thong tin duoc dua vao la:\n");
    for(int i = 0; i < 10; i++)
    {
        printf("%s %s %s\n", A[i].name, A[i].telephone_number, A[i].email_address );
    }
}

void merge(Address A[], int L, int M, int R)
{
    int i,j,k;
    int n1 = M-L+1;
    int n2 = R-M;
    Address A1[n1];
    Address A2[n2];
    for(i = 0; i < n1; i++)
        A1[i] = A[L+i];
    for(j = 0; j < n2; j++)
        A2[j] = A[M+1+j];
    i = 0;
    j = 0;
    k = L;
    while(i < n1 && j < n2)
    {
        if(strcmp(A1[i].name, A2[j].name) <= 0)
        {
            A[k] = A1[i];
            i++;
        }
        else
        {
            A[k] = A2[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        A[k] = A1[i];
        i++;
        k++;
    }
    while(j < n2)
    {
        A[k] = A2[j];
        j++;
        k++;
    }
}

void output(Address A[], int n)
{
    FILE*fp = fopen("out_mergesort.txt","w+");
    int i;
    for(i = 0; i < n; i++)
    {
        fprintf(fp,"%s %s %s\n",A[i].name, A[i].telephone_number, A[i].email_address);
    }
    fclose(fp);
    printf("Danh sach da duoc sap xep theo merge sort o file out_mergesort.txt\n");
}

void mergesort(Address A[], int L, int R)
{
    if(L < R)
    {
        int M = (L+R)/2;
        mergesort(A,L,M);
        mergesort(A,M+1,R);
        merge(A,L,M,R);
    }
}

void main()
{
    input();
    printinfor();
    mergesort(A,0,9);
    output(A,10);
}

