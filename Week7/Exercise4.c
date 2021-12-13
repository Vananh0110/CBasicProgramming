#include <stdio.h>
#include <string.h>
#define MAX 100
enum {SUCCESS, FAIL};
typedef struct phoneaddress_t{
    char name[MAX];
    char telephone_number[MAX];
    char email_address[MAX];
}phoneaddress;
int BinarySearch(phoneaddress A[], char name[], int N)
{
    int low, high, mid;
    low = 0; high = N - 1;
    while(low<=high)
    {
        mid = (low + high) / 2;
        if(strcmp(A[mid].name,name)<0)
            low = mid + 1;
        else if(strcmp(A[mid].name,name)>0)
            high = mid - 1;
        else return mid;
    }
    return -1;
}

int main(void)
{
    FILE *fp, *fout;
    phoneaddress phonarr[MAX];
    int i,n,irc;
    char name[MAX];
    int reval = SUCCESS;

    printf("How many contacts do you want to enter (<=100)? ");
    scanf("%d",&n);
    
}