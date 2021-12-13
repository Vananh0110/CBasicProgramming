#include <stdio.h>
#define NotFound -1
int dem = 0;
int BinarySearch(int A[], int target, int low, int high)
{   
    if(low>high)
    {   
        dem++;
        return NotFound;
    }
    int mid = (low+high)/2;
    if(A[mid]<target)
    {   
        dem++;
        return BinarySearch(A, target, mid+1, high);
    }
    else if(A[mid]>target)
    {   
        dem++;
        return BinarySearch(A, target, low, mid -1);
    }
    else if(A[mid] = target)
    {
        dem++;
        return mid;
    }
    return NotFound;
}
void main()
{   
    int A[100];
    for(int i = 0; i < 100; i++)
    {
        A[i] = i+1;
    }
    printf("Nhap so can tim kiem: ");
    int x;
    scanf("%d", &x);
    printf("Chi so cua phan tu co gia tri %d trong mang la: %d\n",x,BinarySearch(A,x,0,99));
    printf("So phep so sanh den khi tim thay phan tu la: %d",dem);
}
