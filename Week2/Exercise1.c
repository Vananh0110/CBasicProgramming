/*
Write a program that use bloc-based file operations to copy the content of lab1.txt to lab1a.txt
Use: fread, fwrite, feof

size_t fread(void *ptr, size_t size, size_t n, FILE *stream);
=> Hàm trả về số phần tử thực sự đọc thành công từ tập tin

size_fwrite(void *ptr, size_t size, size_t n, FILE *stream);
=> Hàm trả về số phần tử thực sự được ghi thành công vào tập tin

int feof(FILE *stream);
=> Kiểm tra xem vị trí con trỏ file đã tới cuối tập tin hay chưa. Hàm trả về 0 nếu chưa tới vị trí cuối file ngược lại trả về giá trị khác 0

*/

#include <stdio.h>
enum {SUCCESS, FAIL, MAX_LEN = 80};
void BlockReadWrite(FILE *fin, FILE *fout)
{
    int num;
    char buff[MAX_LEN+1];

    while(!feof(fin)) {
        num = fread(buff, sizeof(char), MAX_LEN, fin);
        buff[num * sizeof(char)] = '\0';

        printf("%s", buff);
        fwrite(buff, sizeof(char), num, fout);
    }
}

int main()
{
    FILE *fptr1, *fptr2;
    char filename1[] = "lab1a.txt";
    char filename2[] = "lab1.txt";
    int reval = SUCCESS;
    
    if((fptr1 = fopen(filename1, "w"))== NULL)
    {
        printf("Cannot open %s.\n", filename1);
        reval = FAIL;
    }
    else if((fptr2 = fopen(filename2, "r")) == NULL)
    {
        printf("Cannot open %s.\n", filename2);
        reval = FAIL;
    }
    else BlockReadWrite(fptr2, fptr1);
    fclose(fptr1);
    fclose(fptr2);
    return reval;
}