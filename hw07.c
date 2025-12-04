/*****+*--****-*-**-****-*--*-*--**--**-*---*-***--*************************
*
*  Homework #: 7
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified. Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work. I have not 
*  made use of any AI generated code in this solution. 
*
*  Program Description:
*  This program generates an array of random integers, computes statistics
*  on the original array, removes all occurrences of a user-specified digit
*  from every number, recomputes the statistics, and prints both sets of
*  results in a formatted table for comparison.
******+*--****-*-**-****-*--*-*--**--**-*---*-***--************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define SIZE 1000
#define MIN 0
#define MAX 999
#define SIZE_STATS 8

int getSeed(void);
int getDigit(void);
void makeArr(int seed, int arr[]);
void sortArr(int arr[]);
void makeStatistics(int arr[],double statArr[]);
void removeDigits(int arr[], int digit);
int removeDigit(int num, int digit);
void printResults(double beforeStats[],double afterStats[]);

int main()
{
  //plan: first make array,sort and calculate statics, then remove the numbs
  // needed by replacing with -1 and then resort, keeping track on index of first 
  //non-negative number and using it to calculate the statistics

  //Local Declarations
  int seed; // the seed for array generation
  int digit; //the digit to remove
  int arr[SIZE]; //the array where the numbers are stored
  double beforeStats[SIZE_STATS]; //array containing the statistics for the first, unaltered array
  double afterStats[SIZE_STATS];


  //Execution
  seed = getSeed();
  digit = getDigit();
  makeArr(seed, arr);
  sortArr(arr);
  makeStatistics(arr,beforeStats);
  removeDigits(arr, digit);
  sortArr(arr);
  makeStatistics(arr,afterStats);
  printResults(beforeStats,afterStats);

  return 0;
}

/*****+**-**-*-*-**-****-*--*-*--**--**-*---*-***--*************************
*
*  Function Information
*
*  Name of Function: getSeed
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. N/A
*    2.
*    3.
*
*  Function Description:
*    Prompts the user to enter a non-negative integer seed value, validates
*    the input, and returns the accepted seed.
*
******+**-**-*-*-**-****-*--*-*--**--**-*---*-***--************************/
int getSeed(void)
{
  int seed; //temp seed varible for user
  int done; //status of function

  do
  {
    printf("Enter desired seed value -> ");
    scanf("%d",&seed);
    done = 1;
    if (seed < 0)
    {
      printf("\nError! Non-negative seed values only!!\n\n");
      done = 0;
    }
  } while (!done);
  return seed;
}

/*****+**-**-*-*-**-****-*--*-*--**--**-*---*-***--*************************
*
*  Function Information
*
*  Name of Function: getDigit
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. N/A
*    2.
*    3.
*
*  Function Description:
*    Prompts the user to enter a single digit from 0 to 9, validates the
*    input, and returns the accepted digit to be removed from the numbers.
*
******+**-**-*-*-**-****-*--*-*--**--**-*---*-***--************************/
int getDigit(void)
{
  int digit; //temp variable for the digit
  int done; //status of the function

  do
  {
    printf("Enter desired digit to remove -> ");
    scanf("%d",&digit);
    done = 1;
    if (digit < 0 || digit > 9)
    {
      printf("\nError! Digit must be from 0 to 9.\n\n");
      done = 0;
    }
  } while (!done);
  return digit;
}

/*****+**-**-*-*-**-****-*--*-*--**--**-*---*-***--*************************
*
*  Function Information
*
*  Name of Function: makeArr
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int seed  // random seed used to initialize the generator
*    2. int arr[] // array to be filled with random integers
*    3.
*
*  Function Description:
*    Seeds the random number generator with the given seed and fills the
*    array with SIZE random integers uniformly distributed between MIN and
*    MAX inclusive.
*
******+**-**-*-*-**-****-*--*-*--**--**-*---*-***--************************/
void makeArr(int seed, int arr[])
{
  int i; //index for looping

  srand(seed);
  for (i = 0; i < SIZE; i++)
  {
    arr[i] = rand() % (MAX - MIN + 1) + MIN;
  }
}

/*****+**-**-*-*-**-****-*--*-*--**--**-*---*-***--*************************
*
*  Function Information
*
*  Name of Function: sortArr
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int arr[] // array of integers to be sorted in ascending order
*    2.
*    3.
*
*  Function Description:
*    Sorts the array of SIZE integers in ascending order using the
*    insertion sort algorithm.
*
******+**-**-*-*-**-****-*--*-*--**--**-*---*-***--************************/
void sortArr(int arr[])
{
  int i; //indexing value
  int j; //inner index
  int key; //the key of the values inside the array

  for (i = 1; i < SIZE; i++)
  {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

/*****+**-**-*-*-**-****-*--*-*--**--**-*---*-***--*************************
*
*  Function Information
*
*  Name of Function: makeStatistics
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int arr[]        // sorted data array used to compute statistics
*    2. double statArr[] // array to store computed statistics
*    3.
*
*  Function Description:
*    Computes statistics for the given data array, including the counts of
*    values in four ranges, the maximum, minimum, median, and average, and
*    stores these values in the statistics array.
*
******+**-**-*-*-**-****-*--*-*--**--**-*---*-***--************************/
void makeStatistics(int arr[], double statArr[])
{
  int i; //index for array

  statArr[0] = 0; //0-249
  statArr[1] = 0; //250-499
  statArr[2] = 0; //500-749
  statArr[3] = 0; //750-999
  statArr[4] = arr[0]; //maximum
  statArr[5] = arr[0]; //minimum
  statArr[6] = (arr[(SIZE / 2) - 1] + arr[(SIZE / 2)]) / 2.0; //median
  statArr[7] = 0; //average

  for (i = 0; i < SIZE; i++)
  {

    switch (arr[i] / 250)
    {
      case 0:
        statArr[0]++;
        break;
      case 1:
        statArr[1]++;
        break;
      case 2:
        statArr[2]++;
        break;
      case 3:
        statArr[3]++;
        break;
    }
    if (arr[i] > statArr[4])
    {
      statArr[4] = arr[i];
    }
    if (arr[i] < statArr[5])
    {
      statArr[5] = arr[i];
    }
    statArr[7] += arr[i];
  }
  statArr[7] /= SIZE;
}

/*****+**-**-*-*-**-****-*--*-*--**--**-*---*-***--*************************
*
*  Function Information
*
*  Name of Function: removeDigits
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int arr[] // array of integers whose digits will be removed
*    2. int digit // digit value (0–9) to remove from each array element
*    3.
*
*  Function Description:
*    Iterates through the array and replaces each element with the result
*    of removing all occurrences of the specified digit from that number.
*
******+**-**-*-*-**-****-*--*-*--**--**-*---*-***--************************/
void removeDigits(int arr[], int digit)
{
  int i; //index in the array
  for (i = 0; i < SIZE; i++)
  {
    arr[i] = removeDigit(arr[i],digit);
  }
}

/*****+**-**-*-*-**-****-*--*-*--**--**-*---*-***--*************************
*
*  Function Information
*
*  Name of Function: removeDigit
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int num   // original integer from which a digit will be removed
*    2. int digit // digit value (0–9) to remove from the given number
*    3.
*
*  Function Description:
*    Scans through the decimal digits of the given number and subtracts
*    the place value of any digit that matches the specified digit, using
*    powers of ten, then returns the modified integer.
*
******+**-**-*-*-**-****-*--*-*--**--**-*---*-***--************************/
int removeDigit(int num, int digit)
{
  int numCopy; //copy of the number for division purposes
  double order; //the degree of 10s for the digit to remove
  int temp; //the temporary digit we are on

  order = 0;
  numCopy = num;
  while (numCopy > 0)
  {
    temp = numCopy % 10;
    if (temp == digit)
    {
      num -= digit * pow(10.0,order);
    }
    order++;
    numCopy /= 10;
  }
  return num;
}

/*****+**-**-*-*-**-****-*--*-*--**--**-*---*-***--*************************
*
*  Function Information
*
*  Name of Function: printResults
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. double beforeStats[] // statistics for the original array
*    2. double afterStats[]  // statistics for the digit-modified array
*    3.
*
*  Function Description:
*    Prints a formatted table showing category counts, maximum, minimum,
*    median, and average for both the original and modified data sets so
*    they can be easily compared.
*
******+**-**-*-*-**-****-*--*-*--**--**-*---*-***--************************/
void printResults(double beforeStats[],double afterStats[])
{
  printf("\nCategory | Before | After\n");
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("  0 - 249: %5d  |%5d   \n",(int)beforeStats[0],(int)afterStats[0]);
  printf("250 - 499: %5d  |%5d   \n",(int)beforeStats[1],(int)afterStats[1]);
  printf("500 - 749: %5d  |%5d   \n",(int)beforeStats[2],(int)afterStats[2]);
  printf("750 - 999: %5d  |%5d   \n",(int)beforeStats[3],(int)afterStats[3]);
  printf("Maximum:   %5d  |%5d   \n",(int)beforeStats[4],(int)afterStats[4]);
  printf("Minimum:   %5d  |%5d   \n",(int)beforeStats[5],(int)afterStats[5]);
  printf("Median:    %4.1f  |%5.1f   \n",beforeStats[6],afterStats[6]);
  printf("Average:   %4.1f  |%5.1f   \n",beforeStats[7],afterStats[7]);
}