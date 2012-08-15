#include <stdlib.h>
#include "midi_lib.h"
#include "header.h"

void end(Tset vars)
{
	// Turn off all notes.
	midi_note(vars.oldlead, 1, 0);
	midi_note(vars.oldbass, 3, 0);
	midi_note(vars.key, 2, 0);
	midi_note(vars.key + 7, 2, 0);
	midi_note(vars.key + 10, 2, 0);
	midi_note(vars.key + 15, 2, 0);

	// Clear the screen.
	system ("cls");

	return;
}