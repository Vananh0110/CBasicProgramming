/*
    void *realloc(void *ptr, size_t size)
    Thay đổi kích thước vùng nhớ trỏ bởi ptr đã được cấp phát trước đó với hàm malloc hoặc calloc
    (
        void *calloc(size_t nitems, size_t size);
        void *malloc(unsigned int nbytes);
        void free(void *ptr);
        Hàm free (p) giải phóng bộ nhớ cấp phát trỏ bởi p
        Nếu p không trỏ tới vùng nhớ nào, một lỗi thực thi chương trình sẽ xuất hiện
    )
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char *str;
    str=(char *)malloc(15);
    strcpy(str,"tutorialspoint");
    printf("String = %s, Address = %u\n", str, str);
    str = (char *)realloc(str, 25);
    strcat(str, ".com");
    printf("String = %s, Address = %u\n", str, str);
    free(str);
    return 0;

}