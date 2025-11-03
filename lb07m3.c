#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define THIRTYONE 31
#define THIRTY 30
#define DUEDAY 3
#define DUEMONTH 11
#define DUEYEAR 2025

int calcDayOfYear(int day, int month, int status);
int calcSeasonOfDate(int day, int month);
void calcHomeworkDueDate(int year, int month, int day, int daysInMonth, int* diff_day, int* diff_month, int* diff_year);

int main()
{
  int day = 1;
  int month = 12;
  int year = 2024;
  int status = 0;
  int numDays = 31;
  int dayOfWeek = 2;
  int dayOfYear = 294;
  int season = 3;

  int diffDay = 13;
  int diffMonth = 0;
  int diffYear = 0;

  dayOfYear = calcDayOfYear(day,month,status);
  season = calcSeasonOfDate(day,month);
  calcHomeworkDueDate(year,month,day,numDays,&diffDay,&diffMonth,&diffYear);

  return 0;
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




void calcHomeworkDueDate(int year, int month, int day, int daysInMonth,
                         int* diff_day, int* diff_month, int* diff_year)
{
  // Target (due) and current (now)
  int y2 = DUEYEAR,  m2 = DUEMONTH, d2 = DUEDAY;  // due
  int y1 = year,     m1 = month,    d1 = day;     // current
  int y2Status;

  // Determine sign: +1 if due >= current, -1 if overdue
  int sign = 1;
  if ( (y1 > y2) ||
       (y1 == y2 && m1 > m2) ||
       (y1 == y2 && m1 == m2 && d1 > d2) ) {
    // Swap so we always subtract smaller from larger, then apply sign
    sign = -1;
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
  *diff_year  = sign * dy;
  *diff_month = sign * dm;
  *diff_day   = sign * dd;
}