#include <stdio.h>
#include "midi_lib.h"
#include "header.h"

void rockchord(Tset vars)
{
	// Declare 8 integer variables to hold times for chords.
	int chord1, chord2, chord3, chord4, chord5, chord6, chord7, chord8;
	
	// Assign the times for the chords to be played.
	chord1 = 0;
	chord2 = 400;
	chord3 = 800;
	chord4 = 1200;
	chord5 = 1600;
	chord6 = 2000;
	chord7 = 2400;
	chord8 = 2800;

	// At these times play a note at the key and the key plus an offset of 7.
	if(vars.time == chord1 || vars.time == chord2 || vars.time == chord4 || vars.time == chord6 || vars.time == chord8)
	{
		midi_note(vars.key, 2, vars.instc_velocity);
		midi_note(vars.key + 7, 2, vars.instc_velocity);
	}

	// At these times play a note at the key and the key plus an offset of 9.
	if(vars.time == chord3 || vars.time == chord7)
	{
		midi_note(vars.key, 2, vars.instc_velocity);
		midi_note(vars.key + 9, 2, vars.instc_velocity);
	}

	// At this time play a note at the key and the key plus an offset of 10.
	if(vars.time == chord5)
	{
		midi_note(vars.key, 2, vars.instc_velocity);
		midi_note(vars.key + 10, 2, vars.instc_velocity);
	}

	// At these times turn off all the notes.
	if(vars.time == 380 || vars.time == 780 || vars.time == 1180 || vars.time == 1580 ||
		vars.time == 1980 || vars.time == 2380 || vars.time == 2780 || vars.time == 3200)
	{
		midi_note(vars.key, 2, 0);
		midi_note(vars.key + 7, 2, 0);
		midi_note(vars.key + 9, 2, 0);
		midi_note(vars.key + 10, 2, 0);
	}			

	return;
}