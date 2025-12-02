/*****+**--***-****-****-*--*-*--**--**-*---*-***--*************************
*
*  Lab #: 11
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified. Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work. We have
*  not made use of any AI generated code in this solution.
*
*  Program Description:
*    Generates random temperature, humidity, and dew point data, sorts the
*    values according to a user-selected criterion, and displays a specified
*    index range of the data in a formatted table.
*
*
*****+**--***-****-****-*--*-*--**--**-*---*-***--************************/

#include<stdio.h>
#include<stdlib.h>

#define SIZE 200
#define MINVALUE 30
#define MAXVALUE 100
#define FIVE 5.0
#define NINE 9.0
#define THIRTYTWO 32.0
#define ONEHUNDRED 100.0

int getSeed(void);
int getSortOption(void);
void getIndices(int* mindex, int* maxdex);
void makeArray(int* temp_arr, int* hum_arr, double* dew_arr, int seed);
void sortArrays(int* temp_arr, int* hum_arr, double* dew_arr, int sortOption);
void insertionSort(int* primaryArr, int* secondaryArr, double* tertiaryArr);
void insertionSort2(double* primaryArr, int* secondaryArr, int* tertiaryArr);
void printResults(int mindex, int maxdex, int sortOption, int* temp_arr, int* hum_arr, double* dew_arr);
void printLine(int index, int* temp_arr, int* hum_arr, double* dew_arr);

int main()
{
  //Local Declarations
  int seed; //seed provided by the user
  int sortOption; //the user's choice of sorting style, where 1 => temp, 2 => humidity, 3 => dewpoint

  int mindex; //the minimum index to display (inclusive)
  int maxdex; //the maximum index to display (inclusive)

  int temp_arr[SIZE]; // the array containing the temperature values
  int hum_arr[SIZE]; // the array containing the humidity values
  double dew_arr[SIZE]; //the array containing the dew point values

  //Execution
  seed = getSeed();

  sortOption = getSortOption();

  getIndices(&mindex,&maxdex);

  makeArray(temp_arr,hum_arr,dew_arr, seed);

  sortArrays(temp_arr, hum_arr, dew_arr, sortOption);

  printResults(mindex,maxdex,sortOption,temp_arr, hum_arr,dew_arr);

  return 0;
}

/*****+**--*****-**-****-*--*-*--**--**-*---*-***--*************************
*
*  Function Information
*
*  Name of Function: getSeed
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. None - this function does not take any parameters.
*    2. N/A
*    3. N/A
*
*  Function Description:
*    Prompts the user for a positive integer seed value and validates the
*    input. Repeats until a valid seed is entered, then returns the seed.
*
******+**--*****-**-****-*--*-*--**--**-*---*-***--************************/
int getSeed(void)
{
  int seed; //local variable for the seed

  do
  {
    printf("Enter positive integer seed value -> ");
    scanf("%d",&seed);

    if (seed <= 0)
    {
      printf("\nError! Seed must be positive!\n\n");
    }
  } while (seed <= 0);

  return seed;
}

/*****+**--*****-**-****-*--*-*--**--**-*---*-***--*************************
*
*  Function Information
*
*  Name of Function: getSortOption
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. None - this function does not take any parameters.
*    2. N/A
*    3. N/A
*
*  Function Description:
*    Prompts the user for the sorting option (1=temperature, 2=humidity,
*    3=dew point), validates that the choice is in range, and returns it.
*
******+**--*****-**-****-*--*-*--**--**-*---*-***--************************/
int getSortOption(void)
{
  int option; //local variable for the seed

  do
  {
    printf("Sort the data by (1) temperature, (2) humidity, (3) dew point -> ");
    scanf("%d",&option);

    if (option <= 0 || option > 3)
    {
      printf("\nError! Invalid choice.\n\n");
    }
  } while (option <= 0 || option > 3);

  return option;
}

/*****+**--*****-**-****-*--*-*--**--**-*---*-***--*************************
*
*  Function Information
*
*  Name of Function: getIndices
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int *mindex - pointer to store the minimum index to display.
*    2. int *maxdex - pointer to store the maximum index to display.
*    3. N/A
*
*  Function Description:
*    Prompts the user for minimum and maximum index values to display,
*    validating that they are within the valid array range and that the
*    maximum is not less than the minimum. Stores results via pointers.
*
******+**--*****-**-****-*--*-*--**--**-*---*-***--************************/
void getIndices(int* mindex, int* maxdex)
{
  int temp_mindex; //temp value for mindex
  int temp_maxdex; //temp value for maxdex
  int done; //boolean for status of check.

  do
  {
    printf("Enter minimum index value to display -> ");

    scanf("%d",&temp_mindex);

    done = 1;
    if (temp_mindex < 0)
    {
      printf("\nError! Minimum index value is zero.\n\n");
      done = 0;
    }
    else if (temp_mindex >= SIZE)
    {
      printf("\nError! Minimum index value cannot exceed valid index range.\n\n");
      done = 0;
    }
    else if (temp_mindex > SIZE - 2)
    {
      printf("\nError! Minimum index value must allow for a minimum of two values for display.\n\n");
      done = 0;
    }
  } while (!done);

  do
  {
    printf("Enter maximum index value to display -> ");
    scanf("%d",&temp_maxdex);
    done = 1;
    if (temp_maxdex < temp_mindex)
    {
      printf("\nError! Maximum index value must be greater than %d.\n\n",temp_mindex);
      done = 0;
    }
    else if (temp_maxdex >= SIZE)
    {
      printf("\nError! Maximum index value cannot exceed valid index range.\n\n");
      done = 0;
    }
  } while (!done);

  *mindex = temp_mindex;
  *maxdex = temp_maxdex;
}

/*****+**--*****-**-****-*--*-*--**--**-*---*-***--*************************
*
*  Function Information
*
*  Name of Function: makeArray
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int *temp_arr - array to store generated temperature values (F).
*    2. int *hum_arr  - array to store generated humidity values (%).
*    3. double *dew_arr - array to store computed dew point values (F).
*
*  Function Description:
*    Uses the provided random seed to generate SIZE temperature and humidity
*    values within the specified range. Converts temperatures to Celsius,
*    computes the dew point in Celsius using humidity, converts the dew point
*    back to Fahrenheit, and stores all three values in parallel arrays.
*
******+**--*****-**-****-*--*-*--**--**-*---*-***--************************/
void makeArray(int* temp_arr, int* hum_arr, double* dew_arr, int seed)
{
  int i; // indexing variable in the array
  int rand_temp; //generated random temperatur
  int rand_hum; //generated random humidity
  double rand_temp_cels; // calculated random temperature in celcius
  double rand_dew; //calculated dew value

  srand(seed);

  for (i = 0; i < SIZE; i++)
  {
    rand_temp = (rand() % (MAXVALUE - MINVALUE + 1)) + MINVALUE;
    rand_hum = (rand() % (MAXVALUE - MINVALUE + 1)) + MINVALUE;
    rand_temp_cels = (FIVE * (rand_temp - THIRTYTWO)) / NINE;
    rand_dew = rand_temp_cels - ((ONEHUNDRED - rand_hum) / FIVE);
    rand_dew = (rand_dew * (NINE / FIVE)) + THIRTYTWO;
    temp_arr[i] = rand_temp;
    hum_arr[i] = rand_hum;
    dew_arr[i] = rand_dew;
  }
}

/*****+**--*****-**-****-*--*-*--**--**-*---*-***--*************************
*
*  Function Information
*
*  Name of Function: sortArrays
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int *temp_arr - array of temperature values to be sorted with others.
*    2. int *hum_arr  - array of humidity values linked to temperatures.
*    3. double *dew_arr - array of dew point values linked to temperatures.
*
*  Function Description:
*    Sorts the three parallel arrays based on the user-selected option:
*    by temperature, humidity, or dew point. Calls the appropriate
*    insertion sort routine to keep all three arrays synchronized.
*
******+**--*****-**-****-*--*-*--**--**-*---*-***--************************/
void sortArrays(int* temp_arr, int* hum_arr, double* dew_arr, int sortOption)
{
  switch (sortOption)
  {
    case 1:
      insertionSort(temp_arr,hum_arr,dew_arr);
      break;
    case 2:
      insertionSort(hum_arr,temp_arr,dew_arr);
      break;
    case 3:
      insertionSort2(dew_arr,hum_arr,temp_arr);
      break;
}
}

/*****+**--*****-**-****-*--*-*--**--**-*---*-***--*************************
*
*  Function Information
*
*  Name of Function: insertionSort
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int *primaryArr - primary key array used to control the sort order.
*    2. int *secondaryArr - secondary key array for tie-breaking on ties.
*    3. double *tertiaryArr - third array kept in parallel with the sort.
*
*  Function Description:
*    Performs an insertion sort on three parallel arrays, using the primary
*    array as the main sort key and the secondary array to break ties when
*    primary values are equal. All three arrays are rearranged consistently.
*
******+**--*****-**-****-*--*-*--**--**-*---*-***--************************/
void insertionSort(int* primaryArr, int* secondaryArr, double* tertiaryArr)
{
  int i; // outer index
  int j; // traversal for insertion index
  int key; // primary key value
  int fakeKey1; // secondary key value
  double fakeKey2; // tertiary value

  for (i = 1; i < SIZE; i++)
  {
    key = primaryArr[i];
    fakeKey1 = secondaryArr[i];
    fakeKey2 = tertiaryArr[i];
    j = i - 1;

    while (j >= 0 && (primaryArr[j] > key || (primaryArr[j] == key && secondaryArr[j] > fakeKey1)))
    {
      primaryArr[j + 1]  = primaryArr[j];
      secondaryArr[j + 1] = secondaryArr[j];
      tertiaryArr[j + 1] = tertiaryArr[j];
      j--;
    }

    j++;
    primaryArr[j]  = key;
    secondaryArr[j] = fakeKey1;
    tertiaryArr[j] = fakeKey2;
  }
}

/*****+**--*****-**-****-*--*-*--**--**-*---*-***--*************************
*
*  Function Information
*
*  Name of Function: insertionSort2
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. double *primaryArr - primary key array (dew point) for sorting.
*    2. int *secondaryArr  - secondary key array (e.g., humidity) for ties.
*    3. int *tertiaryArr   - third integer array kept in parallel order.
*
*  Function Description:
*    Performs an insertion sort on three parallel arrays where the primary
*    key is a double array (dew point). Uses the secondary integer array to
*    break ties when primary values are equal, maintaining all arrays in sync.
*
******+**--*****-**-****-*--*-*--**--**-*---*-***--************************/
void insertionSort2(double* primaryArr, int* secondaryArr, int* tertiaryArr)
{
  int i; // outer index
  int j; // traversal for insertion index
  double key; // primary key value
  int fakeKey1; // secondary key value
  int fakeKey2; // tertiary value

  for (i = 1; i < SIZE; i++)
  {
    key = primaryArr[i];
    fakeKey1 = secondaryArr[i];
    fakeKey2 = tertiaryArr[i];
    j = i - 1;

    while (j >= 0 && (primaryArr[j] > key || (primaryArr[j] == key && secondaryArr[j] > fakeKey1)))
    {
      primaryArr[j + 1]  = primaryArr[j];
      secondaryArr[j + 1] = secondaryArr[j];
      tertiaryArr[j + 1] = tertiaryArr[j];
      j--;
    }

    j++;
    primaryArr[j]  = key;
    secondaryArr[j] = fakeKey1;
    tertiaryArr[j] = fakeKey2;
  }
}

/*****+**--*****-**-****-*--*-*--**--**-*---*-***--*************************
*
*  Function Information
*
*  Name of Function: printResults
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int mindex, int maxdex - inclusive index range to be printed.
*    2. int sortOption - indicates which sort option was applied to the data.
*    3. int *temp_arr, int *hum_arr, double *dew_arr - parallel arrays of
*       temperature, humidity, and dew point values to display.
*
*  Function Description:
*    Prints a title line based on the selected sort option, column headers,
*    and then the rows of data between the specified minimum and maximum
*    indices by calling printLine for each row. Ends with a separator line.
*
******+**--*****-**-****-*--*-*--**--**-*---*-***--************************/
void printResults(int mindex, int maxdex, int sortOption, int* temp_arr, int* hum_arr, double* dew_arr)
{
  int i; //index for printing
  
  switch (sortOption)
  {
    case 1: 
      printf("\n  -=-=- Temperature Tracker Results -=-=-=-\n");
      break;
    case 2:
      printf("\n  -=-=-=- Humidity Tracker Results -=-=-=-\n");
      break;
    case 3:
      printf("\n  -=-=-=- Dewpoint Tracker Results -=-=-=-\n");
      break;
  }
  
  printf("\n     Temp (F) | Humidity (%%) | Dew Point (F)\n");
  printf("     ---------------------------------------\n");

  for (i = 0; i < maxdex - mindex + 1;i++)
  {
    printLine(mindex + i,temp_arr,hum_arr,dew_arr);
  }
  printf("     ---------------------------------------\n");
}

/*****+**--*****-**-****-*--*-*--**--**-*---*-***--*************************
*
*  Function Information
*
*  Name of Function: printLine
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int index - index of the data to print from the parallel arrays.
*    2. int *temp_arr - array containing temperature values (F).
*    3. int *hum_arr, double *dew_arr - arrays containing humidity (%) and
*       dew point (F) values corresponding to the given index.
*
*  Function Description:
*    Prints a single formatted line of output showing the index, temperature,
*    humidity, and dew point for one entry of the parallel arrays.
*
******+**--*****-**-****-*--*-*--**--**-*---*-***--************************/
void printLine(int index, int* temp_arr, int* hum_arr, double* dew_arr)
{
  printf("%3d: %5d    |%8d      |%8.1f      \n",index,temp_arr[index],hum_arr[index],dew_arr[index]);
}
