/*
Write a program that gets an input line from the users (ends with '\n') and displays the number of times each letter appears in it
*/

#include <stdio.h>
#define ALPHABET_LEN 26

int main(void)
{
    int i;
    int count[ALPHABET_LEN];
    for (i = 0; i < ALPHABET_LEN; i++)
    {
        count[i] = 0;
    }
    char c='\0';

    printf("Please enter a line of text:\n");

    c=getchar();
    while (c!='\n'  && c>=0)
    {
        if(c<='z' && c>='a')
        ++count[c -'a'];
        if(c<='Z' && c>='A')
        ++count[c -'A'];
        c=getchar();
    }
    for(i = 0; i< ALPHABET_LEN; i++) 
    {
        if (count[i] > 0)
            printf("The letter '%c' appears %d time(s).\n", 'a' + i, count[i]);
    }
    return 0;
}