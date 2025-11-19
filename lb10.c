#include<stdio.h>
#include<stdlib.h>

#define SIZE 100 //use this size for the array

//FUNCTION DECLARATIONS
int getSeed(); 
void makeArr(int seed, int array[]);
int getGCD(int element1, int element2);
void setMin(int numSub,int* minSub,int* minElement1,int* minElement2,int element1,int element2);
void setMax(int numSub,int* maxSub,int* maxElement1,int* maxElement2,int element1,int element2);
void sumNums(int arrMinElement1,int arrMinElement2,int arrMaxElement1,int arrMaxElement2,int* minSums,int* maxSums);
void printResults(int minSub,int minElement1,int minElement2,int minSums,int maxSub,int maxElement1,int maxElement2,int maxSums);


int main()
{
  int seed;//the seed for the random
  int arr[100]; //the array which will be filled
  int element1; //an index pointing to the first element in the pairing
  int element2; //an integer pointing to the second element in the pairing
  int i; //looping variable
  int numSub; //the number of subtractions in the GCD function
  int minSub; //the fewest number of substractions to arrive at the GCD
  int minElement1; //the index of the first element which gave the fewest number of substractions
  int minElement2; //the index of the second element which gave the fewest nuber of substractions.
  int maxSub; // the maximum number of substractions to find GCD
  int maxElement1; //the index of the first element which gave the most number of substractions
  int maxElement2; //the index of the second element which gave the most number of substractions
  int minSums; //the sum of the two numbers which have the smallest number of subs
  int maxSums; //the sum of the two numbers which have the largest number of subs

  seed = getSeed();
  makeArr(seed,arr);
  element1 = 0;
  element2 = 99;
  for (i = 0; i < 50; i++)
  {
    numSub = getGCD(arr[element1],arr[element2]);
    setMin(numSub,&minSub,&minElement1,&minElement2,element1,element2);
    setMax(numSub,&maxSub,&maxElement1,&maxElement2,element1,element2);
    sumNums(arr[minElement1],arr[minElement2],arr[maxElement1],arr[maxElement2],&minSums,&maxSums);
  }
  printResults(minSub,minElement1,minElement2,minSums,maxSub,maxElement1,maxElement2,maxSums);
  return 0;
}

int getSeed()
{
  int seed;//local seed variable
  do 
  {
    printf("Enter desired seed value -> ");
    scanf("%d",&seed);
    printf("\n");
    if (seed < 0)
    {
      printf("\nError! Non-negative values only!\n\n");
    }
  } while (seed < 0);
}


