#include <stdio.h>
#include "midi_lib.h"
#include "header.h"

int rhythm()
{
	/*
	 * Define a string of 256 characters to hold the user input variable rhythm. It is 256
	 * characters long to prevent overflow error and allow the second character in the array
	 * to be checked whether it is the end of file character or not. It is made of
	 * characters rather than integers to prevent the program crashing when an invalid
	 * character is pressed.
	 */

	char rhythm[256];

	/*
	 * Prompt the user for the rhythm and if an incorrect key is pressed print an error message
   	 * and repeat. Check that only one key has been pressed by looking at the second character
	 * in the string and making sure it is '\0'.
	 */

	do
	{
		fflush(stdin);
		printf("Choose rhythm (1 Jazz, 2 Reggae, 3 Rock): ");
		scanf("%s", &rhythm);
		if((rhythm[0] != '1' && rhythm[0] != '2' && rhythm[0] != '3') || rhythm[1] != '\0') 
			printf("Invalid rhythm please choose again.\n\n");
	}
	while((rhythm[0] != '1' && rhythm[0] != '2' && rhythm[0] != '3') || rhythm[1] != '\0');

	// Depending on which number was chosen assign that number to the first place in the string.	
	if(rhythm[0] == '1')
		rhythm[0] = 1;
	if(rhythm[0] == '2')
		rhythm[0] = 2;
	if(rhythm[0] == '3')
		rhythm[0] = 3;
	
	return(rhythm[0]);	// Return the first number in the string rhythm.
}