#include <stdio.h>
#include <stdlib.h>

#define THIRTYONE 31; //the number of days in month
#define THIRTY 30; //the number of days in a month
#define TWENTYNINE 29; //number of days in Feb for leap year
#define TWENTYEIGHT 28; //number of days in Feb

int checkLeapYear(int);
int numberOfDaysInMonth(int, int);
int calcDayOfWeek(int, int, int);

int main(void)
{
  int day = 21;
  int month = 10;
  int year = 2025;
  int status; //stores if the input year is a leap year
  int numDays; //the number of days in the month given
  int dayOfWeek; //the day of the week which the date falls on

  status = checkLeapYear(year);
  numDays = numberOfDaysInMonth(status, month);
  dayOfWeek = calcDayOfWeek(day, month, year);;

  return(0);
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
  int isLeapYear = 0;

  if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
  {
    isLeapYear = 1;
  }

  return(isLeapYear);
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
    case 12: numberOfDays = THIRTYONE;
             break;
    case 4:
    case 6:
    case 9:
    case 11: numberOfDays = THIRTY;
             break;
    default: if(status == 1)
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

/*****+*-*****-----***----*-----*--*-**---*-*-***--*************************
*
*  Function Information
*
*  Name of Function:calcDayOfWeek
*
*  Function Return Type:int
*
*  Parameters (list data type, name, and comment one per line):
*    1.int day, the day the user inputs
*    2.int month, the month the user inputs
*    3.int year, the year the user inputs
*
*  Function Description:calculates the day of the week based on the given date
*
******+*-*****-----***----*-----*--*-**---*-*-***--************************/

int calcDayOfWeek(int day, int month, int year)
{
  int yearCentury; //year of the century
  int zeroBasedCentury; //the zero based century
  int adjYear; //the adjusted year, knowing Jan and Feb are the 13, and 14 month of the previous year
  int dayOfWeek; //stores the day of the week in numeric format;

  if(month == 1)
  {
    adjYear = year - 1;
    month = 13;
  }
  else if(month == 2)
  {
    adjYear = year - 2;
    month = 14;
  }
  else
  {
    adjYear  = year;
  }

  yearCentury = adjYear % 100;
  zeroBasedCentury = adjYear / 100;
  dayOfWeek = (day + (13 * (month + 1) / 5) + yearCentury + (yearCentury / 4) + (zeroBasedCentury / 4) - (2 * zeroBasedCentury)) % 7;
  dayOfWeek = (dayOfWeek + 5) % 7 + 1;

  return(dayOfWeek);

}
