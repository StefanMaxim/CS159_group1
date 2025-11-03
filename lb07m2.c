#include<stdio.h>

#define DUEDAY 3
#define DUEMONTH 11
#define DUEYEAR 2025

void input(int *day, int *month, int *year);
void output(int year, int status, int numDays, int dayOfWeek, int dayOfYear, int season, int diffDay, int diffMonth, int diffYear);

int main(void)
{
  int day;
  int month;
  int year;
  int status = 0;
  int numDays = 31;
  int dayOfWeek = 2;
  int dayOfYear = 294;
  int season = 3;
  int diffDay = 13;
  int diffMonth = 0;
  int diffYear = 0;

  input(&day, &month, &year);
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
    printf("Year 2024 status: Leap Year\n");
  }
  else
  {
    printf("Year 2024 status: Not a Leap Year\n");
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
    printf("\nHomework due date(%d/%02d/%d): %d year, %d months, %d days ago\n", DUEMONTH, DUEDAY, DUEYEAR, diffYear, diffMonth, diffDay);
  }
}                                                                                   