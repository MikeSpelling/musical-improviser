#include <stdio.h>
#include "midi_lib.h"
#include "header.h"

void reggaechord(Tset vars)
{
	/*
	 * If the current time equals one of the times for a chord to be played turn on notes
	 * for the current key plus 3 offset pitches to create a chord. Add a 20ms gap between notes
	 * to simulate strumming.
	 */

	if(vars.time == 800 || vars.time == 1300 || vars.time == 2400 || vars.time == 2900)
	{
		midi_note(vars.key, 2, vars.instc_velocity);
		midi_note(vars.key + 7, 2, vars.instc_velocity);
		midi_note(vars.key + 12, 2, vars.instc_velocity);
		midi_note(vars.key + 16, 2, vars.instc_velocity);
	}

	/*
	 * If the current time equals one of the times for a chord to be turned off then
	 * turn off all the notes plus the offset notes.
	 */

	if(vars.time == 1280 || vars.time == 1600 || vars.time == 2880 || vars.time == 3200)
	{
		midi_note(vars.key, 2, 0);
		midi_note(vars.key + 7, 2, 0);
		midi_note(vars.key + 12, 2, 0);
		midi_note(vars.key + 16, 2, 0);
	}			

	return;
}