#include <stdio.h>
#include "midi_lib.h"
#include "header.h"

Tset lead(Tset vars)
{
	/*
	 * Declare integer variables for a random number, the offset pitch, the new note to be
	 * played and whether velocity was changed or not. Also declare an array of 12 integers
	 * to hold the offsets in the scale. As these offsets depend on which rhythm is being 
	 * played assign the integers in if functions.
	 */

	int rand, offset, newlead, vel;
	int scale[12];

	/*
	 * Depending on the rhythm chosen by the user assign the integers in the array scale to be
	 * offset pitchs of a scale.
	 */

	if(vars.rhythm == 1)
	{
		scale[0] = 0;
		scale[1] = 3;
		scale[2] = 5;
		scale[3] = 7;
		scale[4] = 10;
		scale[5] = 12;
		scale[6] = 15;
		scale[7] = 17;
		scale[8] = 19;
		scale[9] = 22;
		scale[10] = 24;
		scale[11] = 27;
	}	
	if(vars.rhythm == 2)
	{
		scale[0] = 0;
		scale[1] = 2;
		scale[2] = 4;
		scale[3] = 7;
		scale[4] = 9;
		scale[5] = 12;
		scale[6] = 14;
		scale[7] = 16;
		scale[8] = 19;
		scale[9] = 21;
		scale[10] = 24;
		scale[11] = 26;
	}
	if(vars.rhythm == 3)
	{
		scale[0] = 12;
		scale[1] = 14;
		scale[2] = 16;
		scale[3] = 19;
		scale[4] = 21;
		scale[5] = 24;
		scale[6] = 26;
		scale[7] = 28;
		scale[8] = 31;
		scale[9] = 33;
		scale[10] = 36;
		scale[11] = 38;
	}

	/*
	 * Assign a random number to the variable rand and choose an integer from the array scale
	 * at that random number.
	 */

	rand = random_number(0, 11);
	offset = scale[rand];

	// Assign the variable newlead to be the current key plus the offset chosen.
	newlead = vars.key + offset;

	/*
	 * If velocity is not 0 and therefore the lead is being played decide whether to randomly
	 * increase or decrease velocity to add a sense of improvisation. If increased set the
	 * variable vel to 1.
	 */

	if(vars.instl_velocity >= 10)
	{
		if(rand <= 5)
		{			
			vars.instl_velocity = vars.instl_velocity + 5;
			vel = 1;
		}
		else
		{
			vars.instl_velocity = vars.instl_velocity - 5;
			vel = 0;
		}
	}
		
	// Turn off the old note, set the old note to be the new note and play the new note.
	midi_note(vars.oldlead, 1, 0);
	vars.oldlead = newlead;		
	midi_note(newlead, 1, vars.instl_velocity);

	/*
	 * Using vel to check how the velocity was changed, set velocity back to its starting point
	 * so that it doesnt randomly keep increasing or decreasing.
	 */

	if(vars.instl_velocity != 0)
	{
		if(vel == 1)
			vars.instl_velocity = vars.instl_velocity - 5;
		else
			vars.instl_velocity = vars.instl_velocity + 5;
	}

	return(vars);	// Return vars to store the old note so that it can be turned off next time.
}