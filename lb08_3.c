#include<stdio.h>

void inputTime(int *numDays, int *numMonths, int *numYears);
void printOutput(int numDays, int numMonths, int numYears, int day, int month, int year, int dayOfWeek);

int main(void)
{
  int numDays;
  int numMonths;
  int numYears;
  int day = 30;
  int month = 9;
  int year = 2024;
  int dayOfWeek = 2;

  inputTime(&numDays, &numMonths, &numYears);
  printOutput(numDays, numMonths, numYears, day, month, year, dayOfWeek);

  return(0);
}

/*****+-----*******-*---*-**--*--**-**----*-*-***--*************************
*
*  Function Information
*
*  Name of Function: inputTime
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int *numDays - The number of days subtracted from the due date.
*    2. int *numMonths - The number of months subtracted from the due date.
*    3. int *numYears - The number of years subtracted from the due date.
*
*  Function Description: Prompts the user to enter the time to subtract from
*  the due date and sets the values in the main function. If the user enters
*  an invalid time, a specific error message is printed, and the user is
*  prompted again.
*
******+-----*******-*---*-**--*--**-**----*-*-***--************************/
void inputTime(int *numDays, int *numMonths, int *numYears)
{
  do
  {
    printf("Enter time to subtract from due date (day month year) -> ");
    scanf("%d %d %d", numDays, numMonths, numYears);
    printf("\n");

    if (*numDays < 0 || *numDays > 31)
    {
      printf("Invalid day, valid values are 0 to 31.\n\n");
    }

    if (*numMonths < 0 || *numMonths > 11)
    {
      printf("Invalid month, valid values are 0 to 11.\n\n");
    }

    if (*numYears < 0)
    {
      printf("Invalid year, non-negative year values only.\n\n");
    }
  }
  while (*numDays < 0 || *numDays > 31 || *numMonths < 0 || *numMonths > 11 || *numYears < 0);
}

/*****+-----****-*--*---*-**--*--**-**----*-*-***--*************************
*
*  Function Information
*
*  Name of Function: printOutput
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int numDays - The number of days subtracted from the due date.
*    2. int numMonths - The number of months subtracted from the due date.
*    3. int numYears - The number of years subtracted from the due date.
*    4. int day - The day of the past date.
*    5. int month - The month of the past date.
*    6. int year - The year of the past date.
*    7. int dayofWeek - The day of the week of the past date. Stored as 1 ->
*    7 for Sunday -> Saturday.
*
*  Function Description: Prints the date after subtracting the time and its
*  month and day of the week.
*
******+-----****-*--*---*-**--*--**-**----*-*-***--************************/
void printOutput(int numDays, int numMonths, int numYears, int day, int month, int year, int dayOfWeek)
{
  printf("Past date after subtracting %d years, %d months, %d days: %02d/%02d/%d\n\n", numDays, numMonths, numYears, month, day, year);

  switch (month)
  {
    case 1:
      printf("Week Starts in: January on ");
      break;
    case 2:
      printf("Week Starts in: February on ");
      break;
    case 3:
      printf("Week Starts in: March on ");
      break;
    case 4:
      printf("Week Starts in: April on ");
      break;
    case 5:
      printf("Week Starts in: May on ");
      break;
    case 6:
      printf("Week Starts in: June on ");
      break;
    case 7:
      printf("Week Starts in: July on ");
      break;
    case 8:
      printf("Week Starts in: August on ");
      break;
    case 9:
      printf("Week Starts in: September on ");
      break;
    case 10:
      printf("Week Starts in: October on ");
      break;
    case 11:
      printf("Week Starts in: November on ");
      break;
    case 12:
      printf("Week Starts in: December on ");
      break;
  }

  switch (dayOfWeek)
  {
    case 1:
      printf("Sunday\n\n");
      break;
    case 2:
      printf("Monday\n\n");
      break;
    case 3:
      printf("Tuesday\n\n");
      break;
    case 4:
      printf("Wednesday\n\n");
      break;
    case 5:
      printf("Thursday\n\n");
      break;
    case 6:
      printf("Friday\n\n");
      break;
    case 7:
      printf("Saturday\n\n");
      break;
  }
}
   