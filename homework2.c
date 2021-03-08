/*
* Program: homework2.c
* Purpose: Orders an array of size 7 in increasing order
*          using Quick Sort
* Author: Giovanni Rivera
* Date: 03/08/2021
*/

//Defining the header files to use
#include <stdio.h>
//Defining constants using Macro
#define N 7
#define EMPTY 987654321

//declaring function prototypes
void quick_sort(int arrList[], int lowIndex, int highIndex);
int split(int arr[], int lowIndex, int highIndex);

//main (driver) function
int main(void)
{

  //declaring an array with an initialized value of 0
  int arr[N] = {0};

  //requesting for user input
  printf("Enter %d values to sort: ", N);
  scanf("%d %d %d %d %d %d %d", 
  &arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &arr[5], &arr[6]);

  //calling quick sort alorithm and passing array by reference
  quick_sort(arr, 0, N - 1);

  //printing sorted array
  printf("\nNew array reads: ");

  for (int num = 0; num < N; num++)
  {
    printf("%d ", arr[num]);
  }

  printf("\n");


  //exiting program
  return 0;
}

//recursive function for sorting the array using the quick sort 
//algorithm
void quick_sort(int arr[], int lowIndex, int highIndex)
{

  //base case for recursive formula
  if (lowIndex >= highIndex || lowIndex < 0 || highIndex >= N)
  {

    //stop recursion
    return;

  }
  
  //split the array into two
  int middleIndex = split(arr, lowIndex, highIndex);
  //check the first half
  quick_sort(arr, lowIndex, middleIndex - 1);
  //check the second half
  quick_sort(arr, middleIndex + 1, highIndex);
}

//returns a middle section of the array to split the array by
int split(int arr[], int lowIndex, int highIndex)
{
  //storing old values of lowIndex and highIndex for later use
  int oldStart = lowIndex;
  int oldEnd = highIndex;

  //local variable declaration
  int middleIndex;

  //setting the pivot of the array to start from
  int pivot = arr[lowIndex];
  arr[lowIndex] = EMPTY;

  //iterate until the current values match the pivot's location
  //(using lecture 8 [February 24] algorithm technique)
  while (lowIndex <= highIndex)
  {


    //if highIndex is not empty
    if (arr[highIndex] != EMPTY)
    {

      //check if matches pivot, else, switch
      //and keep same pivot
      if (arr[highIndex] >= pivot)
      {

        highIndex--;

      }
      else
      {

        arr[lowIndex] = arr[highIndex];
        lowIndex++;
        arr[highIndex] = (lowIndex >= highIndex) ? pivot : EMPTY;

      }

    }
    // if lowIndex is not empty
    else if (arr[lowIndex] != EMPTY)
    {
      
      //check if matches pivot, else, switch
      //and keep same pivot
      if (arr[lowIndex] <= pivot)
      {

        lowIndex++;

      }
      else
      {

        arr[highIndex] = arr[lowIndex];
        highIndex--;
        arr[lowIndex] = (lowIndex >= highIndex) ? pivot : EMPTY;

      }

    }
    //if both are empty
    else
    {
      if (arr[lowIndex] == EMPTY)
      {
        arr[lowIndex] = pivot;
      }
      else
      {
        arr[highIndex] = pivot;
      }
      break;
    }

  }

  //return the current pivot's index
  //(both highIndex and lowIndex contain its index)
  return lowIndex;
}