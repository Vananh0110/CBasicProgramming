// Sử dụng sắp xếp chèn

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
void output()
{
    FILE *fp = fopen("fileout1.txt","w+");
    for(int i = 0; i < 10; i++)
        fprintf(fp,"%s %s %s\n", A[i].name, A[i].telephone_number, A[i].email_address);
    fclose(fp);
    printf("Thong tin da duoc sap xep trong fileout1.txt!");
}

int partition(int left, int right, Address pivot){
    int i = left;
    int j = right-1;
    while(1){
        while(strcmp(A[i].name,pivot.name)<0){
            i++;
        }
        while(j > 0 && strcmp(A[j].name,pivot.name)>0){
            j--;
        }
        if(i >= j)
            break;
        Address temp = A[i];
        A[i] = A[j];
        A[j] = temp;
        i++;
        j--;
    }
    Address temp1 = A[i];
    A[i] = A[right];
    A[right] = temp1;
    return i;
}
void quickSort(int left, int right) {
    if(right<=left){
        return;
    } else {
        Address pivot = A[right];
        int partitionPoint = partition(left, right, pivot);
        quickSort(left, partitionPoint-1);
        quickSort(partitionPoint+1, right);
    }
}
void main()
{
    input();
    printinfor();
    quickSort(0,9);
    output();
    
}