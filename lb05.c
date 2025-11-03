// for the code, to find the number of days in the year, use a switch, and check if month > 1, then add 30 (for january)
// if month > 2 then add 28 (for february), etc...

#define TWENTYEIGHT 28
#define TWENTYNINE 29
#define THIRTY 30
#define THIRTYONE 31

#include <stdio.h>
#include <stdlib.h>

int dayOfYear(int,int,int);

int main()
{
  int days;
  days = dayOfYear(0,3,11);
  printf("%d",days);
  return 0;
}


int dayOfYear(int status, int day, int month)
{
  //status = 1 means it is leap year
  int days; // the number of days from the start of the year

  days = 0;
  if (month > 1)
  {
    days += THIRTYONE;
  }
  if (month > 2)
  {
    if (status)
    {
      days += 29;
    }
    else
    {
      days += 28;
    }
  }
  if (month > 3)
  {
    days += THIRTYONE;
  }
  if (month > 4)
  {
    days += THIRTY;
  }
  if (month > 5)
  {
    days += THIRTYONE;
  }
  if (month > 6)
  {
    days += THIRTY;
  }
  if (month > 7)
  {
    days += THIRTYONE;
  }
  if (month > 8)
  {
    days += THIRTYONE;
  }
  if (month > 9)
  {
    days += THIRTY;
  }
  if (month > 10)
  {
    days += THIRTYONE;
  }
  if (month > 11)
  {
    days += THIRTY;
  }
  days += day;


  return days;
}

