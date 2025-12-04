#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define THIRTYONE 31 //the number of days in month
#define THIRTY 30 //the number of days in a month
#define TWENTYNINE 29 //number of days in Feb for leap year
#define TWENTYEIGHT 28 //number of days in Feb

int numberOfDaysInMonth(int, int);
void printCalendar(int, int, int, int);
int findSpacing(int);

int main(void)
{
    int dayOfWeek = 3;
    int day = 3;
    int month = 1;
    int status = 0;


    printCalendar(dayOfWeek, day, month, status);
    return (0);
}

/*****+*-*-*-**----***----*-----*--*-**---*-*-***--*************************
*
*  Function Information
*
*  Name of Function:printCalendar
*
*  Function Return Type:void
*
*  Parameters (list data type, name, and comment one per line):
*    1.int dayOfWeek, the day of the week(Sun - Sat) rperesented from (1-7)
*    2.int day, the day in the month(1-31)
*    3.int month, the current month(1-12)
*    4.int status, whether or not it is a leap year,(1) being a leap year
*
*  Function Description:calculates the number of days in the month inputted
*
******+*-*-*-**----***----*-----*--*-**---*-*-***--************************/

void printCalendar(int dayOfWeek, int day, int month, int status)
{
  int numberOfDays; //the number of days in the specific month
  int space; //where starting day should be printed
  int count; //counter for printing 1 week

  numberOfDays = numberOfDaysInMonth(status, month);
  space = 4 * dayOfWeek;

  if(!(day > numberOfDays))
  {
    printf("\n        Sun Mon Tue Wed Thu Fri Sat");
    printf("\nWeek 1:%*.d", space, day);
    day++;

    space = 0;
  }

  for(count = 1; count < 7; count++)
  {
    if(day > numberOfDays)
    {
      day = 1;
    }
    else
    {
      printf("%4d", day);
      day++;
      dayOfWeek++;
    }
    if(dayOfWeek == 7 && count + 1 != 7 )
    {
        printf("\nWeek 2:");
    }

  }
  printf("\n");
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
  int yearCentury;       // K: year of the century
  int zeroBasedCentury;  // J: zero-based century

  int y;                 // adjusted year for Jan/Feb
  int m;                 // adjusted month for Jan/Feb (Mar=3,...,Jan=13, Feb=14)

  int dayOfWeek;         // weekday (Monday=1..Sunday=7)
  int h;                 //zeller calculation number

  /* Adjust Jan/Feb to be months 13/14 of the previous year */
  if (month == 1 || month == 2)
  {
    y = year - 1;
    m = month + 12;
  }
  else
  {
    y = year;
    m = month;
  }

  yearCentury = y % 100;         /* K */

  zeroBasedCentury = y / 100;    /* J */

  /* Zeller (Gregorian): h = (q + 13(m+1)/5 + K + K/4 + J/4 + 5J) % 7, 0=Saturday */
  h = (day + (13 * (m + 1)) / 5 + yearCentury + (yearCentury / 4) + (zeroBasedCentury / 4) + 5 * zeroBasedCentury) % 7;

  /* Map 0=Sat,1=Sun,2=Mon,... to Monday=1..Sunday=7 */
  dayOfWeek = ((h + 5) % 7) + 1;
  return dayOfWeek;
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
