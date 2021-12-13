/*
Create a singly linked list to store a list of phone address.
Write a function to insert to a list a new element just after the current element and use it to add node to the list
Write a function for traversing the list to print out all information stored
Write a function for removal of a node in the list
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct AddressList{
    char phone[100];
    char addr[100];
    struct AddressList * next;
}AddressList;

AddressList* first, *last;

AddressList* makenodeList(char *phone, char *addr)
{
    AddressList *node = (AddressList*) malloc(sizeof(AddressList));
    strcpy(node->phone, phone);
    strcpy(node->addr, addr);
    node -> next = NULL;
    return node;
}

void InitList()
{
    first = NULL;
    last = NULL;
}
int listEmpty()
{
    return first == NULL && last == NULL;
}

void insertLast(char* phone, char* addr)
{
    AddressList* node = makenodeList(phone, addr);
    if(listEmpty())
    {
        first = node;
        last = node;
    }
    else
    {
        last -> next = node;
        last = node;
    }
}

void printlist()
{
    for(AddressList* p = first; p != NULL; p = p -> next)
    {
        printf("So dien thoai: %c , Dia chi: %c\n", p -> phone, p -> addr);
    }
}

AddressList *removal()








