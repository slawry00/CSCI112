/* Spencer Lawry
 * 9/28/18
 * Programming with C
 * Lab 3
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int find_sum(int *nums, int size);
double find_st_dev(int *nums, int size);

int main()
{
   int num_entries;
   int *entries;
   int smallest;
   int largest;
   int sum;
   double st_dev;
   int i;

   scanf("%d", &num_entries); /* the first number in the file is the number of entries */
   entries = malloc(num_entries*sizeof(int)); /* allocates enough space for the int array */

   for (i = num_entries; i > 0; i--)
   {
      scanf("%d", &entries[num_entries - i]);
      if (num_entries == i)
      {
      smallest = entries[num_entries - i];
      largest = entries[num_entries - i];
      }
      else if (entries[num_entries - i] < smallest)
      {
         smallest = entries[num_entries - i]; /* update the smallest */
      }
      else if (entries[num_entries - i] > largest)
      {
         largest = entries[num_entries - i]; /* update the largest */
      }
   }
   sum = find_sum(entries, num_entries);
   st_dev = find_st_dev(entries, num_entries);

   printf("The smallest number in the set of numbers is: %d\n", smallest);
   printf("The largest number in the set of numbers is: %d\n", largest);
   printf("The average of the numbers is: %.2f\n", (double)sum/num_entries);
   printf("The range of the numbers is: %d\n", largest-smallest);
   printf("The standard deviation of the numbers is: %.2f\n", st_dev);

    /*used for testing what the array held
   for (i = num_entries; i > 0; i--)
   {
      printf("%d\n", entries[num_entries - i]);
   } */

   free(entries);
   return 0;
}
/* returns the sum of an array of ints given the array and its size*/
int find_sum(int *nums, int size)
{
   int sum = 0;
   int i;

   for (i = 0; i < size; i++)
   {
      sum += nums[i];
   }
   return sum;
}
/* returns the standard deviation of an array of ints given the array and its size */
double find_st_dev(int *nums, int size)
{
   double mean;
   double diff;
   double sum;
   int i;

   mean = (double)find_sum(nums, size)/size;

   for (i = 0; i < size; i++)
   {
      diff = mean - nums[i];
      diff = pow(diff, 2); /* reuses diff variable momentarily */
      sum += diff;
   }
   return sqrt(sum/size);

}







