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
Address B;

void input()
{
    printf("Input file's name: ");
    char file[MAX];
    scanf("%s", file);
    FILE *f = fopen(file,"r");
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
void output(Address A)
{
    FILE *fp = fopen("fileout.txt","w+");
    fprintf(fp,"%s %s %s\n", A.name, A.telephone_number, A.email_address);
    fclose(fp);
}
void main()
{
    input();
    printinfor();
    printf("Nhap ten can tim kiem: ");
    scanf("%s",B.name);
    for(int i = 0; i < 10; i++)
    {
        if(strcmp(A[i].name,B.name) == 0)
        {
            output(A[i]);
        }
    }

}