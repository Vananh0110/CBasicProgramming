// Sắp xếp sử dụng insert sort và quick sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define MAX 100
int A[MAX];
int n;

void khoitaomang(int A[])
{   
    printf("Nhap so phan tu cua mang: ");
    scanf("%d",&n);
    srand(time(NULL));
    int randNum = 0;
    int i;
    for(i = 0; i < n; i++)
    {
        randNum = rand() % 100;
        A[i] = randNum;
    }
    printf("Mang duoc khoi tao ngau nhien la:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    
}
void insertsort(int A[], int n)
{   
    int i, j, last;
    for(i = 1; i < n; i++)
    {
        last = A[i];
        j = i - 1;
        while(j >= 0 && A[j] > last)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = last;
    }
    printf("Mang duoc sap xep theo thu tu tang dan (insert sort) la:\n");
    for(i = 0; i < n; i++)
        printf("%d ", A[i]);

}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int partition(int A[], int L, int R, int indexpivot)
{
    int pivot = A[indexpivot];
    swap(&A[indexpivot], &A[R]);
    int storeIndex = L;
    int i;
    for(i = L; i <= R-1; i++)
    {
        if(A[i] < pivot)
        {
            swap(&A[storeIndex], &A[i]);
            storeIndex ++;
        }
    }
    swap(&A[storeIndex], &A[R]);
    return storeIndex;
}

void quicksort(int A[], int L, int R)
{
    if(L < R)
    {
        int index = (L+R)/2;
        index = partition(A, L, R, index);
        if(L < index)
        {
            quicksort(A, L, index - 1);
        }
        if(index < R)
        {
            quicksort(A, index+1, R);
        }
    }
}

void main()
{
    int choice;
    do
    {
        printf("\n-----------MENU------------\n");
        printf("1. Khoi tao mang.\n");
        printf("2. Sap xep bang insert sort.\n");
        printf("3. Sap xep bang quick sort.\n");
        printf("4. Thoat.\n");
        printf("Moi ban chon menu: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                khoitaomang(A);
                printf("Nhan bat ki de tiep tuc...");
                getch();
                break;
            case 2: 
                insertsort(A,n);
                printf("Nhan bat ki de tiep tuc....");
                getch();
                break;
            case 3:
                quicksort(A,0,n-1);
                int i;
                printf("Mang duoc sap xep theo quick sort la:\n");
                for(i = 0; i < n; i++)
                    printf("%d ", A[i]);
                printf("\n");
                printf("Nhan bat ki de tiep tuc....");
                break;
            case 4:
                printf("Thoat.");
                break;
            
            default:
                break;
            }
    } while (choice != 4);
    
    
}