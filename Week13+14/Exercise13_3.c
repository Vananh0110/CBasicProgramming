// Thuật toán KMP

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 2000

int KMP(char *source, char *find)
{
    int next[MAX], i = 0, len, j=-1, lensource;
    len = strlen(find);
    lensource = strlen(source);
    next[0] = -1;
    do {
      if (j == -1 || find[i] == find[j])
      {
        i++;
        j++;
        next[i] = j;
      }
      else
        j = next[j];
    } while (i < len-1);
    i = j = 0;
    do {
      if (j==0 || source[i] == find[j])
      {
        i++;
        j++;
      }
      else
        j = next[j];
    } while (j<len && i<lensource);
    if (j>=len)
      return i-len;
    else
      return -1;   
}

void main()
{
    char A[] = "KSNDKGNKNFSKNSBFKABCDJKFBABCDENKNK";
    char B[] = "ABCD";
    int vitri;
    vitri = KMP(A,B);
    if(vitri == -1) printf("Chuoi %s khong ton tai trong chuoi %s", B, A);
    else printf("Vi tri cua chuoi %s trong chuoi %s la: %d",B,A,vitri);
}