#include <stdio.h>
#include "midi_lib.h"
#include "header.h"

void jazzchord(Tset vars)
{
	// Declare 4 integer variables to contain the times at which the chord will be played.
	int chord1, chord2, chord3, chord4;
	
	/*
     * Use a switch to decide at which times the chord should be strummed using the variable
	 * luck. Assign these times to the 4 variables.
	 */

	switch(vars.luck)
	{
		case 1:
		{
			chord1 = 0;
			chord2 = 1200;
			chord3 = 2000;
			chord4 = 2400;
			break;
		}

		case 2:
		{
			chord1 = 400;
			chord2 = 1200;
			chord3 = 2000;
			chord4 = 2800;
			break;
		}
		
		default:
		{
			chord1 = 0;
			chord2 = 1200;
			chord3 = 2800;
			chord4 = 9999;	// This value is simply above 3200 so that it is never used.
		}
	}


	/*
	 * If the current time equals one of the times for a chord to be played turn on notes
	 * for the current key plus 3 offset pitches to create a chord. Add a 20ms gap between notes
	 * to simulate strumming.
	 */

	if(vars.time == chord1 || vars.time == chord2 || vars.time == chord3 || vars.time == chord4)
	{
		midi_note(vars.key, 2, vars.instc_velocity);
	}
	if(vars.time == chord1 + 20 || vars.time == chord2 + 20 || vars.time == chord3 + 20 || vars.time == chord4 + 20)
	{
		midi_note(vars.key + 7, 2, 0);
		midi_note(vars.key + 7, 2, vars.instc_velocity);
	}
	if(vars.time == chord1 + 40 || vars.time == chord2 + 40 || vars.time == chord3 + 40 || vars.time == chord4 + 40)
	{
		midi_note(vars.key + 10, 2, 0);
		midi_note(vars.key + 10, 2, vars.instc_velocity);
	}
	if(vars.time == chord1 + 60 || vars.time == chord2 + 60 || vars.time == chord3 + 60 || vars.time == chord4 + 60)
	{
		midi_note(vars.key + 15, 2, 0);
		midi_note(vars.key + 15, 2, vars.instc_velocity);
	}

	/*
	 * Check which strumming rhythm is being used using the variable luck and turn off notes
	 * at respective times.
	 */

	switch(vars.luck)
	{
		case 1:
		{
			if(vars.time == 800 || vars.time == 1600 || vars.time == 3200)
			{
				midi_note(vars.key, 2, 0);
				midi_note(vars.key + 7, 2, 0);
				midi_note(vars.key + 10, 2, 0);
				midi_note(vars.key + 15, 2, 0);
			}	
			break;
		}			
		default:
		{
			if(vars.time == 800 || vars.time ==  1600 || vars.time ==  2400 || vars.time == 3200)
			{
				midi_note(vars.key, 2, 0);
				midi_note(vars.key + 7, 2, 0);
				midi_note(vars.key + 10, 2, 0);
				midi_note(vars.key + 15, 2, 0);
			}
		}
	}
	return;
}