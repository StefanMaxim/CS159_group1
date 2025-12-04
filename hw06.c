/*****+*--********--****-**-*-*-***-***-*---*-***--*************************
*
*  Homework #: 6
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
*  This program prompts the user for a non-negative integer seed value and
*  uses it to generate 50 random three-digit integers in the range 100–999.
*  For each integer, the program computes the sum of its even digits and
*  the sum of its odd digits, then classifies the value as even-heavy,
*  odd-heavy, or balanced. After processing all values, the program prints
*  the total counts for each category and lists the values in each category
*  in rows of up to five numbers, omitting any category that has no values.
*
******+*--********--****-**-*-*-***-***-*---*-***--************************/
#include <stdio.h>
#include <stdlib.h>

#define NUM_VALUES 50 // Total number of random values to generate 
#define VALUES_PER_ROW 5 // Number of values to print per row 
#define MIN_RANDOM 100 // Minimum random value (inclusive) 
#define MAX_RANDOM 999 // Maximum random value (inclusive) 

//Function Declarations
int getSeed(void);
int classifyingValue(int value);
void generateAndClassifyValues(int seedValue, int evenArray[], int* evenCount, int oddArray[], int* oddCount, int balancedArray[], int* balancedCount);
void printCategoryRows(int categoryArray[], int count);
void printResults(int evenArray[], int evenCount, int oddArray[], int oddCount, int balancedArray[], int balancedCount);

int main(void)
{
  // Local variable declarations 
  int seedValue;                       // value of the seed
  int evenHeavyValues[NUM_VALUES];     // array for even-heavy values 
  int oddHeavyValues[NUM_VALUES];      // array for odd-heavy values 
  int balancedValues[NUM_VALUES];      // array for balanced values 
  int evenCount;                       // count of even-heavy values 
  int oddCount;                        // count of odd-heavy values 
  int balancedCount;                   // count of balanced values 

  //Executable Statments
  seedValue = getSeed();

  generateAndClassifyValues(seedValue, evenHeavyValues, &evenCount, oddHeavyValues, &oddCount, balancedValues, &balancedCount);

  printResults(evenHeavyValues, evenCount, oddHeavyValues, oddCount, balancedValues, balancedCount);

  return 0;
}

/*****+*--********--****-**-*-*-***-***-*---*-***--*************************
*
*  Function Information
*
*  Name of Function: getSeed
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. (none) - this function does not receive any parameters.
*
*  Function Description:
*
*  Prompts the user to enter a non-negative seed value for the random
*  number generator. If the user enters a negative value, an error
*  message is displayed and the user is prompted again. The function
*  returns the validated non-negative seed value to the calling function.
*
******+*--********--****-**-*-*-***-***-*---*-***--************************/
int getSeed(void)
{
  int seed;  //Temp seed variable

  do
  {
    printf("Enter non-negative seed value -> ");
    scanf("%d", &seed);
    if (seed < 0)
    {
      printf("\nError! Seed value must be non-negative!!\n\n");
    }
  } while (seed < 0);

  return seed;
}
/*****+*--********--****-**-*-*-***-***-*---*-***--*************************
*
*  Function Information
*
*  Name of Function: classifyingValue
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int value - three-digit integer to be classified.
*
*  Function Description:
*
*  Separates the given three-digit integer into its hundreds, tens, and
*  ones digits. It computes the sum of all even digits and the sum of all
*  odd digits. If the even-digit sum is greater, the function returns 0
*  (even-heavy). If the odd-digit sum is greater, the function returns 1
*  (odd-heavy). If the sums are equal, the function returns 2 (balanced).
*
******+*--********--****-**-*-*-***-***-*---*-***--************************/
int classifyingValue(int value)
{
  int hundredsDigit;   // hundreds digit 
  int tensDigit;       // tens digit 
  int onesDigit;       // ones digit 
  int sumEvenDigits;   // sum of even digits
  int sumOddDigits;    // sum of odd digits 
  int status; //the status to return

  hundredsDigit = value / 100;
  tensDigit = (value / 10) % 10;
  onesDigit = value % 10;

  sumEvenDigits = 0;
  sumOddDigits = 0;

  if (hundredsDigit % 2 == 0)
  {
    sumEvenDigits = sumEvenDigits + hundredsDigit;
  }
  else
  {
    sumOddDigits = sumOddDigits + hundredsDigit;
  }

  if (tensDigit % 2 == 0)
  {
    sumEvenDigits = sumEvenDigits + tensDigit;
  }
  else
  {
    sumOddDigits = sumOddDigits + tensDigit;
  }

  if (onesDigit % 2 == 0)
  {
    sumEvenDigits = sumEvenDigits + onesDigit;
  }
  else
  {
    sumOddDigits = sumOddDigits + onesDigit;
  }

  if (sumEvenDigits > sumOddDigits)
  {
    status = 0;  
  }
  else if (sumOddDigits > sumEvenDigits)
  {
    status = 1;  
  }
  else
  {
    status = 2; 
  }

  return status;
}
/*****+*--********--****-**-*-*-***-***-*---*-***--*************************
*
*  Function Information
*
*  Name of Function: generateAndClassifyValues
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int seedValue        - seed value used to initialize rand().
*    2. int evenArray[]      - array to store even-heavy values.
*    3. int *evenCount       - pointer to count of even-heavy values.
*    4. int oddArray[]       - array to store odd-heavy values.
*    5. int *oddCount        - pointer to count of odd-heavy values.
*    6. int balancedArray[]  - array to store balanced values.
*    7. int *balancedCount   - pointer to count of balanced values.
*
*  Function Description:
*
*  Initializes the random number generator with the given seed value and
*  then generates NUM_VALUES random integers in the range MIN_RANDOM to
*  MAX_RANDOM inclusive. Each value is classified as even-heavy, odd-heavy,
*  or balanced by calling classifyingValue, and then stored in the
*  appropriate array. The associated count variables for each category
*  are updated through the pointer parameters.
*
******+*--********--****-**-*-*-***-***-*---*-***--************************/
void generateAndClassifyValues(int seedValue, int evenArray[], int* evenCount, int oddArray[], int* oddCount, int balancedArray[], int* balancedCount)
{
  int index;           // loop index 
  int currentValue;    // current random value 
  int classification;  // classification code for current value 

  *evenCount = 0;
  *oddCount = 0;
  *balancedCount = 0;

  srand(seedValue);

  for (index = 0; index < NUM_VALUES; index = index + 1)
  {
    currentValue = rand() % (MAX_RANDOM - MIN_RANDOM + 1) + MIN_RANDOM;

    classification = classifyingValue(currentValue);

    if (classification == 0)
    {
      evenArray[*evenCount] = currentValue;
      *evenCount = *evenCount + 1;
    }
    else if (classification == 1)
    {
      oddArray[*oddCount] = currentValue;
      *oddCount = *oddCount + 1;
    }
    else
    {
      balancedArray[*balancedCount] = currentValue;
      *balancedCount = *balancedCount + 1;
    }
  }
}
/*****+*--********--****-**-*-*-***-***-*---*-***--*************************
*
*  Function Information
*
*  Name of Function: printCategoryRows
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int categoryArray[] - array of values for a single category.
*    2. int count           - number of valid elements in the array.
*
*  Function Description:
*
*  Prints the values stored in the given category array in rows of up to
*  VALUES_PER_ROW values. Each row begins with "Row X:" where X is the
*  row number starting at 1, followed by the values aligned using a fixed
*  field width. A newline is printed at the end of each row.
*
******+*--********--****-**-*-*-***-***-*---*-***--************************/
void printCategoryRows(int categoryArray[], int count)
{
  int index;      // index in the category array
  int rowNumber;  // current row number 

  rowNumber = 1;

  for (index = 0; index < count; index = index + 1)
  {
    if (index % VALUES_PER_ROW == 0)
    {
      printf("Row %d:", rowNumber);
      rowNumber = rowNumber + 1;
    }

    printf("%5d", categoryArray[index]);

    if (index % VALUES_PER_ROW == VALUES_PER_ROW - 1 || index == count - 1)
    {
      printf("\n");
    }
  }
}
/*****+*--********--****-**-*-*-***-***-*---*-***--*************************
*
*  Function Information
*
*  Name of Function: printResults
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int evenArray[]      - array of even-heavy values.
*    2. int evenCount        - number of even-heavy values.
*    3. int oddArray[]       - array of odd-heavy values.
*    4. int oddCount         - number of odd-heavy values.
*    5. int balancedArray[]  - array of balanced values.
*    6. int balancedCount    - number of balanced values.
*
*  Function Description:
*
*  Prints the total counts for the even-heavy, odd-heavy, and balanced
*  categories. Then, for each category that contains at least one value,
*  prints a category header line followed by the values using the
*  printCategoryRows function. Categories with zero values are omitted
*  from the detailed listing.
*
******+*--********--****-**-*-*-***-***-*---*-***--************************/
void printResults(int evenArray[], int evenCount, int oddArray[], int oddCount, int balancedArray[], int balancedCount)
{
  printf("\nTotal Even-heavy: %d\n", evenCount);
  printf("Total Odd-heavy : %d\n", oddCount);
  printf("Total Balanced  : %d\n\n", balancedCount);

  if (evenCount > 0)
  {
    printf("-=-=- Even-heavy Numbers -=-=-\n"); 
    printCategoryRows(evenArray, evenCount);
  }

  if (oddCount > 0)
  {
    printf("-=-=- Odd-heavy Numbers -=-=-\n");
    printCategoryRows(oddArray, oddCount);
  }

  if (balancedCount > 0)
  {
    printf("-=-=-=- Balanced Numbers -=-=-=-\n");
    printCategoryRows(balancedArray, balancedCount);
  }
}