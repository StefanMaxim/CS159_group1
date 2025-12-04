/*****+**--***-****-****-*--*-*--**--**-*---*-***--*************************
*
*  Lab #: 12
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified. Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work. We have
*  not made use of any AI generated code in this solution.
*
*  Program Description:
*    Generates a data set of random integers, removes all occurrences of a
*    user-specified digit from each value, and then examines symmetric pairs
*    of the resulting array elements. For each non-zero pair, it uses a
*    subtraction-based Euclidean algorithm to count the number of steps
*    required to reach the GCD. The program reports the pair requiring the
*    fewest subtractions and the pair requiring the most, using the sums of
*    the paired values to break ties.
*
*****+**--***-****-****-*--*-*--**--**-*---*-***--************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define RANDOM_MIN  0       /* minimum random value                  */
#define RANDOM_MAX  100000  /* maximum random value (inclusive)      */
#define TRUE 1
#define FALSE 0

int getSize(void);

int getSeed(void);

int getDigit(void);

int* makeArr(int seed, int size);

void removeDigits(int digit,int size,int arr[]);

int removeDigit(int digit,int number);

int getGCD(int element1, int element2);

void setMin(int numSub, int* minSub, int* minElement1, int* minElement2, int element1, int element2);

void setMax(int numSub, int* maxSub, int* maxElement1, int* maxElement2, int element1, int element2);

void sumNums(int arrMinElement1, int arrMinElement2, int arrMaxElement1, int arrMaxElement2, int* minSums, int* maxSums);

void printResults(int minSub, int minElement1, int minElement2, int minSums, int maxSub, int maxElement1, int maxElement2, int maxSums);

void findMinMaxPairs(int array[], int size, int* minSub, int* minElement1, int* minElement2, int* minSums, int* maxSub, int* maxElement1, int* maxElement2, int* maxSums);

int main(void)
{
  // LOCAL DECLARATIONS
  int seed; // the seed for the random number generator
  int size; //the size of the array
  int digit; //the digit in the array to remove
  int* arr; // pointer to the first element of the array which will be filled                     
  int minSub; // fewest number of subtractions to arrive at the GCD 
  int minElement1; // index of first element which gave the fewest subs  
  int minElement2; // index of second element which gave the fewest subs 
  int maxSub; // maximum number of subtractions to find GCD         
  int maxElement1; // index of first element which gave the most subs    
  int maxElement2; // index of second element which gave the most subs   
  int minSums; // sum of values for the minimum pair (with tie rule) 
  int maxSums; // sum of values for the maximum pair (with tie rule) 

  // EXECUTABLE STATEMENTS
  size = getSize();
  digit = getDigit();
  seed = getSeed();
  arr = makeArr(seed, size);
  removeDigits(digit, size, arr);

  // find pairs with minimum and maximum subtraction counts (with tie rules)
  findMinMaxPairs(arr, size, &minSub, &minElement1, &minElement2, &minSums, &maxSub, &maxElement1, &maxElement2, &maxSums);

  // display final results
  printResults(minSub, minElement1, minElement2, minSums, maxSub, maxElement1, maxElement2, maxSums);

  return 0;
}

// FUNCTION DEFINITIONS

/*****+**--*****-**-****-*--*-*--**--**-*---*-***--*************************
*
*  Function Information
*
*  Name of Function: getSize
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. N/A - this function does not take any parameters.
*    2.
*    3.
*
*  Function Description:
*    Prompts the user to enter the desired data set size and validates that
*    the value is at least 2. Re-prompts on invalid input and returns the
*    validated size to the caller.
*
******+**--*****-**-****-*--*-*--**--**-*---*-***--************************/
int getSize(void)
{
  int valid; //status of the function
  int size; //temporary size variable

  do
  {
    printf("Enter desired data set size -> ");
    scanf("%d",&size);
    if (size < 2)
    {
      printf("\nError! Size must be at least two!\n\n");
      valid = FALSE;
    }
    else
    {
      valid = TRUE;
    }
  } while (!valid);
  return size;
}

/*****+**--*****-**-****-*--*-*--**--**-*---*-***--*************************
*
*  Function Information
*
*  Name of Function: getDigit
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. N/A - this function does not take any parameters.
*    2.
*    3.
*
*  Function Description:
*    Prompts the user to enter a single decimal digit to be removed from all
*    numbers in the data set. Validates that the value is between 0 and 9,
*    inclusive, re-prompts on invalid input, and returns the validated digit.
*
******+**--*****-**-****-*--*-*--**--**-*---*-***--************************/
int getDigit(void)
{
  int digit; //temp value of the digit
  int valid; //status of the function
  do
  {
    printf("Enter digit to remove from data -> ");
    scanf("%d",&digit);
    if (digit > 9 || digit < 0)
    {
      printf("\nError! Value must be a single non-negative digit!\n\n");
      valid = FALSE;
    }
    else
    {
      valid = TRUE;
    }
    
  } while (!valid);
  return digit;
  
}

/*****+*-*****-**-**----*-**-----**--*----*-*-***--*************************
*
*  Function Information
*
*  Name of Function: getSeed
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. N/A - this function does not take any parameters.
*
*  Function Description:
*    Prompts the user to enter a non-negative integer seed value for the
*    random number generator. Performs input validation and repeats the
*    prompt until a valid (non-negative) integer is entered. Returns the
*    validated seed to the caller.
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
*  Name of Function: makeArr
*
*  Function Return Type: int*
*
*  Parameters (list data type, name, and comment one per line):
*    1. int seed - seed value used to initialize the random number
*                  generator.
*    2. int size - number of elements to allocate and fill in the array.
*
*  Function Description:
*    Dynamically allocates an integer array of length size, initializes the
*    random number generator with the provided seed, and fills each element
*    with a random integer in the range RANDOM_MIN to RANDOM_MAX (inclusive).
*    Returns a pointer to the newly allocated and initialized array.
*
******+*-*****-**-**----*-**-----**--*----*-*-***--************************/
int* makeArr(int seed, int size)
{
  int i;  // loop counter
  int* array; //pointer to the array created via malloc

  array = (int *) malloc(size * sizeof(int));
  srand(seed);  // seed the random number generator

  for (i = 0; i < size; i++)
  {
    // RANDOM_MIN is 0, so we only need to ensure the upper bound
    array[i] = rand() % (RANDOM_MAX + 1);
  }
  return array;
}

/*****+**--*****-**-****-*--*-*--**--**-*---*-***--*************************
*
*  Function Information
*
*  Name of Function: removeDigits
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int digit - digit to be removed from each integer in the array.
*    2. int size  - number of elements in the array.
*    3. int arr[] - array of integers to be processed in place.
*
*  Function Description:
*    Iterates through the array of length size and replaces each element
*    with the result of calling removeDigit on that value. All occurrences
*    of the specified digit are removed from every array element.
*
******+**--*****-**-****-*--*-*--**--**-*---*-***--************************/
void removeDigits(int digit,int size,int arr[])
{
  int i; //loop variable

  for (i = 0;i < size; i++)
  {
    arr[i] = removeDigit(digit,arr[i]);
  }
}
/*****+**--*****-**-****-*--*-*--**--**-*---*-***--*************************
*
*  Function Information
*
*  Name of Function: removeDigit
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int digit  - digit to be removed from the given number.
*    2. int number - original integer from which digit occurrences are
*                    removed.
*    3.
*
*  Function Description:
*    Constructs and returns a new integer formed by removing all digits
*    equal to digit from number. The remaining digits keep their original
*    relative order, and no leading zeros are preserved beyond what the
*    resulting value naturally has.
*
******+**--*****-**-****-*--*-*--**--**-*---*-***--************************/
int removeDigit(int digit,int number)
{
  int removed; // the removed integer
  int temp_num; //the temporary digit in the number
  int i; //looping variable

  removed = 0;
  i = 0;
  while (number > 0)
  {
    temp_num = number % 10;
    if (temp_num != digit)
    {
      removed += temp_num * pow(10,i);
      i++;
    }
    number /= 10;
  }
  return removed;
}

/*****+*-*****-**-**----*-**-----**--*----*-*-***--*************************
*
*  Function Information
*
*  Name of Function: getGCD
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int element1 - first integer whose GCD with element2 is considered.
*    2. int element2 - second integer whose GCD with element1 is considered.
*
*  Function Description:
*    Uses the subtraction-based form of the Euclidean algorithm on the
*    two input integers. Counts how many subtractions are required until
*    the two values become equal (the GCD). Assumes both values are
*    non-zero before the function is called. Returns the number of
*    subtraction operations performed.
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
*  Name of Function: setMin
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int numSub       - number of subtractions for the current pair.
*    2. int* minSub      - pointer to the current minimum subtraction count.
*    3. int* minElement1 - pointer to index of first element in min pair.
*    4. int* minElement2 - pointer to index of second element in min pair.
*    5. int element1     - index of the first element in the new min pair.
*    6. int element2     - index of the second element in the new min pair.
*
*  Function Description:
*    Updates the tracking variables that store information about the pair
*    of array elements requiring the fewest subtractions to reach their
*    GCD. The new minimum count and corresponding indices are written
*    through the pointer parameters.
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
*  Name of Function: setMax
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int numSub       - number of subtractions for the current pair.
*    2. int* maxSub      - pointer to the current maximum subtraction count.
*    3. int* maxElement1 - pointer to index of first element in max pair.
*    4. int* maxElement2 - pointer to index of second element in max pair.
*    5. int element1     - index of the first element in the new max pair.
*    6. int element2     - index of the second element in the new max pair.
*
*  Function Description:
*    Updates the tracking variables that store information about the pair
*    of array elements requiring the most subtractions to reach their GCD.
*    The new maximum count and corresponding indices are written through
*    the pointer parameters.
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
*  Name of Function: sumNums
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int arrMinElement1 - value at index of first element in min pair.
*    2. int arrMinElement2 - value at index of second element in min pair.
*    3. int arrMaxElement1 - value at index of first element in max pair.
*    4. int arrMaxElement2 - value at index of second element in max pair.
*    5. int* minSums       - pointer to store sum of minimum pair values.
*    6. int* maxSums       - pointer to store sum of maximum pair values.
*
*  Function Description:
*    Computes the sums of the array values for the minimum and maximum
*    pairs. Writes the sum of the minimum pair into *minSums and the sum
*    of the maximum pair into *maxSums.
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
*  Name of Function: printResults
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int minSub       - minimum number of subtractions observed.
*    2. int minElement1  - index of first element in minimum pair.
*    3. int minElement2  - index of second element in minimum pair.
*    4. int minSums      - sum of values in the minimum pair.
*    5. int maxSub       - maximum number of subtractions observed.
*    6. int maxElement1  - index of first element in maximum pair.
*    7. int maxElement2  - index of second element in maximum pair.
*    8. int maxSums      - sum of values in the maximum pair.
*
*  Function Description:
*    Prints a formatted summary of the results to the screen, including
*    the minimum and maximum number of subtractions and the indices and
*    sums of the pairs that produced those counts.
*
******+*-*****-**-**----*-**-----**--*----*-*-***--************************/
void printResults(int minSub, int minElement1, int minElement2, int minSums, int maxSub, int maxElement1, int maxElement2, int maxSums)
{
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Minimum number of subtractions: %d\n", minSub);
  printf("Elements at index %02d and %02d create sum: %d\n", minElement1, minElement2, minSums);
  printf("\nMaximum number of subtractions: %d\n", maxSub);
  printf("Elements at index %02d and %02d create sum: %d\n", maxElement1, maxElement2, maxSums);
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
}

/*****+*-*****-**-**----*-**-----**--*----*-*-***--*************************
*
*  Function Information
*
*  Name of Function: findMinMaxPairs
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int array[]      - array of size integers to be processed.
*    2. int* minSub      - pointer to store minimum subtraction count.
*    3. int* minElement1 - pointer to store index of first element in
*                          minimum pair.
*    4. int* minElement2 - pointer to store index of second element in
*                          minimum pair.
*    5. int* minSums     - pointer to store sum of values in minimum pair.
*    6. int* maxSub      - pointer to store maximum subtraction count.
*    7. int* maxElement1 - pointer to store index of first element in
*                          maximum pair.
*    8. int* maxElement2 - pointer to store index of second element in
*                          maximum pair.
*    9. int* maxSums     - pointer to store sum of values in maximum pair.
*
*  Function Description:
*    Forms symmetric pairs of elements from the array, starting with
*    (0, size-1), (1, size-2), ..., (size/2 - 1, size/2). For each pair
*    where neither value is zero, calls getGCD to determine the number of
*    subtractions needed to reach the GCD. Tracks the pair that uses the
*    fewest subtractions and the pair that uses the most, using sum-based
*    tie-breaking rules. At the end, updates minSub, maxSub, and related
*    index and sum variables through the pointer parameters.
*
******+*-*****-**-**----*-**-----**--*----*-*-***--************************/
void findMinMaxPairs(int array[], int size, int* minSub, int* minElement1, int* minElement2, int* minSums, int* maxSub, int* maxElement1, int* maxElement2, int* maxSums)
{
  int element1;    // index of first element in current pair
  int element2;    // index of second element in current pair
  int numSub;      // number of subtractions for current pair
  int sum;         // sum of values for current pair
  int firstValid;  // flag indicating first non-zero pair

  firstValid = 1;

  // Form pairs: (0,99), (1,98), ..., (49,50)
  element1 = 0;
  for (element2 = size - 1; element1 < element2; element2--)
  {
    // only process pairs where both values are non-zero
    if (array[element1] != 0 && array[element2] != 0)
    {
      numSub = getGCD(array[element1], array[element2]);
      sum = array[element1] + array[element2];

      if (firstValid)
      {
        // initialize min and max with the first valid pair
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
        // update minimum pair: fewer subs OR same subs but smaller sum
        if (numSub < *minSub || (numSub == *minSub && sum < *minSums))
        {
          setMin(numSub, minSub, minElement1, minElement2, element1, element2);
          *minSums = sum;
        }

        // update maximum pair: more subs OR same subs but larger sum
        if (numSub > *maxSub || (numSub == *maxSub && sum > *maxSums))
        {
          setMax(numSub, maxSub, maxElement1, maxElement2, element1, element2);
          *maxSums = sum;
        }
      }
    }
    element1++;
  }

  // Recompute and store final sums using the selected indices
  sumNums(array[*minElement1], array[*minElement2], array[*maxElement1], array[*maxElement2], minSums, maxSums);
}
