#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{

    FILE *File1;
    FILE *File2;
    char Str1[128], Str2[128];
    char *Name1, *Name2;
    int ch;
    int str1 = 0, str2 = 0;

    if (argc != 3)
    {
        printf("ERROR");
        exit(1);
    }
    do
    {
        File1 = fopen(argv[1], "r");
        Name1 = argv[1];
        if (!File1) printf("ERROR File1 isn't open");

        File2 = fopen(argv[2], "r");
        Name2 = argv[2];
        if(!File2) printf("ERROR File2 isn't open");
    } while(File1 && File2);

    while(fgets(Str1, 128, File1))
    {
        ch = 0;
        while(fgets(Str2, 128, File2))
        {
             ch = strcmp(Str1, Str2);
            if (ch) break;
            StrSearch: str2++;
        }
        str1++;
    }
    if(ch)
    {
        printf("%s %d %s/n", Name1, str1+1, Str1);
        printf("%s %d %s/n", Name2, str2+1, Str2);
        goto StrSearch;
    }

    fclose(File1);
    fclose(File2);
    system("pause");
    return 0;
}
