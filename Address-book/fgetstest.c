#include <stdio.h>
#include <string.h>
int main()
{
  FILE *f, *f2;
    char s[1000];

    f=fopen("fgetstest.c","r");
    f2 =fopen("remove", "w");
    if (!f)
      return 1;
    if(!f2)
      return 2;
    while (fgets(s,5,f)!=NULL){
      fprintf(f2, "%zd", strlen(s));
      printf("%s",s);
    }
    fclose(f);fclose(f2);
    return 0;
}
