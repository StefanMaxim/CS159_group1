/*****+**--***-****-****-*--*-*--**--**-*---*-***--*************************
*
*  Lab #:
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified. Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work. We have
*  not made use of any AI generated code in this solution.
*
*  Program Description:

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
*  Name of Function:
*
*  Function Return Type:
*
*  Parameters (list data type, name, and comment one per line):
*    1.
*    2.
*    3.
*
*  Function Description:
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
*  Name of Function:
*
*  Function Return Type:
*
*  Parameters (list data type, name, and comment one per line):
*    1.
*    2.
*    3.
*
*  Function Description:
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
*  Name of Function:
*
*  Function Return Type:
*
*  Parameters (list data type, name, and comment one per line):
*    1.
*    2.
*    3.
*
*  Function Description:
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
*  Name of Function:
*
*  Function Return Type:
*
*  Parameters (list data type, name, and comment one per line):
*    1.
*    2.
*    3.
*
*  Function Description:
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
*  Name of Function:
*
*  Function Return Type:
*
*  Parameters (list data type, name, and comment one per line):
*    1.
*    2.
*    3.
*
*  Function Description:
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
*  Name of Function:
*
*  Function Return Type:
*
*  Parameters (list data type, name, and comment one per line):
*    1.
*    2.
*    3.
*
*  Function Description:
*
******+**--*****-**-****-*--*-*--**--**-*---*-***--************************/
void insertionSort(int* primaryArr, int* secondaryArr, double* tertiaryArr)
{
  int i; // outer index
  int j; //traversal for insertion index
  int key; //the value being looked at
  int fakeKey1; //the value to be moved in the secondary array
  double fakeKey2; // the value to be moved in the tertiary array

  for(i = 1; i < SIZE; i++)
  {
    key = primaryArr[i];
    fakeKey1 = secondaryArr[i];
    fakeKey2 = tertiaryArr[i];
    j = i - 1;
    while(j >= 0 && primaryArr[j] > key)
    {
      primaryArr[j + 1] = primaryArr[j];
      secondaryArr[j + 1] = secondaryArr[j];
      tertiaryArr[j + 1] = tertiaryArr[j];
      j--;
    }
    j++;
    primaryArr[j] = key;
    secondaryArr[j] = fakeKey1;
    tertiaryArr[j] = fakeKey2;
  }
}

/*****+**--*****-**-****-*--*-*--**--**-*---*-***--*************************
*
*  Function Information
*
*  Name of Function:
*
*  Function Return Type:
*
*  Parameters (list data type, name, and comment one per line):
*    1.
*    2.
*    3.
*
*  Function Description:
*
******+**--*****-**-****-*--*-*--**--**-*---*-***--************************/
void insertionSort2(double* primaryArr, int* secondaryArr, int* tertiaryArr)
{
  int i; // outer index
  int j; //traversal for insertion index
  double key; //the value being looked at
  int fakeKey1; //the value to be moved in the secondary array
  int fakeKey2; // the value to be moved in the tertiary array

  for(i = 1; i < SIZE; i++)
  {
    key = primaryArr[i];
    fakeKey1 = secondaryArr[i];
    fakeKey2 = tertiaryArr[i];
    j = i - 1;
    while(j >= 0 && primaryArr[j] > key)
    {
      primaryArr[j + 1] = primaryArr[j];
      secondaryArr[j + 1] = secondaryArr[j];
      tertiaryArr[j + 1] = tertiaryArr[j];
      j--;
    }
    j++;
    primaryArr[j] = key;
    secondaryArr[j] = fakeKey1;
    tertiaryArr[j] = fakeKey2;
  }
}

/*****+**--*****-**-****-*--*-*--**--**-*---*-***--*************************
*
*  Function Information
*
*  Name of Function:
*
*  Function Return Type:
*
*  Parameters (list data type, name, and comment one per line):
*    1.
*    2.
*    3.
*
*  Function Description:
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
*  Name of Function:
*
*  Function Return Type:
*
*  Parameters (list data type, name, and comment one per line):
*    1.
*    2.
*    3.
*
*  Function Description:
*
******+**--*****-**-****-*--*-*--**--**-*---*-***--************************/
void printLine(int index, int* temp_arr, int* hum_arr, double* dew_arr)
{
  printf("%3d: %5d    |%8d      |%8.1f      \n",index,temp_arr[index],hum_arr[index],dew_arr[index]);
}
