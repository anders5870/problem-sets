#include <stdlib.h>
int main()
{
    char *s;

    s=(char *) malloc (100);
    s="hello";
    free(s);
    return 0;
}
