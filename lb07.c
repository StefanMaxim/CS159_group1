/*****+**--*-*-****-****-*------***-**----*-*-***--*************************
*
*  Lab #:7
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified. Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work. We have 
*  not made use of any AI generated code in this solution. 
*
*  Program Description:
*  Reads a calendar date (month day year) from the user, determines whether
*  the year is a leap year, computes the number of days in the input month,
*  calculates the day of the week (Monday=1 … Sunday=7), the day-of-year,
*  and the astronomical season (Spring=1, Summer=2, Fall=3, Winter=4).
*  It then computes the calendar difference in years, months, and days
*  between the input date and the fixed homework due date (DUEMONTH/DUEDAY/DUEYEAR),
*  and prints all of these results in a formatted summary.
*
******+**--*-*-****-****-*------***-**----*-*-***--************************/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define DUEDAY 3 //the day in which the assignment is due
#define DUEMONTH 11 //the month in which the assignment is due
#define DUEYEAR 2025 //the year in which the assignment is due
#define THIRTYONE 31 //the number of days in month
#define THIRTY 30 //the number of days in a month
#define TWENTYNINE 29 //number of days in Feb for leap year
#define TWENTYEIGHT 28 //number of days in Feb

void input(int *day, int *month, int *year);
int checkLeapYear(int);
int numberOfDaysInMonth(int, int);
int calcDayOfWeek(int, int, int);
int calcDayOfYear(int day, int month, int status);
int calcSeasonOfDate(int day, int month);
void calcHomeworkDueDate(int year, int month, int day, int* diff_day, int* diff_month, int* diff_year);
void output(int year, int status, int numDays, int dayOfWeek, int dayOfYear, int season, int diffDay, int diffMonth, int diffYear);

int main(void)
{
  //Local Declarations
  int day;        // input: day of month (1–31)
  int month;      // input: month number (1–12)
  int year;       // input: Gregorian year

  int status;     // derived: 1 if leap year, 0 otherwise

  int numDays;    // derived: number of days in the given month for the given year

  int dayOfWeek;  // derived: weekday for the input date (Monday=1 … Sunday=7)
  int dayOfYear;  // derived: ordinal day within the year (1–365/366)
  int season;     // derived: season code (1=Spring, 2=Summer, 3=Fall, 4=Winter)

  int diffDay;    // derived: |day| component of date difference to due date
  int diffMonth;  // derived: |month| component of date difference to due date
  int diffYear;   // derived: |year| component of date difference to due date

  //Executable Statments
  input(&day, &month, &year);
  status = checkLeapYear(year);
  numDays = numberOfDaysInMonth(status, month);
  dayOfWeek = calcDayOfWeek(day, month, year);
  dayOfYear = calcDayOfYear(day, month, status);
  season = calcSeasonOfDate(day, month);
  calcHomeworkDueDate(year, month, day, &diffDay, &diffMonth, &diffYear);
  output(year, status, numDays, dayOfWeek, dayOfYear, season, diffDay, diffMonth, diffYear);

  return 0;
}

/*****+------*-*-**-*-*---**----**---**---*-*-***--*************************
*
*  Function Information
*
*  Name of Function: input
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int *day - The day given.
*    2. int *month - The month given.
*    3. int *year - The year given.
*
*  Function Description: Prompts the user to input a month, day, and year,
*  and saves the values in main.
*
******+------*-*-**-*-*---**----**---**---*-*-***--************************/

void input(int *day, int *month, int *year)
{
  printf("Enter a date (month day year) -> ");
  scanf("%d %d %d", month, day, year);
}

/*****+-----*******---*---**----**---**---*-*-***--*************************
*
*  Function Information
*
*  Name of Function: output
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int year - The year given.
*    2. int status - 0 if the year is not a leap year. 1 if it is.
*    3. int numDays - The number of days the given month has.
*    4. int dayOfWeek - The day of the week of the given date (Monday ->
*    Sunday). Stored as 1 -> 7 respectively.
*    5. int dayOfYear - The given date's day of the year.
*    6. int season - The season of the given date (Spring -> Winter). Stored
*    as 1 -> 4 respectively.
*    7. int diffDay - The difference in days between the given date and the
*    homework due date.
*    8. int diffMonth - The difference in months between the given date and
*    the homework due date.
*    9. int diffYear - The difference in years between the given date and
*    the homework due date.
*
*  Function Description: Prints whether the year is a leap year, the number
*  of days in the month, the day of the week, the day of the year, the
*  season, and the difference between the given date and the homework due
*  date.
*
******+-----*******---*---**----**---**---*-*-***--************************/

void output(int year, int status, int numDays, int dayOfWeek, int dayOfYear, int season, int diffDay, int diffMonth, int diffYear)
{
  printf("\nGiven Date Description\n");
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

  if (status)
  {
    printf("Year %d status: Leap Year\n",year);
  }
  else
  {
    printf("Year %d status: Not a Leap Year\n",year);
  }

  printf("Number of days in month: %d\n", numDays);

  if (dayOfWeek == 1)
  {
    printf("Day of the week: Monday\n");
  }
  else if (dayOfWeek == 2)
  {
    printf("Day of the week: Tuesday\n");
  }
  else if (dayOfWeek == 3)
  {
    printf("Day of the week: Wednesday\n");
  }
  else if (dayOfWeek == 4)
  {
    printf("Day of the week: Thursday\n");
  }
  else if (dayOfWeek == 5)
  {
    printf("Day of the week: Friday\n");
  }
  else if (dayOfWeek == 6)
  {
    printf("Day of the week: Saturday\n");
  }
  else if (dayOfWeek == 7)
  {
    printf("Day of the week: Sunday\n");
  }

  printf("Day of the year: %d\n", dayOfYear);

  if (season == 1)
  {
    printf("Season of date given: Spring\n");
  }
  else if (season == 2)
  {
    printf("Season of date given: Summer\n");
  }
  else if (season == 3)
  {
    printf("Season of date given: Fall\n");
  }
  else if (season == 4)
  {
    printf("Season of date given: Winter\n");
  }

  if (year < DUEYEAR || (year == DUEYEAR && dayOfYear < 307))
  {
    printf("\nHomework due date (%d/%02d/%d): %d years, %d months, %d days in the future\n", DUEMONTH, DUEDAY, DUEYEAR, diffYear, diffMonth, diffDay);
  }
  else if (year == DUEYEAR && dayOfYear == 307)
  {
    printf("\nHomework due date (%d/%02d/%d): Today at 11:00pm\n", DUEMONTH, DUEDAY, DUEYEAR);
  }
  else
  {
    printf("\nHomework due date (%d/%02d/%d): %d years, %d months, %d days ago\n", DUEMONTH, DUEDAY, DUEYEAR, diffYear, diffMonth, diffDay);
  }
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
*  Name of Function: calcDayOfYear
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int day   - Day of the month (1–31).
*    2. int month - Month number (1–12).
*    3. int status- Leap-year flag for the given year (1 = leap, 0 = not).
*
*  Function Description: Computes the 1-based day-of-year for the given date
*  by summing the lengths of all full months prior to `month` and then adding
*  `day`. February is treated as 29 days when `status == 1`, else 28 days.
*
******+*-*-*-**----***----*-----*--*-**---*-*-***--************************/
int calcDayOfYear(int day, int month, int status)
{
//switch case must have in
  int total_days; // the total days that year

  total_days = 0;
  if (month > 1)
  {
    total_days += THIRTYONE;
  }
  if (month > 2)
  {
    if (status)
    {
      total_days += 29;
    }
    else
    {
      total_days += 28;
    }
  }
  if (month > 3)
  {
    total_days += THIRTYONE;
  }
  if (month > 4)
  {
    total_days += THIRTY;
  }
  if (month > 5)
  {
    total_days += THIRTYONE;
  }
  if (month > 6)
  {
    total_days += THIRTY;
  }
  if (month > 7)
  {
    total_days += THIRTYONE;
  }
  if (month > 8)
  {
    total_days += THIRTYONE;
  }
  if (month > 9)
  {
    total_days += THIRTY;
  }
  if (month > 10)
  {
    total_days += THIRTYONE;
  }
  if (month > 11)
  {
    total_days += THIRTY;
  }
  total_days += day;
  return total_days;
}
/*****+*-*-*-**----***----*-----*--*-**---*-*-***--*************************
*
*  Function Information
*
*  Name of Function: calcSeasonOfDate
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int day   - Day of the month (1–31).
*    2. int month - Month number (1–12).
*
*  Function Description: Determines the astronomical season of the given date
*  using these bounds: Spring (Mar 21–Jun 20) → 1, Summer (Jun 21–Sep 20) → 2,
*  Fall (Sep 21–Dec 20) → 3, Winter (Dec 21–Mar 20) → 4.
*  Returns the season code as an integer 1–4.
*
******+*-*-*-**----***----*-----*--*-**---*-*-***--************************/
int calcSeasonOfDate(int day, int month)
{
  int season; //the season where 1 is spring and 4 is winter

  if ((month == 3 && day >= 21) || (month == 4) || (month == 5) || (month == 6 && day <= 20))
  {
    season = 1;
  }
  else if ((month == 6 && day >= 21) || (month == 7) || (month == 8) || (month == 9 && day <= 20))
  {
    season = 2;
  }
  else if ((month == 9 && day >= 21) || (month == 10) || (month == 11) || (month == 12 && day <= 20))
  {
    season = 3;
  }
  else 
  {
    season = 4;
  }
  return season;

}
/*****+*-*-*-**----***----*-----*--*-**---*-*-***--*************************
*
*  Function Information
*
*  Name of Function: calcHomeworkDueDate
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int year      - Current date year.
*    2. int month     - Current date month (1–12).
*    3. int day       - Current date day (1–31).
*    4. int *diff_day   - OUT: absolute day component of difference.
*    5. int *diff_month - OUT: absolute month component of difference.
*    6. int *diff_year  - OUT: absolute year component of difference.
*
*  Function Description: Computes the calendar difference between the current
*  date (year/month/day) and the fixed due date (DUEMONTH/DUEDAY/DUEYEAR).
*  If needed, swaps dates so subtraction is well-defined, then normalizes by
*  borrowing days from the previous month and months from the previous year.
*  Writes the absolute values of the resulting (years, months, days) into the
*  provided output pointers.
*
******+*-*-*-**----***----*-----*--*-**---*-*-***--************************/
void calcHomeworkDueDate(int year, int month, int day, int* diff_day, int* diff_month, int* diff_year)
{
  // Target (due) and current (now)
  int y2; //the years it is due
  int m2; //the month it is due
  int d2; // the day it is due

  int y1; //current year 
  int m1; //current month
  int d1; // current year

  int y2Status; //status of the year is it due

  int dy; //difference in years
  int dm; //difference in months
  int dd; //difference in days

  int ty; //temp year
  int tm; //temp month
  int td; //temp day

  y2 = DUEYEAR;  
  m2 = DUEMONTH; 
  d2 = DUEDAY;  
  y1 = year;    
  m1 = month;    
  d1 = day;     

  if ( (y1 > y2) || (y1 == y2 && m1 > m2) || (y1 == y2 && m1 == m2 && d1 > d2) ) 
  {
    // Swap so we always subtract smaller from larger
    ty = y1; 
    y1 = y2; 
    y2 = ty;

    tm = m1;
    m1 = m2; 
    m2 = tm;

    td = d1; 
    d1 = d2; 
    d2 = td;
  }

  // Borrow days if needed
  if (d2 < d1) 
  {
    // borrow one month into d2
    m2 -= 1;
    if (m2 == 0) 
    {
      m2 = 12; 
      y2 -= 1; 
    }
    y2Status = checkLeapYear(y2);
    d2 += numberOfDaysInMonth(y2Status,m2);
  }

  // Borrow months if needed
  if (m2 < m1) 
  {
    y2 -= 1;
    m2 += 12;
  }

  dy = y2 - y1;
  dm = m2 - m1;
  dd = d2 - d1;

  // Apply sign if overdue
  *diff_year  = abs(dy);

  *diff_month = abs(dm);

  *diff_day   = abs(dd);
}                                                                                   