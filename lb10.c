/*****+*--*-*--*----***-***----*-*--**----*-*-***--*************************
 *
 *  Lab #: 09
 *
 *  Academic Integrity Statement:
 *
 *  We have not used source code obtained from any other unauthorized source,
 *  either modified or unmodified. Neither have we provided access to our code
 *  to another. The effort we are submitting is our own original work. We have 
 *  not made use of any AI generated code in this solution. 
 *
 *  Program Description: This program will simulate a beginner game of blackjack. It will be a player against a simulated dealer. Each player will start with 100 credits and can choose the amount they bet each round. The number of rounds will be determines randomly by the program. 
 *
 ******+*--*-*--*----***-***----*-*--**----*-*-***--************************/

#include <stdio.h>
#include <stdlib.h>

#define SIZE        100     /* fixed size for the array              */
#define RANDOM_MIN  0       /* minimum random value                  */
#define RANDOM_MAX  100000  /* maximum random value (inclusive)      */

int getSeed(void);

void makeArr(int seed, int array[]);

int getGCD(int element1, int element2);

void setMin(int numSub,
            int* minSub,
            int* minElement1,
            int* minElement2,
            int element1,
            int element2);

void setMax(int numSub,
            int* maxSub,
            int* maxElement1,
            int* maxElement2,
            int element1,
            int element2);

void sumNums(int arrMinElement1,
             int arrMinElement2,
             int arrMaxElement1,
             int arrMaxElement2,
             int* minSums,
             int* maxSums);

void printResults(int minSub,
                  int minElement1,
                  int minElement2,
                  int minSums,
                  int maxSub,
                  int maxElement1,
                  int maxElement2,
                  int maxSums);

void findMinMaxPairs(int array[],
                     int* minSub,
                     int* minElement1,
                     int* minElement2,
                     int* minSums,
                     int* maxSub,
                     int* maxElement1,
                     int* maxElement2,
                     int* maxSums);

int main(void)
{
  // LOCAL DECLARATIONS
  int seed;           // the seed for the random number generator           
  int arr[SIZE];      // the array which will be filled                     
  int minSub;         // fewest number of subtractions to arrive at the GCD 
  int minElement1;    // index of first element which gave the fewest subs  
  int minElement2;    // index of second element which gave the fewest subs 
  int maxSub;         // maximum number of subtractions to find GCD         
  int maxElement1;    // index of first element which gave the most subs    
  int maxElement2;    // index of second element which gave the most subs   
  int minSums;        // sum of values for the minimum pair (with tie rule) 
  int maxSums;        // sum of values for the maximum pair (with tie rule) 

  // EXECUTABLE STATEMENTS
  seed = getSeed();
  makeArr(seed, arr);

  findMinMaxPairs(arr, &minSub, &minElement1, &minElement2, &minSums, &maxSub, &maxElement1, &maxElement2, &maxSums);

  printResults(minSub, minElement1, minElement2, minSums, maxSub, maxElement1, maxElement2, maxSums);

  return 0;
}

// FUNCTION DEFINITIONS

/*****+*-*****-**-**----*-**-----**--*----*-*-***--*************************
*
*  Function Information
*
*  Name of Function: get_seed
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1.
*    2.
*    3.
*
*  Function Description: This function will get the seed value from the user and use input validation.
*
******+*-*****-**-**----*-**-----**--*----*-*-***--************************/
int getSeed(void)
{
  int seed;  // local seed variable

  do
  {
    printf("Enter desired seed value -> ");
    scanf("%d", &seed);
    if (seed < 0)
    {
      printf("\nError! Non-negative values only!\n\n");
    }
  } while (seed < 0);

  return seed;
}

/*****+*-*****-**-**----*-**-----**--*----*-*-***--*************************
*
*  Function Information
*
*  Name of Function: get_seed
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1.
*    2.
*    3.
*
*  Function Description: This function will get the seed value from the user and use input validation.
*
******+*-*****-**-**----*-**-----**--*----*-*-***--************************/
void makeArr(int seed, int array[])
{
  int i;  // loop counter 

  srand(seed);

  for (i = 0; i < SIZE; i++)
  {
    array[i] = rand() % (RANDOM_MAX + 1);  // RANDOM_MIN is 0, so no offset 
  }
}

/*****+*-*****-**-**----*-**-----**--*----*-*-***--*************************
*
*  Function Information
*
*  Name of Function: get_seed
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1.
*    2.
*    3.
*
*  Function Description: This function will get the seed value from the user and use input validation.
*
******+*-*****-**-**----*-**-----**--*----*-*-***--************************/
int getGCD(int element1, int element2)
{
  int x;      // working copy of first value  
  int y;      // working copy of second value
  int count;  // number of subtractions performed

  x = element1;
  y = element2;
  count = 0;

  // Assumes x and y are non-zero (zero pairs skipped before call)
  while (x != y)
  {
    if (x > y)
    {
      x = x - y;
    }
    else
    {
      y = y - x;
    }
    count++;
  }

  return count;
}

/*****+*-*****-**-**----*-**-----**--*----*-*-***--*************************
*
*  Function Information
*
*  Name of Function: get_seed
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1.
*    2.
*    3.
*
*  Function Description: This function will get the seed value from the user and use input validation.
*
******+*-*****-**-**----*-**-----**--*----*-*-***--************************/
void setMin(int numSub, int* minSub, int* minElement1, int* minElement2, int element1, int element2)
{
  *minSub = numSub;
  *minElement1 = element1;
  *minElement2 = element2;
}

/*****+*-*****-**-**----*-**-----**--*----*-*-***--*************************
*
*  Function Information
*
*  Name of Function: get_seed
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1.
*    2.
*    3.
*
*  Function Description: This function will get the seed value from the user and use input validation.
*
******+*-*****-**-**----*-**-----**--*----*-*-***--************************/
void setMax(int numSub, int* maxSub, int* maxElement1, int* maxElement2, int element1, int element2)
{
  *maxSub = numSub;
  *maxElement1 = element1;
  *maxElement2 = element2;
}

/*****+*-*****-**-**----*-**-----**--*----*-*-***--*************************
*
*  Function Information
*
*  Name of Function: get_seed
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1.
*    2.
*    3.
*
*  Function Description: This function will get the seed value from the user and use input validation.
*
******+*-*****-**-**----*-**-----**--*----*-*-***--************************/
void sumNums(int arrMinElement1, int arrMinElement2, int arrMaxElement1, int arrMaxElement2, int* minSums, int* maxSums)
{
  *minSums = arrMinElement1 + arrMinElement2;
  *maxSums = arrMaxElement1 + arrMaxElement2;
}

/*****+*-*****-**-**----*-**-----**--*----*-*-***--*************************
*
*  Function Information
*
*  Name of Function: get_seed
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1.
*    2.
*    3.
*
*  Function Description: This function will get the seed value from the user and use input validation.
*
******+*-*****-**-**----*-**-----**--*----*-*-***--************************/
void printResults(int minSub, int minElement1, int minElement2, int minSums, int maxSub, int maxElement1, int maxElement2, int maxSums)
{
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Minimum number of subtractions: %d\n", minSub);
  printf("Elements at index %02d and %02d create sum: %d\n",
         minElement1, minElement2, minSums);
  printf("\nMaximum number of subtractions: %d\n", maxSub);
  printf("Elements at index %02d and %02d create sum: %d\n",
         maxElement1, maxElement2, maxSums);
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
}

/*****+*-*****-**-**----*-**-----**--*----*-*-***--*************************
*
*  Function Information
*
*  Name of Function: get_seed
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1.
*    2.
*    3.
*
*  Function Description: This function will get the seed value from the user and use input validation.
*
******+*-*****-**-**----*-**-----**--*----*-*-***--************************/
void findMinMaxPairs(int array[], int* minSub, int* minElement1, int* minElement2, int* minSums, int* maxSub, int* maxElement1, int* maxElement2, int* maxSums)
{
  int element1;    // index of first element in current pair
  int element2;    // index of second element in current pair
  int numSub;      // number of subtractions for current pair
  int sum;         // sum of values for current pair
  int firstValid;  // flag indicating first non-zero pair

  firstValid = 1;

  // Form pairs: (0,99), (1,98), ..., (49,50)
  for (element1 = 0, element2 = SIZE - 1; element1 < element2;
       element1++, element2--)
  {
    if (array[element1] != 0 && array[element2] != 0)
    {
      numSub = getGCD(array[element1], array[element2]);
      sum = array[element1] + array[element2];

      if (firstValid)
      {
        *minSub = numSub;
        *minElement1 = element1;
        *minElement2 = element2;
        *minSums = sum;

        *maxSub = numSub;
        *maxElement1 = element1;
        *maxElement2 = element2;
        *maxSums = sum;

        firstValid = 0;
      }
      else
      {
        if (numSub < *minSub || (numSub == *minSub && sum < *minSums))
        {
          setMin(numSub, minSub, minElement1, minElement2, element1, element2);
          *minSums = sum;
        }

        if (numSub > *maxSub || (numSub == *maxSub && sum > *maxSums))
        {
          setMax(numSub, maxSub, maxElement1, maxElement2, element1, element2);
          *maxSums = sum;
        }
      }
    }
  }

  sumNums(array[*minElement1], array[*minElement2], array[*maxElement1], array[*maxElement2], minSums, maxSums);
}
