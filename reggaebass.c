#include <stdio.h>
#include "midi_lib.h"
#include "header.h"

Tset reggaebass(Tset vars)
{	
	// Declare intger variables for the new bass note played and whether velocity was changed or not.
	int newbass, vel;
	
	/*
	 * Increase the velocity of every other note and decrease the other notes. Set the
	 * variable vel to 1 if increased to be used later.
	 */

	if(vars.instb_velocity >= 10)
	{
		if(vars.time == 0 || vars.time == 1600)
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

	// Assign the variable newbass to be the current key minus 12 as bass is an octave lower.
	newbass = (vars.key - 12);	

	// At certain times play the bass note and assign it to be the variable oldbass.
	if(vars.time == 0 || vars.time == 500 || vars.time == 1600 || vars.time == 2100)
	{
		vars.oldbass = newbass;		
		midi_note(newbass, 3, vars.instb_velocity);
	}

	// At certain times turn of the note at the key of variable oldnote.
	if(vars.time == 200 || vars.time == 800 || vars.time == 1800 || vars.time == 2400)
	{
		midi_note(vars.oldbass, 3, 0);	
	}

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
	
	return(vars);	// Return vars to keep track of the variable oldbass.
}