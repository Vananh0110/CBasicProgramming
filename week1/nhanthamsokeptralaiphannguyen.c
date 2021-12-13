/*
Write a function that accepts a double parameter and returns its integer and fraction parts.Write a program that accepts a number from the user and prints out its integer and fraction parts, using this function.
*/

#include <stdio.h>
void split(double num, int*int_part,double*frac_part)
{
    *int_part = (int)num;
    *frac_part = num -*int_part;
}
int main(void)
{
    double num, fraction;
    int integer;
    printf("Please  enter a real number: ");
    scanf("%f", &num);
    split(num, &integer, &fraction);
    printf("The integer part is %d\n", integer);
    printf("The remaining fraction is %f\n", fraction);return 0;
}