#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    FILE *fp;
    char buf[4000] = {0};
    int i, num, n = 0;
    char *s = "Äã";
 
    fp = fopen("test.txt", "r");
    num = fread(buf, sizeof(char), 4000, fp);
    for(i = 0; i < num; i++)
        if(strncmp(buf+i, s, 2)==0)
            n++;
    printf("%d\n", n);
    fclose(fp);
    return 0;
}
