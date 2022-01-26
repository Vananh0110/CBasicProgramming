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
   
    FILE *fp = fopen("input.txt","r");
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
void printinfor()
{   
    printf("Danh sach hien tai:\n");
    Address *p;
    for(p = first; p != NULL; p = p->next)
    {
        printf("%s %s %s\n",p -> name, p -> telephone_number, p -> email_address);
    }
}

void remove_head()
{
    if(first == NULL && last == NULL)
    {
        printf("Khong co gi de xoa!\n");
    }
    else
    {
        Address *tmp = first;
        first = first -> next;
        free(tmp);
    }
}

void remove_tail()
{
    if(first == NULL && last == NULL)
    {
        printf("Khong co gi de xoa!\n");
    }
    else
    {
        Address *p = first;
        while(p->next->next != NULL)
        {
            p = p -> next;
        }
        last = p;
        p -> next = NULL;

        
    }
}

void main()
{
    InitList();
    Input();
    printinfor();
    printf("\nXoa phan tu o dau danh sach\n");
    remove_head();
    printinfor();
    printf("\nXoa phan tu o cuoi danh sach\n");
    remove_tail();
    printinfor();
}