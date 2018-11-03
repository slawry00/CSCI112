/* Spencer Lawry
 * 10/25/18
 * Programming with C
 * Lab 5
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define ARRAY_SIZE 50

void selection_sort(char* my_chars);
void swap(char* a, char* b);
int main()
{
   char my_chars[ARRAY_SIZE]; /* fixed array size because its a pain to dynamically allocate
                                 one char input at a time in C */
   int i = 0;

   printf("Enter some characters to be sorted (one at a time) \nType 0 to exit\n");
   do
   {
      scanf(" %c", &my_chars[i]); // theres a space in front of %c to throw away newlines
   } while (my_chars[i++] != '0'); // exit = '0'
   my_chars[i] = '\0'; // need to put a null so I can use strlen

   selection_sort(my_chars);

   i = 0;
   while (my_chars[i] != '0')
   {
      printf("%c ", my_chars[i++]);
   }
   printf("\n");

   return 0;
}

void selection_sort(char* my_chars)
{
   int length = strlen(my_chars) - 1; // minus 1 for the '0'
   int is_first = 1; // flag variable
   int i, j;

   char* cur,
         *largest;

   for (i = 0; i < length - 1; i++) //(- 1) so we dont swap the last element with itself
   {                                // though it would "work" either way
      for (j = i; j < length; j++)
      {
         cur = &my_chars[j];
         if (is_first)
         {
            largest = cur;
            is_first = 0; // turning off flag
         }
         else if (*cur > *largest)
         {
            largest = cur;
         }
      }

      swap(largest, &my_chars[i]);
      is_first = 1; // reseting flag
   }
}
void swap(char* a, char* b)
{
   int temp;

   temp = *a;
   *a = *b;
   *b = temp;
}
