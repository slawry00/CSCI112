/* Spencer Lawry
 * 9/7/18
 * Programming with C
 * Lab 1
*/

#include <stdio.h> /*need io functions*/
#define FEET_PER_MILE 5280 /*define constant feet to mile conversion factor*/

int main(int argc, char** argv){
   int feet;
   double miles;

   printf("Enter a distance in feet: "); /*prompts user for feet value*/
   scanf("%d", &feet); /*scans feet value and saves into feet local variable's memory location*/

   miles = (double)feet/FEET_PER_MILE; /* does the conversion*/
   printf("The value in miles is: %.2f\n", miles); /* returns the value in miles to the user*/

   return(0);
}



