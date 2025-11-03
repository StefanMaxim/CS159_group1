/*****+**--*****-*---*-*-*--*-*-**---**---*-*-***--*************************
*
*  Homework #: 4
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified. Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work. I have not 
*  made use of any AI generated code in this solution. 
*
*  Program Description:
*
*  This program helps users decide between renting and buying a house by 
*  simulating mortgage growth using either compound or simple interest, chosen 
*  at random via a seeded coin flip. The program calculates the total cost of 
*  the house, computes the purchase-to-rent ratio, and outputs a final decision 
*  stating which option is financially better based on that ratio.
*
******+**--*****-*---*-*-*--*-*-**---**---*-*-***--************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void get_input(int *seed, double *monthly_rent, double *house_price,
               int *years, double *interest_rate, int *compound_frequency);

double calculate_total_price(double house_price, double interest_rate, int years,
                             int compound_frequency, int coin_flip, char **interest_type);

char* determine_decision(double ratio);

void display_results(const char *interest_type, double total_price,
                     double purchase_rent_ratio, const char *decision);

int main(void)
{
  int seed;
  int years;
  int compound_frequency;
  int coin_flip;
  double monthly_rent;
  double house_price;
  double interest_rate;
  double total_price;
  double purchase_rent_ratio;
  char *interest_type;
  char *decision;

  get_input(&seed, &monthly_rent, &house_price, &years, &interest_rate, &compound_frequency);

  srand(seed);
  coin_flip = rand();

  total_price = calculate_total_price(house_price, interest_rate, years,
                                      compound_frequency, coin_flip, &interest_type);

  purchase_rent_ratio = total_price / (monthly_rent * 12.0);
  decision = determine_decision(purchase_rent_ratio);

  display_results(interest_type, total_price, purchase_rent_ratio, decision);

  return 0;
}


/*****+*---***-*-*---*-*-*--*-*-**---**---*-*-***--*************************
*
*  Function Information
*
*  Name of Function: get_input
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int *seed               - pointer to store the random number generator seed
*    2. double *monthly_rent    - pointer to store the user's monthly rent
*    3. double *house_price     - pointer to store the house purchase price
*    4. int *years              - pointer to store the mortgage term in years
*    5. double *interest_rate   - pointer to store the annual interest rate
*    6. int *compound_frequency - pointer initialized to zero (set later if needed)
*
*  Function Description:
*    Prompts the user for all required input values including the random seed,
*    rent, purchase price, years, and interest rate. Initializes compound 
*    frequency to zero for later use when compound interest is chosen.
*
******+*---***-*-*---*-*-*--*-*-**---**---*-*-***--************************/
void get_input(int *seed, double *monthly_rent, double *house_price,
               int *years, double *interest_rate, int *compound_frequency)
{
  printf("Enter seed value -> ");
  scanf("%d", seed);

  printf("Enter the monthly rent amount -> ");
  scanf("%lf", monthly_rent);

  printf("Enter the house purchase price -> ");
  scanf("%lf", house_price);

  printf("Enter the years of mortgage -> ");
  scanf("%d", years);

  printf("Enter interest rate -> ");
  scanf("%lf", interest_rate);
  printf("\n");

  *compound_frequency = 0;
}


/*****+*---***-*-*---*-*-*--*-*-**---**---*-*-***--*************************
*
*  Function Information
*
*  Name of Function: calculate_total_price
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double house_price      - original price of the house
*    2. double interest_rate    - annual interest rate as a percentage
*    3. int years               - number of years of the mortgage
*    4. int compound_frequency  - number of times interest is compounded per year
*    5. int coin_flip           - random number used to select interest type (even=compound, odd=simple)
*    6. char **interest_type    - pointer to string storing chosen interest type ("Simple" or "Compound")
*
*  Function Description:
*    Uses the parity of the random number to determine whether to apply 
*    simple or compound interest to the mortgage calculation. Prompts the 
*    user for compound frequency if applicable. Returns the total cost 
*    of the house after interest is applied.
*
******+*---***-*-*---*-*-*--*-*-**---**---*-*-***--************************/
double calculate_total_price(double house_price, double interest_rate, int years,
                             int compound_frequency, int coin_flip, char **interest_type)
{
  double total_price;

  if (coin_flip % 2 == 0)
  {
    *interest_type = "Compound";
    printf("Enter compound frequency -> ");
    scanf("%d", &compound_frequency);
    printf("\n");

    total_price = house_price *
                  pow(1 + (interest_rate / 100.0) / compound_frequency,
                      compound_frequency * years);
  }
  else
  {
    *interest_type = "Simple";
    total_price = house_price * (1 + (interest_rate / 100.0) * years);
  }

  return total_price;
}


/*****+*---***-*-*---*-*-*--*-*-**---**---*-*-***--*************************
*
*  Function Information
*
*  Name of Function: determine_decision
*
*  Function Return Type: char*
*
*  Parameters (list data type, name, and comment one per line):
*    1. double ratio - purchase-to-rent ratio calculated from costs
*
*  Function Description:
*    Determines which financial option is better based on the computed
*    purchase-to-rent ratio. Returns the appropriate message string:
*    "Buying is better", "Renting is better", or "Both are similar".
*
******+*---***-*-*---*-*-*--*-*-**---**---*-*-***--************************/
char* determine_decision(double ratio)
{
  if (ratio < 15.0)
  {
    return "Buying is better";
  }
  if (ratio > 20.0)
  {
    return "Renting is better";
  }
  return "Both are similar";
}


/*****+*---***-*-*---*-*-*--*-*-**---**---*-*-***--*************************
*
*  Function Information
*
*  Name of Function: display_results
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. const char *interest_type  - specifies whether compound or simple interest was used
*    2. double total_price         - final house price including interest
*    3. double purchase_rent_ratio - ratio comparing house cost to yearly rent
*    4. const char *decision       - string indicating the final recommendation
*
*  Function Description:
*    Displays all formatted program results including the chosen interest
*    type, the calculated total house price, the purchase-to-rent ratio,
*    and the decision indicating whether buying or renting is better.
*
******+*---***-*-*---*-*-*--*-*-**---**---*-*-***--************************/
void display_results(const char *interest_type, double total_price,
                     double purchase_rent_ratio, const char *decision)
{
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Interest Type      : %s\n", interest_type);
  printf("House Total Price  : $%.2f\n", total_price);
  printf("Purchase/Rent Ratio: %.1f\n", purchase_rent_ratio);
  printf("Final Decision     : %s\n", decision);
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
}
