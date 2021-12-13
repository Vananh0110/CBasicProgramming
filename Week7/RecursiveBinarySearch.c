#include <stdio.h>
#define NotFound -1
int BinarySearch(int A[], int target, int low, int high)
{   
    if(low>high)
    {   
        return NotFound;
    }
    int mid = (low+high)/2;
    if(A[mid]<target)
    {   
        return BinarySearch(A, target, mid+1, high);
    }
    else if(A[mid]>target)
    {   
        return BinarySearch(A, target, low, mid -1);
    }
    else if(A[mid] = target)
    {
        return mid;
    }
    return NotFound;
}
void main()
{
    int static A[] = {0, 5, 6, 9, 15, 17};
    int size = sizeof(A)/sizeof(A[0]);
    for(int i=0; i<= 20; i++)
    {
        printf("BinarySearch of %d returns %d\n",i, BinarySearch(A,i,0,size-1));
    }
}
