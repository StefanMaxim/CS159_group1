#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define DUEDAY 3
#define DUEMONTH 11
#define DUEYEAR 2025

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
  int day;
  int month;
  int year;
  int status;
  int numDays;
  int dayOfWeek;
  int dayOfYear;
  int season;
  int diffDay;
  int diffMonth;
  int diffYear;

  input(&day, &month, &year);
  status = checkLeapYear(year);
  numDays = numberOfDaysInMonth(status, month);
  dayOfWeek = calcDayOfWeek(day, month, year);
  dayOfYear = calcDayOfYear(day,month,status);
  season = calcSeasonOfDate(day,month);
  calcHomeworkDueDate(year,month,day,&diffDay,&diffMonth,&diffYear);
  output(year, status, numDays, dayOfWeek, dayOfYear, season, diffDay, diffMonth, diffYear);

  return(0);
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
    printf("\nHomework due date (%d/%02d/%d): %d year, %d months, %d days ago\n", DUEMONTH, DUEDAY, DUEYEAR, diffYear, diffMonth, diffDay);
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
int calcDayOfYear(int day, int month, int status)
{
//switch case must have in
int total_days;

total_days = 0;
if (month > 1)
{
  total_days += THIRTYONE;
}
if (month > 2)
{
  if (status)
  {
    total_days +=29;
  }
  else
  {
    total_days +=28;
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
int calcSeasonOfDate(int day, int month)
{
  int season;

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
void calcHomeworkDueDate(int year, int month, int day, int* diff_day, int* diff_month, int* diff_year)
{
  // Target (due) and current (now)
  int y2 = DUEYEAR,  m2 = DUEMONTH, d2 = DUEDAY;  // due
  int y1 = year,     m1 = month,    d1 = day;     // current
  int y2Status;

  if ( (y1 > y2) ||
       (y1 == y2 && m1 > m2) ||
       (y1 == y2 && m1 == m2 && d1 > d2) ) {
    // Swap so we always subtract smaller from larger
    int ty = y1; y1 = y2; y2 = ty;
    int tm = m1; m1 = m2; m2 = tm;
    int td = d1; d1 = d2; d2 = td;
  }

  // Borrow days if needed
  if (d2 < d1) {
    // borrow one month into d2
    m2 -= 1;
    if (m2 == 0) { m2 = 12; y2 -= 1; }
    y2Status = checkLeapYear(y2);
    d2 += numberOfDaysInMonth(y2Status,m2);
  }

  // Borrow months if needed
  if (m2 < m1) {
    y2 -= 1;
    m2 += 12;
  }

  int dy = y2 - y1;
  int dm = m2 - m1;
  int dd = d2 - d1;

  // Apply sign if overdue
  *diff_year  = abs(dy);
  *diff_month = abs(dm);
  *diff_day   = abs(dd);
}                                                                                   