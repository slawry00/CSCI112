/* Spencer Lawry
 * 10/19/18
 * Programming with C
 * Lab 4
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define BUF_SIZE 15
#define ARR_SIZE 20

int get_corners(double* x_arr, double* y_arr, int size);
void output_corners(double* x_arr, double* y_arr);
double polygon_area(double* x_arr, double* y_arr);

int main()
{
   double x_vals[ARR_SIZE + 1], //last space for the sentinel
          y_vals[ARR_SIZE + 1],
          area;

   get_corners(x_vals, y_vals, ARR_SIZE);
   output_corners(x_vals, y_vals);
   area = polygon_area(x_vals, y_vals);
   printf("Area of the closed polygon = %.2f\n", area);

   return 0;
}
int get_corners(double* x_arr, double* y_arr, int size)
{

   char buffer[BUF_SIZE];
   int i = 0;

   while(fgets(buffer, BUF_SIZE, stdin) != NULL) // grabs the whole line and checks for EOF
   {
      if (i > size)
      {
         break; //we've used up all of our array slots (and we're fine with that)
      }
      else if(sscanf(buffer, "%lf %lf", &x_arr[i], &y_arr[i]) != 2)
         //if string scanf doesn't input both x&y coords (at least 2 doubles), it is an error
      {
         fprintf(stderr, "parsing error\n");
         exit(1);
      }
      i++; //increment i for array indexing purposes
   }
   x_arr[i] = -1; //making a sentinel at the end of the array
   y_arr[i] = -1;

   return i-1; //number of values in the array (it incremented 1 last time before it ended)
}
void output_corners(double* x_arr, double* y_arr) //I chose to use a sentinel instead of size
{
   int i = 0;

   while (x_arr[i] != -1) // while we haven't yet reached the sentinel
   {
      printf("%.2f  " , x_arr[i]);
      printf("%.2f\n", y_arr[i]);
      i++;
   }
}
double polygon_area(double* x_arr, double* y_arr) // I used a sentinel instead of size
{
   double area = 0.0;
   int i = 0;

   while (x_arr[i+1] != -1) //while i+1 is not the sentinel
   {
      area += (x_arr[i+1] + x_arr[i])*(y_arr[i+1] - y_arr[i]);
      i++;
   }
   return abs(area)/2.0;
}












