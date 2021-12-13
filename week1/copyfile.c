#include <stdio.h>
void main() {
    char in_name[30], out_name[30];
    FILE *in_file, *out_file;
    printf("FIle to be copied: ");
    scanf("%s", in_name);
    printf("Output file name: ");
    scanf("%s", out_name);

    in_file = fopen(in_name, "r");
    if(in_file == NULL)
    {
        printf("Cannot open %s for reading.\n",in_name);
    }
    else
    {
        out_file = fopen(out_name, "w");
        if(out_file == NULL)
        {
            printf("Cannot open %s for writing.\n",out_name);
        }
        else
        {
            int c;
            while ((c = fgetc(in_file))!=EOF)
            {
                fputc(c,out_file);
                putchar(c);
            }
            fclose(out_file);
        }
    }
    fclose(in_file);
}