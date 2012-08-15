#include <stdio.h>
#include "midi_lib.h"
#include "header.h"

void rockdrum(Tset vars)
{
	/*
	 * At various times play a drum note at the drum velocity. The times and notes are
	 * carefully chosen to play an interesting and suitable rhythm.
	 */

	switch(vars.time)
	{
		case 0:
		{
			// Add random cymbal crashes determined by the variable luck.
			if(vars.luck <= 2)
				midi_note(49, 10, vars.drum_vel);
			midi_note(35, 10, vars.drum_vel);
			midi_note(42, 10, vars.drum_vel);
			midi_note(51, 10, vars.drum_vel);
			midi_note(53, 10, vars.drum_vel);
			break;
		}
		case 400:
			{
			midi_note(42, 10, vars.drum_vel);
			break;
			}
		case 800:
		{
			midi_note(42, 10, vars.drum_vel);
			midi_note(38, 10, vars.drum_vel);
			break;
		}
		case 1200:
		{
			midi_note(42, 10, vars.drum_vel);
			midi_note(35, 10, vars.drum_vel);
			break;
		}
		case 1600:
		{
			midi_note(42, 10, vars.drum_vel);
			midi_note(35, 10, vars.drum_vel);
			break;
		}
		case 2000:
		{
			// Add random claps determined by the variable luck.
			if(vars.luck ==1)
				midi_note(39, 10, vars.drum_vel);
			midi_note(42, 10, vars.drum_vel);
			break;
		}
		case 2400:
		{
			midi_note(42, 10, vars.drum_vel);
			midi_note(38, 10, vars.drum_vel);
			break;
		}
		case 2800:
		{
			// Add random claps determined by the variable luck.
			if(vars.luck ==1)
				midi_note(39, 10, vars.drum_vel);
			midi_note(42, 10, vars.drum_vel);
			break;
		}
	}

	return;
}