/*We assume that you make a mobile phone’s address book.
• Declare a structure which can store at least "name", "telephone
number", "e-mail address.”.
• Declare a structure for a binary tree which can stores the
structure of an address book inside. Read data of about 10 from
an input file to this binary tree as the following rules.
– An address data which is smaller in the dictionary order for the e-mail
address is stored to the left side of a node.
– An address data which is larger in the dictionary order for the e-mail
address is stored to the right side of a node.
• (1) Confirm the address data is organized in the binary tree
structure with some methods (printing, debugger, etc).
• (2) Find a specified e-mail address in the binary tree and output it
to a file if found.
• (3) Output all the data stored in the binary tree in ascending
order for the e-mail address. (Reserve it for the next week)*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct Node
{
    char name[MAX];
    char telephone_number[MAX];
    char email_address[MAX];
    struct Node *left, *right;
}Node;

Node *makenode(char name[], char telephone_number[], char email_address[])
{
    Node *p = (Node *)malloc(sizeof(Node));
    strcpy(p->name, name);
    strcpy(p->telephone_number, telephone_number);
    strcpy(p->email_address, email_address);
    p -> left = NULL;
    p -> right = NULL;
    return p;
}

Node *Insert(char name[], char telephone_number[], char email_address[], Node *root)
{
    if(root == NULL) return makenode(name, telephone_number, email_address);
    int c = strcmp(root->email_address, email_address);
    if(c == 0)
    {
        printf("Dia chi %s da ton tai!\n",email_address);
        return root;
    }
    else if(c < 0)
    {
        root -> right = Insert(name, telephone_number, email_address, root -> right);
        return root;
    }
    else if(c > 0)
    {
        root -> left = Insert(name, telephone_number, email_address, root -> left);
        return root;
    }
}

Node *Search(Node *root, char *email_address)
{
    if(root == NULL) return NULL;
    int c = strcmp(root->email_address,email_address);
    if(c == 0) return root;
    if(c < 0) return Search(root -> right, email_address);
    else return Search( root-> left, email_address);
}

void processsearch(Node *root)
{
    
    char *email_address;
    printf("Nhap email can tim kiem: ");
    fflush(stdin);
    gets(email_address);
    Node *p = Search(root, email_address);
    if(p == NULL)
    {
        printf("Not Found!\n");
    }
    else
    {
        FILE *f = fopen("out_BST.txt", "w+");
        fprintf(f,"%s %s %s\n",p->name, p->telephone_number, p->email_address);
        fclose(f);
    }
}

void Inorder(Node *root)
{
    if(root != NULL)
    {
        Inorder(root -> left);
        printf("%s %s %s\n", root -> name, root -> telephone_number, root -> email_address);
        Inorder(root -> right);
    }
}

void main()
{
/*  Nguoi dung tu nhap thong tin

    Node *root = NULL;
    char name[MAX], telephone_number[MAX], email_address[MAX];
    char choice;
    do
    {
        printf("Ban co muon them 1 node vao cay khong(y/n)?...");
        scanf("%c",&choice);
        switch(choice)
        {
            case 'y':
                printf("Nhap ten: "); fflush(stdin);
                gets(name);
                printf("Nhap so dien thoai: "); fflush(stdin);
                gets(telephone_number);
                printf("Nhap dia chi email: "); fflush(stdin);
                gets(email_address);
                root = Insert(name, telephone_number, email_address, root);
                break;
            default:
                break;
        }
    } while (choice!='n');
*/
    Node *root = NULL;
    FILE *fp = fopen("fileinput.txt", "r");
    if(fp == NULL)
    {
        printf("Can't open input file.\n");
    }
    else
    {
        while(!feof(fp))
        {
            char name[MAX], telephone_number[MAX], email_address[MAX];
            fscanf(fp,"%s %s %s", name, telephone_number, email_address);
            root = Insert(name, telephone_number,email_address,root);
        }
    }
    fclose(fp);
    printf("\n==Duyet theo che do giua==\n");
    Inorder(root);
    processsearch(root);    
}