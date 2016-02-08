#include <stdio.h>

int main(int argc, char *argv[])
{
    int x;

    printf("%d\n",argc);
    for (x=0; x<argc; x++){
      printf("%s\n", argv[x]);
      if (strcmp(argv[x], "-help") == 0)
        printf("Help message\n");
    }
    return 0;
}
