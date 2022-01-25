/* Cài đặt hàm my_strcat: 
        Đầu vào là hai xâu ký tự s1 và s2
        Đầu ra là một con trỏ - trỏ tới vùng nhớ động chứa nội dung xâu là kết quả của phép nối hai xâu s1 và s2 
    Sử dụng kỹ thuật cấp phát bộ nhớ động
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100

char *my_strcat(char *str1, char *str2)
{
    int len1, len2;
    char *result;
    len1 = strlen(str1);
    len2 = strlen(str2);
    result = (char *)malloc((len1 + len2 + 1) * sizeof(char));
    if(result == NULL)
    {
        printf("Allocation failed! Check memory!\n");
        return NULL;
    }
    strcpy(result, str1);
    strcpy(result + len1, str2);
    return result;
}
int main()
{
    char str1[MAX_LEN], str2[MAX_LEN];
    char *cat_str;
    printf("Please enter two string:\n");
    printf("Enter String1:\n");
    scanf("%100s", str1);
    printf("Enter String2:\n");
    scanf("%100s", str2);
    cat_str = my_strcat(str1, str2);
    if(cat_str == NULL)
    {
        printf("Problem allocating memory!\n");
        return 1;
    }
    printf("The concatention of %s and %d is %s\n", str1, str2, cat_str);
    free(cat_str);
    return 0;
}