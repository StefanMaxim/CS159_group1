#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*****+*--****-****-**-*-*------**--**----*-*-***--*************************
*
*  Homework #:
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified. Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work. I have not 
*  made use of any AI generated code in this solution. 
*
*  Program Description: This program generates a user-specified number of 
*  pseudo-random integers within an input range, converts each to its binary 
*  representation, and counts the number of 1-bits. It tracks and reports: 
*  the value with the most 1s, the value with the fewest 1s, the corresponding 
*  1-bit counts, and how many generated values have an even vs. odd number of 1-bits.
******+*--****-****-**-*-*------**--**----*-*-***--************************/

//Global Declarations
void input(int* seedValue, int* numValues, int* min, int* max);
void output(int mostOnes, int fewestOnes, int numWithMostOnes, int numWithFewestOnes, int numEvenOnes, int numOddOnes);
void calculateStatistics(int seedValue, int numValues, int min, int max, int* numWithMostOnes, int* numWithFewestOnes, int* mostOnes, int* fewestOnes, int* numEvenOnes, int* numOddOnes);
int generateNum(int min, int max); //need to check bounds here
int convertToBinary(int num);
void generateStatistics(int number, int binaryNum, int* numWithMostOnes, int* numWithFewestOnes, int* mostOnes, int* fewestOnes, int* numEvenOnes, int* numOddOnes);
void updateStatistics(int number, int binaryNum, int* numWithMostOnes, int* numWithFewestOnes, int* mostOnes,int* fewestOnes, int* numEvenOnes, int* numOddOnes);
int countOnes(int binaryNum);


int main()
{
  int seedValue; //the user's selected seed
  int numValues; //The number of values the user wants to generate
  int min; //the minimum random value to generate
  int max; //the maximum random number to generate
  int mostOnes; // the actual number of ones in the number with most ones
  int fewestOnes; //the acutal numner of ones in the numner with the fewest ones
  int numEvenOnes; //the number of even ones
  int numOddOnes; //the number of odd ones
  int numWithMostOnes; //the number with the most ones
  int numWithFewestOnes; //the number with the fewest ones
  
  input(&seedValue, &numValues, &min, &max);
  calculateStatistics(seedValue, numValues, min, max, &numWithMostOnes, &numWithFewestOnes, &mostOnes, &fewestOnes, &numEvenOnes, &numOddOnes);
  output(mostOnes, fewestOnes, numWithMostOnes, numWithFewestOnes, numEvenOnes, numOddOnes);
  return 0;
}

/*****+**--***-****-**-*-*------**--**----*-*-***--*************************
*
*  Function Information
*
*  Name of Function: calculateStatistics
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int seedValue             : RNG seed used for reproducibility
*    2. int numValues             : how many random values to generate
*    3. int min                   : inclusive lower bound for random values
*    4. int max                   : inclusive upper bound for random values
*    5. int* numWithMostOnes      : out-param; value having the most 1-bits
*    6. int* numWithFewestOnes    : out-param; value having the fewest 1-bits
*    7. int* mostOnes             : out-param; max 1-bit count observed
*    8. int* fewestOnes           : out-param; min 1-bit count observed
*    9. int* numEvenOnes          : out-param; count of values with even 1-bits
*   10. int* numOddOnes           : out-param; count of values with odd 1-bits
*
*  Function Description:
*    Seeds the RNG and iterates numValues times. Each iteration generates a
*    random integer in [min, max], converts it to a decimal-encoded binary
*    representation, and either initializes or updates tracking statistics
*    for max/min counts of 1-bits and parity (even/odd) tallies.
*
******+**--***-****-**-*-*------**--**----*-*-***--************************/
void calculateStatistics(int seedValue, int numValues, int min, int max, int* numWithMostOnes, int* numWithFewestOnes, int* mostOnes,int* fewestOnes, int* numEvenOnes, int* numOddOnes)
{
  int i; //looping variable
  int number; //the individual number being generated
  int binaryNum; //the number converted to binary


  srand(seedValue);
  for (i=0;i<numValues;i++)
  {
    number = generateNum(min,max);
    binaryNum = convertToBinary(number);
    if (i == 0)
    {
      generateStatistics(number, binaryNum, numWithMostOnes, numWithFewestOnes, mostOnes, fewestOnes, numEvenOnes, numOddOnes);
    }
    else
    {
      updateStatistics(number, binaryNum, numWithMostOnes, numWithFewestOnes, mostOnes, fewestOnes, numEvenOnes, numOddOnes);
    }
    
  }
}

/*****+**--***-****-**-*-*------**--**----*-*-***--*************************
*
*  Function Information
*
*  Name of Function: generateNum
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int min : inclusive lower bound
*    2. int max : inclusive upper bound
*
*  Function Description:
*    Returns a uniformly distributed pseudo-random integer in the closed
*    interval [min, max]. Assumes 0 <= min <= max and that max - min
*    fits within int range.
*
******+**--***-****-**-*-*------**--**----*-*-***--************************/
int generateNum(int min, int max)
{
  return (rand() % (max - min + 1)) + min;
}


/*****+**--***-****-**-*-*------**--**----*-*-***--*************************
*
*  Function Information
*
*  Name of Function: convertToBinary
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int num : non-negative integer to convert
*
*  Function Description:
*    Converts num to a decimal-encoded binary representation (e.g., 13 -> 1101)
*    by repeatedly taking num % 2 and building the result with powers of 10.
*    This representation is used later to count 1-digits conveniently.
*    Returns 0 when num == 0.
*
******+**--***-****-**-*-*------**--**----*-*-***--************************/
int convertToBinary(int num)
{
  int binaryNum; //the obtained binary number
  int digit; // the digit to append
  int place; //the place of the digit in the number

  place = 1;
  binaryNum = 0;
  while (num > 0)
  {
    digit = num%2;
    binaryNum += digit * place;
    place *= 10;
    num /= 2;
  }
  return binaryNum;
}

/*****+**--***-****-**-*-*------**--**----*-*-***--*************************
*
*  Function Information
*
*  Name of Function: generateStatistics
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int number               : first generated value
*    2. int binaryNum            : decimal-encoded binary digits of number
*    3. int* numWithMostOnes     : out-param initialized to number
*    4. int* numWithFewestOnes   : out-param initialized to number
*    5. int* mostOnes            : out-param initialized to this number's 1-bit count
*    6. int* fewestOnes          : out-param initialized to this number's 1-bit count
*    7. int* numEvenOnes         : out-param initialized to 1 if count is even, else 0
*    8. int* numOddOnes          : out-param initialized to 1 if count is odd,  else 0
*
*  Function Description:
*    Handles the very first sample by establishing baseline statistics:
*    both the "most" and "fewest" records are set to this number and its
*    1-bit count, and parity tallies are initialized based on that count.
*
******+**--***-****-**-*-*------**--**----*-*-***--************************/
void generateStatistics(int number, int binaryNum, int* numWithMostOnes, int* numWithFewestOnes, int* mostOnes,int* fewestOnes, int* numEvenOnes, int* numOddOnes)
{
  int numOnes; //the number of ones in the number;
  

  numOnes = countOnes(binaryNum); 
  *numWithMostOnes = number;
  *numWithFewestOnes = number;
  *mostOnes = numOnes;
  *fewestOnes = numOnes;
  if (numOnes % 2 == 0)
  {
    *numEvenOnes = 1;
    *numOddOnes = 0;
  }
  else
  {
    *numEvenOnes = 0;
    *numOddOnes = 1;
  }
}

/*****+**--***-****-**-*-*------**--**----*-*-***--*************************
*
*  Function Information
*
*  Name of Function: updateStatistics
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int number               : newly generated value
*    2. int binaryNum            : decimal-encoded binary digits of number
*    3. int* numWithMostOnes     : updated if current 1-bit count exceeds max
*    4. int* numWithFewestOnes   : updated if current 1-bit count is a new min
*    5. int* mostOnes            : maximum 1-bit count seen so far
*    6. int* fewestOnes          : minimum 1-bit count seen so far
*    7. int* numEvenOnes         : incremented if current count is even
*    8. int* numOddOnes          : incremented if current count is odd
*
*  Function Description:
*    Incorporates one additional sample into the running statistics. Compares
*    the new 1-bit count to current extrema, updates the associated number
*    when a new max/min is found, and increments the even/odd tally.
*
******+**--***-****-**-*-*------**--**----*-*-***--************************/
void updateStatistics(int number, int binaryNum, int* numWithMostOnes, int* numWithFewestOnes, int* mostOnes,int* fewestOnes, int* numEvenOnes, int* numOddOnes)
{
  int numOnes; //the number of ones in the number;
  
  numOnes = countOnes(binaryNum);
  if (numOnes > *mostOnes)
  {
    *mostOnes = numOnes;
    *numWithMostOnes = number;
  }
  if (numOnes < *fewestOnes)
  {
    *fewestOnes = numOnes;
    *numWithFewestOnes = number;
  }
  if(numOnes % 2 == 0)
  {
    *numEvenOnes = *numEvenOnes + 1;
  }
  else
  {
    *numOddOnes = *numOddOnes + 1;
  }

}


/*****+**--***-****-**-*-*------**--**----*-*-***--*************************
*
*  Function Information
*
*  Name of Function: countOnes
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int binaryNum : decimal-encoded binary digits (e.g., 1101)
*
*  Function Description:
*    Counts how many digits equal 1 in the decimal-encoded binary value.
*    Iteratively strips the last digit with % 10 and increments a counter
*    when that digit is 1. Returns the total number of 1-bits.
*
******+**--***-****-**-*-*------**--**----*-*-***--************************/
int countOnes(int binaryNum)
{
  int numOnes; //the number of ones
  int digit; //the digit in the binary number

  numOnes = 0;
  while (binaryNum > 0)
  {
    digit = binaryNum% 10;
    if (digit == 1)
    {
      numOnes++;
    }
    binaryNum /= 10;
  }
  return numOnes;
}

/*****+**--***-****-**-*-*------**--**----*-*-***--*************************
*
*  Function Information
*
*  Name of Function: input
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int* seedValue : out-param; validated non-negative RNG seed
*    2. int* numValues : out-param; validated count in [10, 100]
*    3. int* min       : out-param; validated minimum in [0, 999]
*    4. int* max       : out-param; validated maximum in (min, 999]
*
*  Function Description:
*    Prompts for and validates all user inputs according to the assignment
*    constraints. Re-prompts on invalid entries. On success, writes results
*    to the provided pointers.
*
******+**--***-****-**-*-*------**--**----*-*-***--************************/
void input(int* seedValue, int* numValues, int* min, int* max)
{
  int tempSeed; //the temporary seed value
  int tempNumValues; //the temporary number of values
  int tempMin; //the temporary min value
  int tempMax; //the temporary max value

  do
  {
    printf("Please enter a non-negative seed value -> ");
    scanf("%d",&tempSeed);
    if(tempSeed < 0)
    {
      printf("\nError! Seed value must be non-negative.\n\n");
    }
  } while(tempSeed < 0);

  do
  {
    printf("Enter number of values between 10 and 100 inclusive to generate -> ");
    scanf("%d", &tempNumValues);
    if (tempNumValues < 10 || tempNumValues > 100)
    {
      printf("\nError! The number of values must be between 10 and 100 inclusive.\n\n");
    }
  } while (tempNumValues < 10 || tempNumValues > 100);

  do
  {
    printf("Enter minimum random value between 0 and 999 inclusive -> ");
    scanf("%d",&tempMin);
    if (tempMin < 0 || tempMin > 999)
    {
      printf("\nError! The minimum must be between 0 and 999 inclusive.\n\n");
    }
  } while(tempMin < 0 || tempMin > 999);

  do
  {
    printf("Enter maximum random value between 300 exclusive and 999 inclusive -> ");
    scanf("%d",&tempMax);
    if (tempMax <= tempMin || tempMax > 999)
    {
      printf("\nError! The maximum must be between %d exclusive and 999 inclusive.\n\n",tempMin);
    }
  } while (tempMax <= tempMin || tempMax > 999);

  *seedValue = tempSeed;
  *numValues = tempNumValues;
  *min = tempMin;
  *max = tempMax;
}

/*****+**--***-****-**-*-*------**--**----*-*-***--*************************
*
*  Function Information
*
*  Name of Function: output
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int mostOnes         : maximum 1-bit count observed
*    2. int fewestOnes       : minimum 1-bit count observed
*    3. int numWithMostOnes  : value that achieved mostOnes
*    4. int numWithFewestOnes: value that achieved fewestOnes
*    5. int numEvenOnes      : how many values had an even number of 1-bits
*    6. int numOddOnes       : how many values had an odd number of 1-bits
*
*  Function Description:
*    Prints a formatted summary report of the computed statistics: the values
*    that achieved the maximum and minimum 1-bit counts (and those counts),
*    plus tallies for even and odd 1-bit occurrences among all generated values.
*
******+**--***-****-**-*-*------**--**----*-*-***--************************/
void output(int mostOnes, int fewestOnes, int numWithMostOnes, int numWithFewestOnes, int numEvenOnes, int numOddOnes)
{
  printf("\n");
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Number with most 1s (%d): %d\n",mostOnes,numWithMostOnes);
  printf("Number with fewest 1s (%d): %d\n",fewestOnes,numWithFewestOnes);
  printf("Numbers with even number of 1s: %d\n",numEvenOnes);
  printf("Numbers with odd number of 1s: %d\n",numOddOnes);
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
}






















