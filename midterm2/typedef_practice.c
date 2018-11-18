/* Spencer Lawry
 * Practice Program for Typedef
 * 11/5/2018
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
   typedef enum
   {
      Red,
      Orange,
      Yellow,
      Green,
      Blue,
      Purple
   } Color;
   Color i;
   for (i = Red; i <= Purple; i++)
   {
      printf("%d\n", i);
   }
}
