#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char ID[30];
    char name[50];
    int grade;

    struct Student* next;
}Student;

Student* first, *last;

void initList()
{
    first = NULL; last = NULL;
}

int listEmpty()
{
    return first == NULL && last == NULL;
}
Student* makeStudent(char ID[], char name[], int grade)
{
    Student* node = (Student*) malloc(sizeof(Student));
    strcpy(node->ID, ID);
    strcpy(node->name, name);
    node ->grade = grade;
    node ->next = NULL;
    return node;
}

void InsertLast(char ID[], char name[], int grade) {
    Student* node = makeStudent(ID, name, grade);
    if(listEmpty())
    {
        first = node;
        last = node;
    }
    else {
        last -> next = node;
        last = node;
    }
}

void InserFirst(char ID[], char name[], int grade)
{
    Student *node = makeStudent(ID,name,grade);
    if(listEmpty())
    {
        first = node;
        last = node;
    }
    else
    {
        node -> next = first;
        first = node;
    }
    return node;
}

int size()
{
    int count = 0;
    for(Student *p = first; p!= NULL; p = p->next)
    {
        count++;
    }
    return count;
}

void Insertposition(char ID[], char name[], int grade, int position)
{   
    Student *node = makeStudent(ID, name, grade);
    if(listEmpty())
    {
        first = node;
        last = node;
    }
    else
    {
        if(position > size())
        {
            printf("Vi tri lon hon so phan tu trong danh sach, them vao cuoi danh sach.\n");
            InsertLast(ID, name, grade);
        }
        else
        {
        }
    }
}
Student* removeStudent(Student *node,char ID[])
{
    if(listEmpty()) return NULL;
    if(strcmp(node ->ID, ID) == 0)
    {
        Student* tmp = node -> next;
        free(node);
        if(tmp == NULL) last = NULL;
    }
    else{
        node -> next = removeStudent(node->next,ID);
        return node;
    }
    
}
void ReadInfor()
{
    char filename;
    printf("Nhap ten file thong tin: ");
    gets(filename);
    FILE * f = fopen(filename, "r");
    if(f == NULL)
    {
        printf("Cannot open file to read.\n");
    }
    char id[30];
    char name[50];
    int grade;
    while(fscanf(f, "%s %s %d",id,name,&grade)!=EOF)
    {
        makeStudent(id,name,grade);
    }
    fclose(f);
}
void WriteInfor()
{
    char filename;
    FILE * f = fopen(filename,"w+");
    Student* p;
    for(p = first; p != NULL; p = p->next)
    {
        fprintf(f,"%-10s %-30s %-10d\n", p->ID, p->name,p->grade);
    }
    fclose(f);
}
int main()
{
    
}

