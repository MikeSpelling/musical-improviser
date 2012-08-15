#include <stdio.h>

int pitch()
{
	/*
	 * Define a string of 256 characters to hold the user input variable key. It is 256
	 * characters long to prevent overflow error and allow the second character in the array
	 * to be checked whether it is the end of file character or not. Also define an integer
	 * numkey to hold to respective number to represent the key.
	 */

	char key[256];
	int numkey;

	/*
	 * Prompt the user for the key and if an incorrect key is pressed print an error message
	 * and repeat. Check that only one key has been pressed by looking at the second character
	 * in the string and making sure it is '\0'.
	 */

	do
	{
		fflush(stdin);
		printf("Choose key (a, b, c, d, e, f or g): ");
		scanf("%s", &key);
		if((key[0] != 'a' && key[0] != 'b' && key[0] != 'c' && key[0] != 'd' && key[0] != 'e' && key[0] != 'f' && key[0] != 'g') 
			|| key[1] != '\0') 
			printf("Invalid key please choose again.\n\n");
	}
	while((key[0] != 'a' && key[0] != 'b' && key[0] != 'c' && key[0] != 'd' && key[0] != 'e' && key[0] != 'f' && key[0] != 'g')
		|| key[1] != '\0');

	// Depending on which key was chosen define numkey to be the representative number for that key.
	switch(key[0])
	{
		case 'a':
			numkey = 45;
			break;

		case 'b':
			numkey = 47;
			break;

		case 'c':
			numkey = 48;
			break;
				
		case 'd':
			numkey = 50;
			break;

		case 'e':
			numkey = 52;
			break;

		case 'f':
			numkey = 41;
			break;

		case 'g':
			numkey = 43;
			break;
	}
	
	return (numkey);	// Return the value of numkey to the main function.
}