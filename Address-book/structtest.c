#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
typedef struct
	{
		char name[21];
		char city[21];
		char phone[21];
		char *comment;
	} Addr;
	Addr s;
	char comm[100];
        puts("Enter name: ");
	gets(s.name);
        puts("Enter city: ");
        gets(s.city);
	puts("Enter number: ");
        gets(s.phone);
        puts("Enter comment: ");
	gets(comm);
	s.comment =
     (char *)malloc(sizeof(char[strlen(comm)+1]));
	strcpy(s.comment, comm);
}
