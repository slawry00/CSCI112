/* Spencer Lawry
 * Practice Program for strcat
 * 11/5/2018
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
   char my_string[50] = "Hello, my name is ",
        name_string[50] = "Spencer Lawry",
        *full = malloc(sizeof(char)*50);

   strcat(full, my_string);
   strcat(full, name_string);
   printf("%s\n", full);
}
