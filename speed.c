#include <stdio.h>

int speed()
{
	/*
	 * Define a string of 256 characters to hold the user input. It is 256
	 * characters long to prevent overflow error and allow the second character in the array
	 * to be checked whether it is the end of file character or not. It is made of
	 * characters rather than integers to prevent the program crashing when an invalid
	 * character is pressed. Also assign an integer tempo to hold the chosen time to
	 * return to the main function.
	 */

	char num[256];
	int tempo;

	/*
	 * Prompt the user for the speed and if an incorrect key is pressed print an error message
	 * and repeat. Check that only one key has been pressed by looking at the second character
	 * in the string and making sure it is '\0'.
	 */

	do
	{
		fflush(stdin);
		printf("Choose speed between 1 (slowest) and 6 (fastest): ");
		scanf("%s", &num);

		/*
		 * Assign the variable tempo to be the value of the first character in the num
		 * array minus the value of '0'. This assigns the correct integer and prevents the 
		 * program from crashing when a character is entered.
		 */

		tempo = num[0] - '0';
		
		if(tempo < 1 || tempo > 6 || num[1] != '\0')
		{
			fflush(stdin);
			printf("Invalid choice please choose again\n\n");
		}
	}
	while(tempo < 1 || tempo > 6 || num[1] != '\0');

	/*
	 * Depending on which speed was chosen assign a number which will be the amount of time
	 * the program pauses for each loop to tempo.
	 */

	switch(tempo)
	{
		case 1:
			tempo = 16;
			break;

		case 2:
			tempo = 14;
			break;

		case 3:
			tempo = 12;
			break;

		case 4:
			tempo = 10;
			break;

		case 5:
			tempo = 8;
			break;

		case 6:
			tempo = 6;
			break;
	}
	
	return (tempo);	// Return the value of tempo to the main function.
}