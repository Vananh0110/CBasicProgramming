#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

typedef struct Address
{
    char name[MAX];
    char telephone_number[MAX];
    char email_address[MAX];
    struct Address *next;
}Address;

Address *first, *last;


void InitList()
{
    first = NULL;
    last = NULL;
}

Address *makenodeList(char name[], char telephone_number[], char email_address[])
{
    Address *Node = (Address *) malloc(sizeof(Address));
    strcpy(Node->name, name);
    strcpy(Node->telephone_number, telephone_number);
    strcpy(Node->email_address, email_address);
    Node -> next = NULL;
    return Node;
}

void Insert(char name[], char telephone_number[], char email_address[])
{
    Address *p = makenodeList(name, telephone_number, email_address);
    if(first == NULL&& last == NULL)
    {
        first = p;
        last = p;
    }
    else
    {
       last -> next = p;
       last = p;
    }
}

void Input()
{
    char filename[MAX];
    printf("Input file's name: ");
    scanf("%s", filename);
    FILE *fp = fopen(filename,"r");
    if(fp == NULL)
    {
        printf("Can't open input file.\n");
    }
    else
    {   
        while(!feof(fp))
        {
            char name[MAX], telephone_number[MAX], email_address[MAX];
            fscanf(fp, "%s %s %s", name, telephone_number, email_address);
            Insert(name, telephone_number, email_address);
        }
    }
    fclose(fp);
}

void searching(char name[])
{   
    FILE *fp = fopen("fileout2.txt","w+");
    for(Address *p = first; p != NULL; p = p->next)
    {
        if(strcmp(p->name, name) == 0)
        {
            fprintf(fp, "%s %s %s\n",p -> name, p -> telephone_number, p -> email_address);
        }
    }
    fclose(fp);
}

void printinfor()
{
    printf("Thong tin duoc nhap vao la:\n");
    for(Address *p = first; p != NULL; p = p->next)
    {
        printf("%s %s %s\n",p -> name, p -> telephone_number, p -> email_address);
    }
}

void main()
{
    InitList();
    Input();
    printinfor();
    char name[MAX];
    printf("Nhap ten can tim kiem: ");
    scanf("%s", name);
    searching(name);
}
