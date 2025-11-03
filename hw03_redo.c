/**
 * Idea: input a random number seed of the form: 0 to 86400 (number of seconds since midnight) inclusive
 * convert to time format, hours, minutes, seconds.
 * 
 * Heres the loose idea:
 * use mathematical formula to ensure that each number in set has same chance of being generated
 * (need previous number generated, but how to start?)
 * need a seed
 * generated pseudorandom series:
 * 
 * seed -> randFunct -> first rand -> randFunct -> second rand -> ...
 * 
 * C privides two functions to build random numbers, srand and rand, both in stdlib.h
 * 
 * srand, or teh seed random function creates the starting seed, void srand(unsigned int seed)
 * 
 * t make same series in each run, either omit srand or use srand with prime, like srand(997);
 * 
 * to use the time, use srand(time(NULL)) to use teh time, in time.h, as the seed
 * 
 * rand returns an integer between 0 and RAND_MAX (at least 32,767, but depends on implimentation)
 * 
 * from here, you map the range into a usable range for you, either real-numner sereies like 0.0 to 1.0, or something else
 * 
 * Trick: rand() % range + minimum
 * can be used to get any integer range of values, assuming rand() max is creater than range, so can map to all teh values
 * 
 * For Rand Reals.
 *  (float)rand() / RAND_MAX;
 * 
 */

 #include <stdio.h>
 #include <stdlib.h>

 int getUserSeed(void);
 void outputTime(int hours, int minutes, int days);
 void outputGeneratedTime
