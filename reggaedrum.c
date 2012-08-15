#include <stdio.h>
#include "midi_lib.h"
#include "header.h"

void reggaedrum(Tset vars)
{
	/*
	 * At various times play a drum note at the drum velocity. The times and notes are
	 * carefully chosen to play an interesting and suitable rhythm.
	 */

	switch(vars.time)
	{
		case 0:
		{
			midi_note(36, 10, vars.drum_vel);
			break;
		}
		case 600:
		{
			midi_note(76, 10, vars.drum_vel);
			break;
		}
		case 800:
		{
			midi_note(46, 10, vars.drum_vel);
			break;
		}
		case 1600:
		{
			midi_note(31, 10, vars.drum_vel);
			break;
		}
		case 2200:
		{
			midi_note(76, 10, vars.drum_vel);
			break;
		}
		case 2400:
		{	
			midi_note(46, 10, vars.drum_vel);
			break;
		}
		case 3000:
		{	
			midi_note(42, 10, vars.drum_vel);
			break;
		}
	}
	return;
}