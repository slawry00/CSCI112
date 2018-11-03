/* Spencer Lawry
 * 10/5/18
 * Programming with C
 * Program 1
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double calc_monthly(int p, double rate, int n);

int main()
{
   double principal; /* the inital amount of money borrowed */
   double rate; /* the annual interest rate */
   int num_pay; /* the number of payments */
   double monthly; /* the monthly payment */
   double term_i; /* the portion of a monthly payment that goes to interest */
   double term_p; /* the portion of a monthly payment that goes to principal */
   FILE *out_file = fopen("payments.txt", "w");
   int i;

   printf("Enter the amount of money borrowed: ");
   scanf("%lf", &principal);
   printf("Enter the annual interest rate: ");
   scanf("%lf", &rate);
   rate = rate/100; /* convert from % to decimal percentages */
   printf("Enter the number of payments: ");
   scanf("%d", &num_pay);

   monthly = calc_monthly(principal, rate, num_pay);
   monthly = round(monthly * 100) / 100; /* round the monthly payment to the nearest cent */
   printf("Monthly payment: %.2f\n", monthly);

   for (i = 1; i <= num_pay; i++)
   {
      term_i = rate*principal/12; /* monthly interest paid */
      term_i = round(term_i * 100) / 100; /* round the interest to the nearest cent */
      if (i == num_pay)
      {
         term_p = principal; /* to account for rounding on final payment */
         principal -= term_p;
         fprintf(out_file, "%d      %.2f   %.2f   %.2f\n", i, term_i, term_p, principal);
         fprintf(out_file, "Final payment: %.2f", term_i + term_p);
      }
      else
      {
      term_p = monthly - term_i; /* monthly principal paid off */
      principal -= term_p;
      fprintf(out_file, "%d      %.2f   %.2f   %.2f\n", i, term_i, term_p, principal);
      }
   }

   return 0;
}
double calc_monthly(int p, double rate, int n)
{
   rate = rate/12;
   double denom = 1 - pow(1 + rate, -1*n); /* 1 - (1+int-rate)^-n */
   return rate*p/denom;
}

