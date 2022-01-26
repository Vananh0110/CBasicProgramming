#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define MAX 100
typedef struct Student {
    char ID[MAX];
    char name[MAX];
    int grade;

    struct Student* next;
}Student;

Student* first, *last;

//Khoi tao danh sach
void initList()
{
    first = NULL; last = NULL;
}

//Kiem tra danh sach co trong khong
int listEmpty()
{
    return first == NULL && last == NULL;
}

//Tao node moi
Student* makeStudent(char ID[], char name[], int grade)
{
    Student* node = (Student*) malloc(sizeof(Student));
    strcpy(node->ID, ID);
    strcpy(node->name, name);
    node ->grade = grade;
    node ->next = NULL;
    return node;
}

//Them 1 node vao cuoi danh sach
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

//Them node vao dau danh sach
void InsertFirst(char ID[], char name[], int grade)
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
}

//Dem so node trong danh sach
int size()
{
    int count = 0;
    for(Student *p = first; p!= NULL; p = p->next)
    {
        count = count + 1;
    }
    return count;
}

//Them 1 node vao 1 vi tri trong danh sach
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

//Nap thong tin vao danh sach
void Input()
{
   
    FILE *fp = fopen("danhsachsinhvien.txt","r");
    if(fp == NULL)
    {
        printf("Can't open input file.\n");
    }
    else
    {   
        while(!feof(fp))
        {
            char ID[MAX], name[MAX];
            int grade;
            fscanf(fp, "%s %s %d",ID,name,&grade);
            InsertLast(ID,name, grade);
        }
        printf("Thong tin trong file da duoc nap vao trong danh sach.\n");
    }
    fclose(fp);
}
void printinfor()
{   
    printf("Danh sach hien tai:\n");
    Student *p;
    for(p = first; p != NULL; p = p->next)
    {
        printf("%s %s %d\n",p -> ID, p -> name, p -> grade);
    }
}

//Tim sinh vien theo ID
Student *search(char ID[])
{
    if(listEmpty())
    {
        printf("Danh sach trong!\n");
        return NULL;
    }
    else
    {
        Student *node;
        int dem = 0;
        printf("Thong tin cua sinh vien co ID %s la:\n",ID);
        for(node = first; node!=NULL; node=node->next)
        {
            if(strcmp(node->ID, ID) == 0)
            {   
                dem++;
                printf("%s %s %d\n", node -> ID, node -> name, node -> grade);

            }
        }
        if(dem == 0)
        {
            printf("Khong tim thay sinh vien co ID: %s trong danh sach.\n",ID);
            return NULL;
        }
        return node;
    }
}

//Tim kiem theo ID
void timkiemtheoID()
{
    char ID[MAX];
    printf("Moi ban nhap ID cua sinh vien muon tim kiem: ");
    fflush(stdin);
    gets(ID);
    Student *ketqua;
    ketqua = search(ID);
}

void remove_head()
{
    if(first == NULL && last == NULL)
    {
        printf("Khong co gi de xoa!\n");
    }
    else
    {
        Student *tmp = first;
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
        Student *p = first;
        while(p->next->next != NULL)
        {
            p = p -> next;
        }
        last = p;
        p -> next = NULL;
    }
}

void Remove(char ID[])
{
    if(strcmp(ID,first->ID) == 0)
    {
        remove_head();
    }
    else
    {   
        Student *p = NULL;
        Student *tmp = NULL;
        int dem = 0;
        for(p = first;p!= NULL; p= p-> next)
        {
            if(strcmp(ID,p->ID)==0)
            {
                dem++;
                tmp = p;
            }
        }
        if(dem == 0) printf("Khong ton tai sinh vien co ID %s trong danh sach.\n", ID);
        else
        {
            if(strcmp(first->next->ID,ID) == 0)
            {
                Student *tmp = first -> next;
                first -> next = tmp->next;
                free(tmp);
            }
            else
            {   Student *q = first;
                while(q->next->next != NULL)
                {
                    q = q->next;
                }
                Student *tmp = q -> next;
                q -> next = tmp->next;
                free(tmp);
                
            }
        }
    }
}

//Xoa sinh vien theo ID
void xoathongtintheoid()
{
    char ID[MAX];
    printf("Moi ban nhap ID cua sinh vien ban muon xoa khoi danh sach: ");
    fflush(stdin);
    gets(ID);
    Remove(ID);
    printinfor();
}

void main()
{
    initList();
    int choice;
    do
    {
        printf("--------MENU-------\n");
        printf("1. Nap file thong tin vao danh sach\n");
        printf("2. In thong tin\n");
        printf("3. Tim kiem hoc sinh theo ID\n");
        printf("4. Xoa sinh vien khoi danh sach theo ID.\n");
        printf("5. Thoat.\n");
        printf("---------------------\n");
        printf("Moi ban chon menu: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                Input();
                printf("Nhan phim bat ki de tiep tuc ...\n");
                getch();
                break;
            case 2:
                printinfor();
                printf("Nhan phim bat ki de tiep tuc ...\n");
                getch();
                break;
            case 3:
                timkiemtheoID();
                printf("Nhan phim bat ki de tiep tuc ...\n");
                getch();
                break;
            case 4:
                xoathongtintheoid();
                printf("Nhan phim bat ki de tiep tuc ...\n");
                getch();
                break;
            case 5:
                printf("Nhan phim bat ki de thoat ...\n");
                getch();
                break;
            default:
                printf("Nhan phim bat ki de tiep tuc ...\n");
                getch();
                break;

        }

    } while (choice!=5);
    
}




