#include <stdio.h>
#include "midi_lib.h"
#include "header.h"

Tset rockbass(Tset vars)
{	
	// Declare variables for the note played and whether veloctiy has been changed.
	int newbass, vel;

	// Declare an array of integers to create a bassline.
	int offset[7] = {0, 0, 12, 0, 0, 12, 0};
	
	/*
	 * Increase the velocity of every other note and decrease the other notes. Set the
	 * variable vel to 1 if increased to be used later.
	 */

	if(vars.instb_velocity >= 10)
	{
		if(vars.time == 0 || vars.time == 1200 || vars.time == 2400)
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
	 * Set the new note to be played to be the key minus 12 to take into account the bass
	 * playing an octave lower plus the offset from the corresponding place in the array
	 * determined by the time.
	 */

	newbass = (vars.key - 12) + offset[vars.time/400];	
	
	// At certain times play the new note and assign it to be the variable oldbass.
	if(vars.time == 0 || vars.time == 400 || vars.time == 800 || vars.time == 1200 ||
		vars.time == 2000 || vars.time == 2400 || vars.time == 2800)
	{
		vars.oldbass = newbass;		
		midi_note(newbass, 3, vars.instb_velocity);
	}

	// At certain times turn off the note at the key of the variable oldbass.
	if(vars.time == 380 || vars.time == 780 || vars.time == 1180 || vars.time == 1580 ||
		vars.time == 2380 || vars.time == 2780 || vars.time == 3180)
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