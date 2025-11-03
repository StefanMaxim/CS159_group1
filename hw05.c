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
*  Program Description:
*
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
******+**--***-****-**-*-*------**--**----*-*-***--************************/
int generateNum(int min, int max)
{
  return (rand() % (max - min + 1)) + min;
}

/*****+**--***-****-**-*-*------**--**----*-*-***--*************************
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






















