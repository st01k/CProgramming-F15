#include <stdio.h>
#include <string.h>

int main()
{
   char src1[40];
   char dest1[12];
   char* src;
   char* dest;

   memset(dest, '\0', sizeof(dest));
   strcpy(src, "This is tutorialspoint.com");
   strncpy(dest, src, 10);

   printf("Final copied string : %s\n", dest);

   return(0);
}
