/*****+*--**-***-*---*-*-*--*-*--**-***---*-*-***--*************************
*
*  Homework #:3
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified. Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work. I have not 
*  made use of any AI generated code in this solution. 
*
*  Program Description: Program to calculate two randomly generated times given a seed and determine the difference
*  between them.
*
******+*--**-***-*---*-*-*--*-*--**-***---*-*-***--************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SECONDS_PER_DAY 86400    // Maximum seconds in a day (24 * 60 * 60)
#define SECONDS_PER_HOUR 3600    // Seconds in an hour (60 * 60)
#define SECONDS_PER_MINUTE 60    // Seconds in a minute
#define HOURS_PER_DAY 24         // Hours in a day
#define ONE 1                    // Constant for adding one

// Function Declarations
void getSeedValue(int *seed_value);
void generateRandomTimes(int *time1_seconds, int *time2_seconds);
void convertSecondsToTime(int total_seconds, int *hours, int *minutes, int *seconds);
void displayTime(int hours, int minutes, int seconds);
void calculateTimeDifference(int time1_seconds, int time2_seconds, int *diff_seconds);
void displayResults(int time1_seconds, int time2_seconds, int diff_seconds);

int main()
{
  // Local Declarations
  int seed_value;         // Seed for random number generator
  int time1_seconds;      // First random time in seconds
  int time2_seconds;      // Second random time in seconds
  int diff_seconds;       // Difference between times in seconds

  // Executable Statements
  getSeedValue(&seed_value);
  srand(seed_value);
  generateRandomTimes(&time1_seconds, &time2_seconds);
  calculateTimeDifference(time1_seconds, time2_seconds, &diff_seconds);
  displayResults(time1_seconds, time2_seconds, diff_seconds);

  return 0;
}

/*****+**-**-***-*---*-*-*--*-*--**-***---*-*-***--*************************
*
*  Function Information
*
*  Name of Function: getSeedValue
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int *seed_value - pointer to store the seed value
*
*  Function Description: Prompts the user for a seed value for random number generation
*
******+**-**-***-*---*-*-*--*-*--**-***---*-*-***--************************/
void getSeedValue(int *seed_value)
{
  // Executable Statements
  printf("Enter Seed For Time Generation -> ");
  scanf("%d", seed_value);

  return;
}

/*****+**-**-***-*---*-*-*--*-*--**-***---*-*-***--*************************
*
*  Function Information
*
*  Name of Function: generateRandomTimes
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int *time1_seconds - pointer to store first random time
*    2. int *time2_seconds - pointer to store second random time
*
*  Function Description: Generates two random times in seconds since midnight
*
******+**-**-***-*---*-*-*--*-*--**-***---*-*-***--************************/
void generateRandomTimes(int *time1_seconds, int *time2_seconds)
{
  // Executable Statements
  *time1_seconds = rand() % (SECONDS_PER_DAY + ONE);
  *time2_seconds = rand() % (SECONDS_PER_DAY + ONE);

  return;
}

/*****+**-**-***-*---*-*-*--*-*--**-***---*-*-***--*************************
*
*  Function Information
*
*  Name of Function: convertSecondsToTime
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int total_seconds - total seconds to convert
*    2. int *hours - pointer to store hours
*    3. int *minutes - pointer to store minutes
*    4. int *seconds - pointer to store seconds
*
*  Function Description: Converts total seconds to hours, minutes, and seconds format
*
******+**-**-***-*---*-*-*--*-*--**-***---*-*-***--************************/
void convertSecondsToTime(int total_seconds, int *hours, int *minutes, int *seconds)
{
  // Executable Statements
  *hours = total_seconds / SECONDS_PER_HOUR;
  *minutes = (total_seconds % SECONDS_PER_HOUR) / SECONDS_PER_MINUTE;
  *seconds = total_seconds % SECONDS_PER_MINUTE;

  return;
}

/*****+**-**-***-*---*-*-*--*-*--**-***---*-*-***--*************************
*
*  Function Information
*
*  Name of Function: displayTime
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int hours - hours value
*    2. int minutes - minutes value
*    3. int seconds - seconds value
*
*  Function Description: Displays time in HH-MM-SS format
*
******+**-**-***-*---*-*-*--*-*--**-***---*-*-***--************************/
void displayTime(int hours, int minutes, int seconds)
{
  // Executable Statements
  printf("Time (HH-MM-SS): %02d-%02d-%02d\n", hours, minutes, seconds);

  return;
}

/*****+**-**-***-*---*-*-*--*-*--**-***---*-*-***--*************************
*
*  Function Information
*
*  Name of Function: calculateTimeDifference
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int time1_seconds - first time in seconds
*    2. int time2_seconds - second time in seconds
*    3. int *diff_seconds - pointer to store the difference
*
*  Function Description: Calculates the absolute difference between two times in seconds
*
******+**-**-***-*---*-*-*--*-*--**-***---*-*-***--************************/
void calculateTimeDifference(int time1_seconds, int time2_seconds, int *diff_seconds)
{
  // Executable Statements
  *diff_seconds = abs(time1_seconds - time2_seconds);

  return;
}

/*****+**-**-***-*---*-*-*--*-*--**-***---*-*-***--*************************
*
*  Function Information
*
*  Name of Function: displayResults
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int time1_seconds - first time in seconds
*    2. int time2_seconds - second time in seconds
*    3. int diff_seconds - difference in seconds
*
*  Function Description: Displays all results including times and their differences in multiple formats
*
******+**-**-***-*---*-*-*--*-*--**-***---*-*-***--************************/
void displayResults(int time1_seconds, int time2_seconds, int diff_seconds)
{
  // Local Declarations
  int hours1;                              // First time hours component
  int minutes1;                            // First time minutes component
  int seconds1;                            // First time seconds component
  int hours2;                              // Second time hours component
  int minutes2;                            // Second time minutes component
  int seconds2;                            // Second time seconds component
  int diff_hours;                          // Difference hours component
  int diff_minutes;                        // Difference minutes component
  int diff_secs;                           // Difference seconds component
  double total_hours;                      // Total difference in hours
  double total_minutes;                    // Total difference in minutes

  // Executable Statements
  printf("\n");
  printf("Randomly Generated Times\n");
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  
  convertSecondsToTime(time1_seconds, &hours1, &minutes1, &seconds1);
  displayTime(hours1, minutes1, seconds1);
  
  convertSecondsToTime(time2_seconds, &hours2, &minutes2, &seconds2);
  displayTime(hours2, minutes2, seconds2);
  
  printf("\n");
  printf("Difference Between Times\n");
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  
  convertSecondsToTime(diff_seconds, &diff_hours, &diff_minutes, &diff_secs);
  displayTime(diff_hours, diff_minutes, diff_secs);
  
  total_hours = (double)diff_seconds / SECONDS_PER_HOUR;
  total_minutes = (double)diff_seconds / SECONDS_PER_MINUTE;
  
  printf("Total Hours: %.2f\n", total_hours);
  printf("Total Minutes: %.2f\n", total_minutes);
  printf("Total Seconds: %d\n", diff_seconds);

  return;
}
