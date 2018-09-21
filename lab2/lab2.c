/* Spencer Lawry
 * 9/21/18
 * Programming with C
 * Lab 2
*/
#include <stdio.h>
#define NUM_YEARS 5
void prompt();
void calc_cost(double *tot_cost, int fuel, int in_cost, double tax);

int main()
{
   int initial_cost,
       annual_fuel;
   double tax_rate,
          total_cost;

   prompt();

   printf("What is the initial cost of the house? ");
   scanf("%d", &initial_cost);

   printf("What is the annual fuel cost? ");
   scanf("%d", &annual_fuel);

   printf("What is the annual tax rate? ");
   scanf("%lf", &tax_rate);

   calc_cost(&total_cost, annual_fuel, initial_cost, tax_rate);

   printf("\nThe total cost of the house after five years will be: %.2f\n", total_cost);

   return(0);

}

/* prints the instructions to the user */
void prompt()
{
   printf("Please input the initial cost, annual fuel cost, and annual tax rate in the \
following format:\n\
           \ninitial cost: as an int with no commas ~ex. sixty thousand = 60000\
           \nannual fuel cost: as an int with no commas ~ex. two thousand = 2000\
           \nannual tax rate: as a decimal value ~ex. 3 percent = 0.03\n\n");
}

/* first parameter is a double pointer to total_cost */
void calc_cost(double *tot_cost, int fuel, int in_cost, double tax)
{
   *tot_cost = in_cost + NUM_YEARS*(fuel+ in_cost*tax); /* mutates total_cost variable in main */
   /* total cost = initial cost + years * yearly cost */
   /* (yearly cost = fuel/year + tax/year) */
}
