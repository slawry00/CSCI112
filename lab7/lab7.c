/* Spencer Lawry
 * 11/7/2018
 * Programming with C
 * Lab 7
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define STRING_SIZE 50
int pal(char* str);

int main()
{
   char str[STRING_SIZE],
        str_copy[STRING_SIZE],
        *s1 = "STOP",
        *s2 = "Stop",
        *s3 = "stop";

   printf("Enter a word and this will tell you if its a palindrome\n");
   scanf("%s", str);
   while (strcmp(str, s1) && strcmp(str, s2) && strcmp(str, s3))
   {
      strcpy(str_copy, str);
      printf("%s is %sa palindrome\n", str_copy, pal(str)? "" : "not ");
      scanf("%s", str);
   }

   return 0;
}

int pal(char* str)
{
   int len = strlen(str);

   if (len <= 1)
   {
      return 1;
   }
   else if (str[0] == str[len-1])
   {
      str[len-1] = '\0';
      return pal(&str[1]); // recurse with 1 char cut off on front and end
   }
   else
   {
      return 0;
   }
}
