#include <stdlib.h>
#include <stdio.h>

void removeblanks(char *s){
  char temp[100];
  int m = 0;
  while(*s++ == ' ' && m<100, m++);
  int i = 0;
  while(*s++ != ' '){
    temp[i++] = *s;
  }
  temp[++i] = ' ';
  while(*s++ == ' ');
  while(*s++ != ' '){
    temp[i++] = *s;
  }
  s = temp;
}

int ztrlen(char *s){
  int x = 0;
  while(*s++)
    ++x;
  return x;
}

char *getlastname(char *s){
  int start, end = 0;
  while(*(s+end),++end);
  while(*(s+end+start),--start);
  char *lastname = (char*)malloc((-1)*start+1);
  while(*lastname++ = *(s+end-start++));
 return lastname;
}

void toUpper(char *s){
  while(*s){
    if ((int)*s >= 97 && (int)*s <= 122){
      *s = (int)*s-32;
    }
    s++;
  }
}


char *getremainder(char *s){
  int m;
    for(m = 0; *s++ == ' ' && m<100;m++);
  for(m = 0; *s++ != ' ' && m<100;m++);
  for(m = 0; *s++ == ' ' && m<100;m++);
  char *tmp;
  while(*s++ = *tmp++);
  char *remainder = (char *)malloc(ztrlen(tmp+1));
  remainder = tmp;
  return remainder;
}

int main(){
  printf("Enter firstname and lastname separated by one or more spaces:");
  char s[99];
  char *p = (char*)malloc(100);
  gets(s);
  p = s;
  removeblanks(p);
  printf("Lastname: %s\n", getlastname(p));
  toUpper(p);
  printf("%s\n", p);
  printf("%s\n", getremainder(p));
  return 0;
}
