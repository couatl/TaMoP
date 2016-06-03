#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int num = 0;
    char cur_str[256];
    char *out_str, *temp;
    FILE * file;
    file = fopen("file.txt", "r");
    if (file)
    {
        while (fgets(cur_str, 256, file))
        {
            if (out_str = strstr(cur_str, "/func"))
            {
                out_str += strlen("/func ");
                if (temp = strstr(out_str, "*/"))
                    *temp = '\0';
                if (!strstr(out_str, "\n"))
                    strcat(out_str, "\n");
                printf("%d. %s", ++count, out_str);
            }
        }
        fclose(file);
    }
    else
        return 1;
    return 0;
}
