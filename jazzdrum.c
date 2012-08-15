#include <stdio.h>
#include "midi_lib.h"
#include "header.h"

void jazzdrum(Tset vars)
{
	/*
	 * Play a number of drum notes at different times with the possibility of a random
	 * change when the variable luck is 2. This is just to add variation.
	 */

	if(vars.luck == 2)
	{
		/*
		 * At various times play a drum note at the drum velocity. The times and notes are
		 * carefully chosen to play an interesting and suitable rhythm.
		 */

		switch(vars.time)
		{
			case 0:
			{
				midi_note(51, 10, vars.drum_vel);
				break;
			}
			case 600:
			{
				midi_note(33, 10, vars.drum_vel);
				break;
			}
			case 800:
			{
				midi_note(51, 10, vars.drum_vel);
				break;
			}
			case 1400:
			{
				midi_note(33, 10, vars.drum_vel);
				break;
			}
			case 1600:
			{
				midi_note(51, 10, vars.drum_vel);
				break;
			}
			case 2200:
			{		
				midi_note(33, 10, vars.drum_vel);
				break;
			}
			case 2400:
			{
				midi_note(51, 10, vars.drum_vel);
				break;
			}
			case 3000:
			{		
				midi_note(33, 10, vars.drum_vel);
				break;
			}
		}
	}
	else
	{
		switch(vars.time)
		{
			case 0:
			{
				midi_note(51, 10, vars.drum_vel);
				break;
			}
			case 800:
			{
				midi_note(42, 10, vars.drum_vel);
				midi_note(33, 10, vars.drum_vel);
				break;
			}
			case 1400:
			{
				midi_note(42, 10, vars.drum_vel);
				midi_note(33, 10, vars.drum_vel);
				break;
			}
			case 1600:
			{
				midi_note(51, 10, vars.drum_vel);
				break;
			}
			case 2400:
			{
				midi_note(42, 10, vars.drum_vel);
				midi_note(33, 10, vars.drum_vel);
				break;
			}
			case 3000:
			{
			
				midi_note(42, 10, vars.drum_vel);
				midi_note(33, 10, vars.drum_vel);
				break;
			}		
		}
	}
	return;
}
