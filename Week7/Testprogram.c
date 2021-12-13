#include <stdio.h>
#define NotFound -1

int BinarySearch(int A[], int x, int n)
{
    int low, high, mid;
    low = 0; high = n -1;
    while(low <= high)
    {
        mid = (low + high)/2;
        if(A[mid] < x)
        {
            low = mid +1;
        }
        else if(A[mid] > x)
        {
            high = mid -1;
        }
        else return mid;
    }
    return NotFound;
}

void main()
{
    static int A[] = {1,4,6,7,9,10,14,24};
    int SizeofA = sizeof(A)/sizeof(A[0]);
    int i;
    for(int i = 0; i < 20; i++)
    {
        printf("Binary Search of %d return %d\n", i, BinarySearch(A,i,SizeofA));

    }
}

