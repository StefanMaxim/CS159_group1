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
*
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

void makeArr(int seed, int arr[])
{
  int i; //index for looping

  srand(seed);
  for (i = 0; i < SIZE; i++)
  {
    arr[i] = rand() % (MAX - MIN + 1) + MIN;
  }
}

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

void removeDigits(int arr[], int digit)
{
  int i; //index in the array
  for (i = 0; i < SIZE; i++)
  {
    arr[i] = removeDigit(arr[i],digit);
  }
}

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