//Thuật toán Brute Force Matching

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Brute_Force(char *source, char *substr)
{
    int  i = 0, j = 0, m, n;
    n = strlen(source) - 1;
    m = strlen(substr) - 1;
    do {
        if (source[i] == substr[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    } while (j <= m && i <= n);
    if (j > m)
    {
        return i - m - 1;
    }
    else
        return -1;
}

void main()
{
    char A[] = "NGKKSNFKSNFKSKNFKSNFKSBFKABCDJKFBABCDENKNK";
    char B[] = "ABCD";
    int vitri;
    vitri = Brute_Force(A,B);
    if(vitri == -1) printf("Chuoi %s khong ton tai trong chuoi %s", B, A);
    else printf("Vi tri cua chuoi %s trong chuoi %s la: %d",B,A,vitri);
}