/*****+*--*-*--*----***-***----*-*--**----*-*-***--*************************
 *
 *  Lab #: 09
 *
 *  Academic Integrity Statement:
 *
 *  We have not used source code obtained from any other unauthorized source,
 *  either modified or unmodified. Neither have we provided access to our code
 *  to another. The effort we are submitting is our own original work. We have 
 *  not made use of any AI generated code in this solution. 
 *
 *  Program Description: This program will simulate a beginner game of blackjack. It will be a player against a simulated dealer. Each player will start with 100 credits and can choose the amount they bet each round. The number of rounds will be determines randomly by the program. 
 *
 ******+*--*-*--*----***-***----*-*--**----*-*-***--************************/
#include <stdio.h>
#include <stdlib.h>

#define CREDITS 100
#define MIN_BET 0
#define MAX_BET 100

//function declarations
int get_seed();
int get_bet();
int get_rounds();
void play_game(int, int, int *);
void play_round(int, int, int *);
int get_card();
void print_round_head(int);
void print_results(int, int, int, int *);

int main(void)
{
  //variable declarations
  int seed; //initialize seed
  int bet; //initialize bet
  int credits; //initialize credits
  int rounds; //initialize rounds

  credits = CREDITS;
  
  //function calls
  seed = get_seed();
  srand(seed);

  bet = get_bet();
  rounds = get_rounds();

  play_game(bet, rounds, &credits);

  return(0);
}

/*****+*-*****-**-**----*-**-----**--*----*-*-***--*************************
*
*  Function Information
*
*  Name of Function: get_seed
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1.
*    2.
*    3.
*
*  Function Description: This function will get the seed value from the user and use input validation.
*
******+*-*****-**-**----*-**-----**--*----*-*-***--************************/

int get_seed(void)
{
  int seed; // temporary storage for seed value

  printf("Enter starting seed value -> ");
  scanf("%d", &seed);

  while (seed < 0)
  {
    printf("\nERROR! Must enter a non-negative integer.\n\n");
    printf("Enter starting seed value -> ");
    scanf("%d", &seed);
  }
  return(seed);
}
/*****+*-*-***-**-**----*-**-----**--*----*-*-***--*************************
*
*  Function Information
*
*  Name of Function: get_bet
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. 
*    2.
*    3.
*
*  Function Description: This function will get user input for the bet and use the credits and input validation to make sure it is in the right range.
*
******+*-*-***-**-**----*-**-----**--*----*-*-***--************************/

int get_bet()
{
  int bet; // temporary storage for bet value

  printf("Enter your bet value -> ");
  scanf("%d", &bet);

  while (bet < MIN_BET || bet > MAX_BET || bet > CREDITS)
  {
    printf("\nERROR! Wager must be from 0 to 100.\n\n");
    printf("Enter your bet value -> ");
    scanf("%d", &bet);
  }
  return(bet);
}
/*****+*-*-***-**-**----*-**-----**--*----*-*-***--*************************
*
*  Function Information
*
*  Name of Function: get_rounds
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1.
*    2.
*    3.
*
*  Function Description: This function will get a random number for the amount of rounds they will play.
*
******+*-*-***-**-**----*-**-----**--*----*-*-***--************************/

int get_rounds(void)
{
  return (rand() % 3) + 1;
}
/*****+*-*-***-**-**----*-**-----**--*----*-*-***--*************************
*
*  Function Information
*
*  Name of Function: play_game
*
*  Function Return Type: none
*
*  Parameters (list data type, name, and comment one per line):
*    1. int bet- operand to calculate if there are enough credits
*    2. int rounds- operand to calculate if there are enough credits
*    3. int credits- operand to calculate if there are enough credits
*
*  Function Description: This function will calculate if there are enough credits to run the round or not.
*
******+*-*-***-**-**----*-**-----**--*----*-*-***--************************/

void play_game(int bet, int rounds, int *credits)
{
  int r; //the number of rounds iterator
  int played = 0; //the number of rounds played so far

  for (r = 1; r <= rounds && *credits >= bet; r++)
  {
    play_round(r, bet, credits);
    played++;
  }
  if (played < rounds && *credits < bet) 
  {
    printf("\nInsufficient credits to continue.\n");
  }
}
/*****+*-*-***-**-**----*-**-----**--*----*-*-***--*************************
*
*  Function Information
*
*  Name of Function: get_card
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1.
*    2.
*    3.
*
*  Function Description: This function will get a random number for the cards.
*
******+*-*-***-**-**----*-**-----**--*----*-*-***--************************/

int get_card(void)
{
  return(rand() % 10) + 1;
}
/*****+*-*-***-**-**----*-**-----**--*----*-*-***--*************************
*
*  Function Information
*
*  Name of Function: print_round_head
*
*  Function Return Type: none
*
*  Parameters (list data type, name, and comment one per line):
*    1. int round_num- operand to print the header
*    2.
*    3.
*
*  Function Description: This function will print the header for the print statement.
*
******+*-*-***-**-**----*-**-----**--*----*-*-***--************************/

void print_round_head(int round_num)
{
  printf("\nROUND %d        | Player | Dealer |\n", round_num);
}
/*****+*-*-***-**-**----*-**-----**--*----*-*-***--*************************
*
*  Function Information
*
*  Name of Function: play_round
*
*  Function Return Type: none
*
*  Parameters (list data type, name, and comment one per line):
*    1. int round_num- operand to calculate the total for the round
*    2. int bet- operand to calculate the total for the round
*    3. int credits- operand to calculate the total for the round
*
*  Function Description: This function will calculate the total scores for the player and dealer to determine who will win.
*
******+*-*-***-**-**----*-**-----**--*----*-*-***--************************/

void play_round(int round_num, int bet, int *credits)
{
  //local declaration
  int player_start; //initialize player_start
  int dealer_start; //initialize dealer_start
  int player_tot; //initialize player_tot
  int dealer_tot; //initialize dealer_tot
  int player_draw; //initialize player_draw
  int dealer_draw; //initialize dealer_draw

  //print results for starting hand and total
  print_round_head(round_num);

  player_start = get_card() + get_card();
  dealer_start = get_card() + get_card();

  printf("Starting Hand: |     %2d |     %2d |\n", player_start, dealer_start);

  player_draw = 0;
  player_tot = player_start;
  
  while (player_tot < 16)
  {
    player_tot += get_card();
    player_draw++;
  }

  if (player_tot > 21) 
  {
    dealer_tot = dealer_start;
    dealer_draw = 0;
  }
  else
  {
    dealer_draw = 0;
    dealer_tot = dealer_start;
    while (dealer_tot < 17)
    {
      dealer_tot += get_card();
      dealer_draw++;
    }
  }

  printf("Total (draws): | (%1d) %2d | (%1d) %2d |\n", player_draw, player_tot, dealer_draw, dealer_tot);

  print_results(player_tot, dealer_tot, bet, credits);
}
/*****+*-*-***-**-**----*-**-----**--*----*-*-***--*************************
*
*  Function Information
*
*  Name of Function: print_results
*
*  Function Return Type: none
*
*  Parameters (list data type, name, and comment one per line):
*    1. int player_tot- operand to print whether player wins, loses, or ties
*    2. int player_draw- operand to print whether player wins, loses, or ties
*    3. int dealer_tot- operand to print whether player wins, loses, or ties
*    4. int deal_draw- operand to print whether player wins, loses, or ties
*    5. int bet- operand to print whether player wins, loses, or ties depending on their bet
*    6. int credits- operand to print whether player wins, loses, or ties counting up the credits based on the bet
*
*  Function Description: This function will determine and print the results for the game on whether the player wins, loses, or ties using the bets and will add up the credits. 
*
******+*-*-***-**-**----*-**-----**--*----*-*-***--************************/

void print_results(int player_tot, int dealer_tot, int bet, int *credits)
{
  //print statements to print results depending on player total
  if (player_tot > 21)
  {
    *credits -= bet;
    printf("--- PLAYER LOSES. Credits: %3d ---\n", *credits);
  }
  else if (dealer_tot > 21)
  {
    *credits += bet;
    printf("--- PLAYER WINS! Credits: %3d ----\n", *credits);
  }
  else if (player_tot > dealer_tot)
  {
    *credits += bet;
    printf("--- PLAYER WINS! Credits: %3d ----\n", *credits);
  }
  else if (player_tot < dealer_tot)
  {
    *credits -= bet;
    printf("--- PLAYER LOSES. Credits: %3d ---\n", *credits);
  }
  else
  {
    printf("--- IT'S A TIE. Credits: %3d -----\n", *credits);
  }
}