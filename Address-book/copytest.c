#include <stdio.h>
#define MAX 10




void main()
{
    int a[MAX];
    int i;
    int *p;

    p=a;
    for(i=0; i<MAX; i++){
      a[i]=i;
      printf("%d  ", a[i]);
    }
    puts("");
    printf("%d\n",*p);
    p = p-1;
    printf("%d\n",*p);
}
