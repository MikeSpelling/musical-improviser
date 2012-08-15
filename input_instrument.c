#include <stdio.h>
#include "midi_lib.h"
#include "header.h"

Tset input_instrument(Tset vars)
{
	/*
	 * Define 4 strings of 256 characters to hold the user input. They are 256
	 * characters long to prevent overflow error and allow the second character in the arrays 
	 * to be checked whether it is the end of file character or not.
	 */

	char num1[256], num2[256], num3[256], num4[256];
	int lead, chord, bass, drum;

	/*
	 * Prompt the user for the instrument and if an incorrect key is pressed print an error
	 * message, clear the standard input memory and repeat. Check that only one key has been
	 * pressed by looking at the second character in the string and making sure it is '\0'.
	 */

	do
	{
		fflush(stdin);
		printf("Choose lead instrument (1 Piano, 2 Distortion Guitar, 3 Nylon Guitar, 4 Sax, 5 Glockenspiel, 6 Steel drums, 0 Off): ");
		scanf("%s", &num1);

		/* Assign the variable lead to be the value of the first character in the num1
		 * array minus the value of '0'. This assigns the correct integer and prevents the
		 * program from crashing when a character is entered.
		 */

		lead = num1[0] - '0';
		
		if((lead != 1 && lead != 2 && lead != 3 && lead != 4 && lead != 5 && lead != 6 && lead != 0)
			|| num1[1] != '\0')
		{
			fflush(stdin);
			printf("Invalid choice please choose again\n\n");
		}
	}
	while((lead != 1 && lead != 2 && lead != 3 && lead != 4 && lead != 5 && lead != 6  && lead != 0)
		|| num1[1] != '\0');

	/*
	 * Prompt the user for the instrument and if an incorrect key is pressed print an error
	 * message, clear the standard input memory and repeat. Check that only one key has been
	 * pressed by looking at the second character in the string and making sure it is '\0'.
	 */

	do
	{
		// Clear the standard input memory, print a message and scan user for input.
		fflush(stdin);
		printf("Choose backing instrument (1 Piano, 2 Nylon Guitar, 3 Muted Guitar, 0 Off): ");
		scanf("%s", &num2);

		/*
		 * Assign the variable chord to be the value of the first character in the num2
		 * array minus the value of '0'.
		 */

		chord = num2[0] - '0';
	
		if((chord != 1 && chord != 2 && chord != 3 && chord != 0) || num2[1] != '\0')
		{
			fflush(stdin);
			printf("Invalid choice please choose again\n\n");
		}
	}
	while((chord != 1 && chord != 2 && chord != 3 && chord != 0) || num2[1] != '\0');

	/*
	 * Prompt the user for the instrument and if an incorrect key is pressed print an error
	 * message, clear the standard input memory and repeat. Check that only one key has been
	 * pressed by looking at the second character in the string and making sure it is '\0'.
	 */

	do
	{
		// Clear the standard input memory, print a message and scan user for input.
		fflush(stdin);
		printf("Choose bass instrument (1 Acoustic, 2 Electric, 0 Off): ");
		scanf("%s", &num3);

		/*
		 * Assign the variable bass to be the value of the first character in the num3
		 * array minus the value of '0'.
		 */

		bass = num3[0] - '0';
		
		if((bass != 1 && bass != 2 && bass != 0) || num3[1] != '\0')
		{
			fflush(stdin);
			printf("Invalid choice please choose again\n\n");
		}
	}
	while((bass != 1 && bass != 2 && bass != 0) || num3[1] != '\0');

	/*
	 * Prompt the user for the drums and if an incorrect key is pressed print an error
	 * message, clear the standard input memory and repeat. Check that only one key has been
	 * pressed by looking at the second character in the string and making sure it is '\0'.
	 */

	do
	{
		// Clear the standard input memory, print a message and scan user for input.
		fflush(stdin);
		printf("Drums (1 On, 0 Off): ");
		scanf("%s", &num4);

		/*
		 * Assign the variable drums to be the value of the first character in the num4 array
		 * minus the value of '0'.
		 */

		drum = num4[0] - '0';
		
		if((drum != 1 && drum != 0) || num4[1] != '\0')
		{
			fflush(stdin);
			printf("Invalid choice please choose again\n\n");
		}
	}
	while((drum != 1 && drum != 0) || num4[1] != '\0');

	/*
	 * Use switches for each integer entered by the user to assign instruments for the lead,
	 * chord and bass, and to turn drums on or off. Set their respective velocities to values
	 * recorded in the header file. Assign a value to the variable scroll to remember which
	 * instrument is being played.
	 */

	switch (lead)
	{
		case 1:
		{
			vars.instl_velocity = LEAD;
			program_change(1, 5);
			vars.instl_scroll = 1;
			break;
		}
		case 2:
		{
			vars.instl_velocity = LEAD;
			program_change(1, 31);
			vars.instl_scroll = 2;
			break;
		}
		case 3:			
		{
			program_change(1, 27);
			vars.instl_velocity = LEAD;
			vars.instl_scroll = 3;
			break;
		}
		case 4:
		{
			program_change(1, 67);
			vars.instl_velocity = LEAD;
			vars.instl_scroll = 4;
			break;
		}
		case 5:
		{
			program_change(1, 10);
			vars.instl_velocity = LEAD;
			vars.instl_scroll = 5;
			break;
		}
		case 6:
		{
			program_change(1, 115);
			vars.instl_velocity = LEAD;
			vars.instl_scroll = 0;
			break;
		}
		case 0:
		{			
			program_change(1, 5);
			vars.instl_velocity = 0;
			vars.instl_scroll = 1;
			break;
		}
	}
	
	switch (chord)
	{
		case 1:
		{	
			program_change(2, 5);
			vars.instc_velocity = CHORD;
			vars.instc_scroll = 1;
			break;
		}
		case 2:
		{	
			program_change(2, 27);
			vars.instc_velocity = CHORD;
			vars.instc_scroll = 2;
			break;
		}
		case 3:
		{	
			program_change(2, 29);
			vars.instc_velocity = CHORD;
			vars.instc_scroll = 0;
			break;
		}
		case 0:
		{	
			program_change(2, 5);
			vars.instc_velocity = 0;
			vars.instc_scroll = 1;
			break;
		}
	}	

	switch (bass)
	{
		case 1:
		{	
			program_change(3, 33);
			vars.instb_velocity = BASS;
			vars.instb_scroll = 1;
			break;
		}

		case 2:
		{	
			program_change(3, 34);
			vars.instb_velocity = BASS;
			vars.instb_scroll = 0;
			break;
		}

		case 0:
		{
			program_change(3, 33);
			vars.instb_velocity = 0;
			vars.instb_scroll = 1;
			break;
		}
	}

	switch (drum)
	{
		case 0:
		{
			vars.drum_vel = 0;
			break;
		}
		case 1:
		{
			vars.drum_vel = DRUM;
			break;
		}
	}	
	return(vars);	// Return the chosen values in the structure vars to the main function.
}