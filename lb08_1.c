#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define DAY 3
#define MONTH 11
#define YEAR 2025

#define THIRTYONE 31 //the number of days in month
#define THIRTY 30 //the number of days in a month
#define TWENTYNINE 29 //number of days in Feb for leap year
#define TWENTYEIGHT 28 //number of days in Feb

int checkLeapYear(int);
int numberOfDaysInMonth(int, int);
void findNewDate(int numDays, int numMonths, int numYears, int* day, int* month, int* year);

int main()
{
  int numMonths;
  int numDays;
  int numYears;

  int day;
  int month;
  int year;

  numDays = 1;
  numMonths = 10;
  numYears = 4;

  findNewDate(numDays,numMonths,numYears,&day,&month,&year);
  printf("The date was found to be %d/%d/%d",month,day,year);
  return 0;
}

/*****+*-*-*-**----***----*-----*--*-**---*-*-***--*************************
*
*  Function Information
*
*  Name of Function: findNewDate
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int month       - starting month (1-12)
*    2. int day         - starting day of month (1-31, valid for month/year)
*    3. int year        - starting year (e.g., 2025)
*    4. int addedDays   - number of days to add to the starting date (>= 0)
*    5. int *newMonth   - pointer to store resulting month (1-12)
*    6. int *newDay     - pointer to store resulting day (1-31)
*    7. int *newYear    - pointer to store resulting year
*
*  Function Description:
*    Calculates the calendar date that occurs addedDays after the input date
*    (month/day/year). The function accounts for varying month lengths and
*    leap years. The computed future date is returned through the pointer
*    parameters newMonth, newDay, and newYear.
*
******+*-*-*-**----***----*-----*--*-**---*-*-***--************************/
void findNewDate(int numDays, int numMonths, int numYears, int* day, int* month, int* year)
{
  int tempDay;
  int tempMonth;
  int tempYear;

  int resDay;
  int resMonth;
  int resYear;

  int status; //the status of the year as a leap year
  int daysIn; //the number of days in the month

  tempDay = DAY;
  tempMonth = MONTH;
  tempYear = YEAR;

  resDay = DAY - numDays;
  if (resDay <= 0)
  {
    tempMonth--; //carrying over
    tempDay += THIRTYONE; //days in october
    resDay = tempDay - numDays;
  }
  resMonth = tempMonth - numMonths;
  if (resMonth <= 0)
  {
    tempYear--; //carrying over
    tempMonth += 12; //the carry over
    resMonth = tempMonth - numMonths;
  }
  resYear = tempYear - numYears;

  status = checkLeapYear(resYear);
  daysIn = numberOfDaysInMonth(status,resMonth);
  if (resDay > daysIn)
  {
    resDay = daysIn;
  }

  *day = resDay;
  *month = resMonth;
  *year = resYear;
}

/*****+*-*-*-**----***----*-----*--*-**---*-*-***--*************************
*
*  Function Information
*
*  Name of Function:numberOfDaysInMonth
*
*  Function Return Type:int
*
*  Parameters (list data type, name, and comment one per line):
*    1.int status, stores whether its a leap year or not
*    2.int month, the month the user inputs
*    3.
*
*  Function Description:calculates the number of days in the month inputted
*
******+*-*-*-**----***----*-----*--*-**---*-*-***--************************/
int numberOfDaysInMonth(int status, int month)
{
  int numberOfDays; //stores the number of days in the specific month

  switch(month)
  {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      numberOfDays = THIRTYONE;
      break;
    case 4:
    case 6:
    case 9:
    case 11:
      numberOfDays = THIRTY;
      break;
    default:
      if(status == 1)
        {
          numberOfDays = TWENTYNINE;
        }
        else
        {
          numberOfDays = TWENTYEIGHT;
        }
  }

  return(numberOfDays);
}

/*****+*-*-*-**----***----*-----*--*-**---*-*-***--*************************
*
*  Function Information
*
*  Name of Function:checkLeapYear
*
*  Function Return Type:int
*
*  Parameters (list data type, name, and comment one per line):
*    1.int year, stores the year that user inputs
*    2.
*    3.
*
*  Function Description: check if the year inputted is a leap year
*
******+*-*-*-**----***----*-----*--*-**---*-*-***--************************/

int checkLeapYear(int year)
{
  int isLeapYear; //integer representing the boolean of whether or not it is a leap year

  isLeapYear = 0;

  if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
  {
    isLeapYear = 1;
  }

  return(isLeapYear);
}