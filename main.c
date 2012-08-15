#include <stdio.h>
#include <conio.h>
#include "midi_lib.h"
#include "header.h"

int main(void)
{
	// Assign a structure called vars of type Tset, defined in the header, and an integer chance.
	Tset vars;
	int chance;

	// Call the rhythm function to prompt the user for the variable rhythm.
	vars.rhythm = rhythm();	
	
	// Call the pitch function to prompt the user for the pitch to be assigned to the variable key.
	vars.key = pitch();
	
	// Set the variable original to be the chosen key so it can be returned to needed later.
	vars.original = vars.key;

	// Call the speed function to prompt the user for the time to wait to be assigned to the variable tempo.
	vars.tempo = speed();

	// Call the input_instrument function to prompt the user for the 3 instruments to be stored in the structure vars.
	vars = input_instrument(vars);
	
	// Set starting variables to 0.
	vars.loop = 0;
	vars.time = 0;
	vars.count = 0;
	vars.luck = 0;
	vars.melody = random_number(1, 3);
	vars.shift = 0;

	// Display the user interface.
	messages(vars);

	// Run the loop while the variable loop equals 0.
	while(vars.loop == 0)
	{
		// Check if a key has been pressed and if so call the function keypress and re-display messages.
		if(kbhit() == 1)
		{
			vars = keypress(vars);
			messages(vars);
		}

		// Assign the variable chance a random number.
		chance = random_number(1,4);
		
		/*
		 * Call the function lead if time is equal to a set of times stored in the header file
		 * and if the variable chance equals 1.
		 */

		if(LEAD_TIME && chance == 1)
			vars = lead(vars);

		// Check which style of music the user has chosen.
		if(vars.rhythm == 1)
		{
			/*
			 * If user has chosen jazz call the functions for the jazzchord,
			 * jazzbass and jazzdrum
			 */

			vars = jazzbass(vars);
			jazzchord(vars);
			jazzdrum(vars);
		}

		// Check which style of music the user has chosen.
		if(vars.rhythm == 2)
		{
			/*
			 * If the user has chosen reggae call the functions for the reggaechord,
			 * reggaebass and reggaedrum.
			 */

			vars = reggaebass(vars);
			reggaechord(vars);
			reggaedrum(vars);
		}

		// Check which style of music the user has chosen.
		if(vars.rhythm == 3)
		{
			/*
			 * If the user has chosen rock call the functions for the rockchord,
			 * rockbass and rockdrum.
			 */

			vars = rockbass(vars);
			rockchord(vars);
			rockdrum(vars);
		}

		// Pause for a length of time determined by the variable tempo chosen by the user.
		pause(vars.tempo);
		
		// Call the counter function to keep track of timing.
		vars = counter(vars);
	}

	// Call the end function to stop music and close the screen.
	end(vars);

	return 0;
}