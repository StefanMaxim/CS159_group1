/*****+*--**-*-*-**--*-****-----**--**--*-*-*-***--*************************
*
*  Homework #:2
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified. Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work. I have not 
*  made use of any AI generated code in this solution. 
*
*  Program Description: Program to calculate the simple and compound interest for three different annual rates and compare them
*
******+*--**-*-*-**--*-****-----**--**--*-*-*-***--************************/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
  //local declarations:
  double amount; // the initial amount to invest.
  int term; //the term of the investment in years.
  int compound_frequency; //the frequency with which the interest is compounded.

  double annual_rate_1; // the first annual interest rate.
  double annual_rate_2; // the second annual interest rate.
  double annual_rate_3; // the third annual interest rate.

  int decimals_1;// the number of decimal points to display for the first annual interest rate value
  int decimals_2;// the number of decimal points to display for the second annual interest rate value
  int decimals_3;// the number of decimal points to display for the third annual interest rate value

  double simple_interest_amount_1; //the total amount of money in the simple interest account
  double compound_interest_amount_1; //the total amount of money in the compound interest account
  double simple_interest_earned_1;  //the amount of simple interest earned.
  double compound_interest_earned_1; //the amount of compound interest earned.
  double investment_difference_1; //the difference between the two investment amounts

  double simple_interest_amount_2; //the total amount of money in the simple interest account
  double compound_interest_amount_2; //the total amount of money in the compound interest account
  double simple_interest_earned_2;  //the amount of simple interest earned.
  double compound_interest_earned_2; //the amount of compound interest earned.
  double investment_difference_2; //the difference between the two investment amounts

  double simple_interest_amount_3; //the total amount of money in the simple interest account
  double compound_interest_amount_3; //the total amount of money in the compound interest account
  double simple_interest_earned_3;  //the amount of simple interest earned.
  double compound_interest_earned_3; //the amount of compound interest earned.
  double investment_difference_3; //the difference between the two investment amounts

  //executable statements:
  printf("Enter the initial amount -> ");
  scanf("%lf",&amount);

  printf("Enter the number of years -> ");
  scanf("%d",&term);

  printf("Enter compound frequency -> ");
  scanf("%d",&compound_frequency);

  printf("Enter three rates to compare -> ");
  scanf("%lf %lf %lf",&annual_rate_1,&annual_rate_2,&annual_rate_3);

  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

  simple_interest_amount_1 = amount * (1 + (annual_rate_1 / 100) * term); //annual rate is 5, but intended meaning is 5%
  compound_interest_amount_1 = amount * pow((1 + ((annual_rate_1 / 100) / compound_frequency)),(term * compound_frequency));
  simple_interest_earned_1 = simple_interest_amount_1 - amount;
  compound_interest_earned_1 = compound_interest_amount_1 - amount;
  investment_difference_1 = fabs(simple_interest_earned_1 - compound_interest_earned_1);

  simple_interest_amount_2 = amount * (1 + (annual_rate_2 / 100) * term); //annual rate is 5, but intended meaning is 5%
  compound_interest_amount_2 = amount * pow((1 + ((annual_rate_2 / 100) / compound_frequency)),(term * compound_frequency));
  simple_interest_earned_2 = simple_interest_amount_2 - amount;
  compound_interest_earned_2 = compound_interest_amount_2 - amount;
  investment_difference_2 = fabs(simple_interest_earned_2 - compound_interest_earned_2);

  simple_interest_amount_3 = amount * (1 + (annual_rate_3 / 100) * term); //annual rate is 5, but intended meaning is 5%
  compound_interest_amount_3 = amount * pow((1 + ((annual_rate_3 / 100) / compound_frequency)),(term * compound_frequency));
  simple_interest_earned_3 = simple_interest_amount_3 - amount;
  compound_interest_earned_3 = compound_interest_amount_3 - amount;
  investment_difference_3 = fabs(simple_interest_earned_3 - compound_interest_earned_3);

  //code find the number of decimal places to display:
  // less than 10 -> 1 pt, between 10 and 20, 2pts, 20 and 30 3 pts
  decimals_1 = (int)(annual_rate_1 / 10) + 1;
  decimals_2 = (int)(annual_rate_2 / 10) + 1;
  decimals_3 = (int)(annual_rate_3 / 10) + 1;

  printf("Principal $%10.2f | Years %2d | Compounded %2d times/year",amount,term,compound_frequency);
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("   Rate     Simple Amount    Compound Amount    Difference");
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

  printf("%7.*lf%% : $%12.2lf      $%12.2lf   $%12.2lf\n",decimals_1,annual_rate_1,simple_interest_amount_1,compound_interest_amount_1,investment_difference_1);
  printf("%7.*lf%% : $%12.2lf      $%12.2lf   $%12.2lf\n",decimals_2,annual_rate_2,simple_interest_amount_2,compound_interest_amount_2,investment_difference_2);
  printf("%7.*lf%% : $%12.2lf      $%12.2lf   $%12.2lf",decimals_3,annual_rate_3,simple_interest_amount_3,compound_interest_amount_3,investment_difference_3);
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

  return 0;
}