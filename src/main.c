/****************************************************************************
 File name:  main.c
 Author:     chadd williams
 Date:       feb 18, 2022
 Class:      CS 460
 Assignment: Shell
 Purpose:    Demonstrate strtok_r
 ****************************************************************************/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/****************************************************************************
 Function:    main
 
 Description  Demonstrate strtok_r

 Parameters:  None

 Return:      None
 ****************************************************************************/
int main()
{
  char* pConstString = "Hello CS460   Students\tGood Luck!";
  char* pBigString;
  int totalCharactersAllocated =  strlen(pConstString) + 1;
  int i;

  // strtok_r alters the string so the first parameter
  // cannot be a constant string (like pConstString)
  pBigString = (char*) malloc( totalCharactersAllocated );
  memcpy (pBigString, pConstString, totalCharactersAllocated);

  // the token
  char *pToken;
  // allow strtok_r some space to save its progress
  char *pSavePtr;
   
  // count the number of tokens found
  int counter = 0;

  // Print each token that is separated by whitespace
  // You don't know what each token starts with
  // You don't know how much whitespace is between
  // each token.

  // find the first token and set the
  // pSavePtr correctly
  pToken = strtok_r(pBigString, " \t", &pSavePtr);

  counter ++;
  printf("%d: |%s|\n", counter, pToken);

  // each subsequent call to strtok_r should 
  // set the first parameter to NULL
  while( (pToken = strtok_r(NULL, " \t", &pSavePtr)))
  {
    counter ++;
    printf("%d: |%s|\n", counter, pToken);
  }

  // what is left in pBigString?
  printf("pBigString: %s\n", pBigString);

  for (i = 0 ; i < totalCharactersAllocated ; i ++ )
  {
    if( '\0' ==  pBigString[i] )
    {
      printf("[null]");
    }
    else
    {
      printf("%c", pBigString[i]);
    }
  }
  printf("\n\n");

  free(pBigString);

  return EXIT_SUCCESS; // for sure
}