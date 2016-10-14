#include<string.h>
#include<stdio.h>

int main(void)
{
  char string[]="Hi there, Chip!";
  char *string_ptr;

  while((string_ptr=strpbrk(string," "))!=NULL)
    *string_ptr='-';

  printf("New string is \"%s\".\n",string);
  return 0;
}
