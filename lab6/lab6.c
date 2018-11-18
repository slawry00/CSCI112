/* Spencer Lawry
 * 11/2/2018
 * Programming with C
 * Lab 6
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define STRING_SIZE 50
void plural_maker(char* word);
int main()
{
   char word[STRING_SIZE],
        *s1 = "STOP",
        *s2 = "Stop",
        *s3 = "stop";

   printf("Enter a noun and this program will return its plural form.\n");
   scanf("%s", word);

   //printf("s1 is: %s\ns2 is: %s\ns3 is: %s\nword is %s\n", s1, s2, s3, word);
   //printf("strcmp returns: %d\n", strcmp(word, s3));
   while (strcmp(word, s1) && strcmp(word, s2) && strcmp(word, s3))
   {
      plural_maker(word);
      printf("The plural is: %s\n", word);
      scanf("%s", word);
   }
   return 0;

}

void plural_maker(char* word)
{
   int len = strlen(word);
   char last,
        sec_last;

   if (len < 1) // don't have a word
   {
      fprintf(stderr, "The word must have at least 1 character");
      exit(1);
   }

   last = word[len-1]; // now that we know it has at least 1 char

   if (len > 1)
   {
      sec_last = word[len-2]; // now we know it has at least 2 chars
      if (last == 'h' && (sec_last == 'c' || sec_last == 's'))
      { // add 'es' to 'ch', 'sh'
         word[len] = 'e';
         word[len+1] = 's';
         word[len+2] = '\0';
         return;
      }
   }
   if (last == 's')
   { // add 'es' to 's'
      word[len] = 'e';
      word[len+1] = 's';
      word[len+2] = '\0';
   }
   else if (last == 'y')
   { // turn 'y' into 'ies'
      word[len-1] = 'i';
      word[len] = 'e';
      word[len+1] = 's';
      word[len+2] = '\0';
   }
   else
   { // otherwise add 's'
      word[len] = 's';
      word[len+1] = '\0';
   }

}
