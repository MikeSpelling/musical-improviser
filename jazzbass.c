#include <stdio.h>
#include "midi_lib.h"
#include "header.h"

Tset jazzbass(Tset vars)
{
	// Only run the jazzbass commands if the time is at certain values.
	if(vars.time == 400 || vars.time == 800 || vars.time == 1200 || vars.time == 1600 || vars.time == 2000 || vars.time == 2400 || vars.time == 2800)
	{
		/*
		 * Declare variables for the offset pitch, the note played and whether veloctiy has
		 * been changed.
		 */

		int offset, newbass, vel;

		// Declare 4 arrays of offset pitches to create 4 possible bass lines.
		int scale[7] = {0, 3, 5, 7, 12, 10, 7};
		int scale2[7] = {0, 0, 3, 3, 5, 7, 10};
		int scale3[7] = {7, 10, 7, 10, 7, 10, 12};
		int scale4[7] = {12, 10, 7, 10, 7, 5, 0};
		
		/*
		 * Increase the velocity of every other note and decrease the other notes. Set the
		 * variable vel to 1 if increased to be used later.
		 */

		if(vars.instb_velocity >= 10)
		{
			if(vars.time == 400 || vars.time == 1200 || vars.time == 2000 || vars.time == 2800)
			{
				vars.instb_velocity = vars.instb_velocity + 5;
				vel = 1;
			}
			else
			{
				vars.instb_velocity = vars.instb_velocity - 5;
				vel = 0;
			}
		}

		/*
		 * Decide which scale to use depending on the variable luck, which is assigned a
		 * random number every 3200ms in the function counter. Set the offset to be the
		 * corresponding integer in the array of bass notes using the equation
		 * '(current time/400) - 1'. The minus 1 takes into account the first place in the array
		 * is actually 0. The 400 is because a bass note is played every 400 ms.
		 */

		switch(vars.luck)
		{
		case 1:
			offset = scale2[(vars.time / 400) - 1];
			break;
			
		case 2:
			offset = scale3[(vars.time / 400) - 1];
			break;

		case 3:
			offset = scale4[(vars.time / 400) - 1];
			break;

		default:
			offset = scale[(vars.time / 400) - 1];
			break;
		}

		/*
		 * Add the offset to the current key, minus twelve as bass is an octave lower, and
		 * assign it to the variable newbass.
		 */

		newbass = (vars.key - 12) + offset;	

		/*
		 * Turn off the note at the pitch variable oldbass, assign the variable oldbass to equal
		 * the variable newbass and play a note at the pitch newbass.
		 */

		midi_note(vars.oldbass, 3, 0);
		vars.oldbass = newbass;		
		midi_note(newbass, 3, vars.instb_velocity);

		/*
	   	 * Use the variable vel to check if velocity has increased or decreased and return it
		 * to its original value unless velocity is 0 at which point the note should be off.
		 * This means that velocity doesnt randomly keep rising or falling but fluctuates around
		 * its given value.
		 */

		if(vars.instb_velocity != 0)
		{
			if(vel == 1)
				vars.instb_velocity = vars.instb_velocity - 5;
			else
				vars.instb_velocity = vars.instb_velocity + 5;
		}
	}
	
	return(vars);	// Return vars to keep track of the variable oldbass.
}