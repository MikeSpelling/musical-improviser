#include <stdio.h>
#include <conio.h>
#include "midi_lib.h"
#include "header.h"


Tset keypress(Tset vars)
{
	// Declare an integer variable assign the value of the users key press to it.
	int input;
	input = getch();

	/*
	 * Use a switch to check if the key pressed corresponds to any control keys and if
	 * so edit the approriate variable.
	 */

	switch(input)
	{
		case '1':
		{
			vars.instl_velocity = 0;			
			break;
		}
		case 'q':
		{
			vars.instc_velocity = 0;
			break;
		}
		case 'a':
		{
			vars.instb_velocity = 0;
			break;
		}
		case 'z':
		{
			vars.drum_vel = 0;
			break;
		}
		case '3':
		{
			vars.instl_velocity += 5;
			break;
		}
		case 'e':
		{
			vars.instc_velocity += 5;
			break;
		}
		case 'd':
		{
			vars.instb_velocity += 5;
			break;
		}
		case 'c':
		{
			vars.drum_vel += 5;
			break;
		}
		
		/*
		 * In cases where velocity is decreased check that the decreased value does not go
		 * negative before decreasing the variable.
		 */

		case '2':
		{
			if(vars.instl_velocity - 5 > 0)
			vars.instl_velocity -= 5;
			break;
		}
		case 'w':
		{
			if(vars.instc_velocity - 5 > 0)
			vars.instc_velocity -= 5;
			break;
		}
		case 's':
		{
			if(vars.instb_velocity - 5 > 0)
			vars.instb_velocity -= 5;
			break;
		}
		case 'x':
		{
			if(vars.drum_vel - 5 > 0)
			vars.drum_vel -= 5;
			break;
		}

		// Set the instruments velocitys to be at a standard value declared in the header file
		case '4':
		{
			vars.instl_velocity = LEAD;
			break;
		}
		case 'r':
		{
			vars.instc_velocity = CHORD;
			break;
		}
		case 'f':
		{
			vars.instb_velocity = BASS;
			fflush(stdin);
			break;
		}
		case 'v':
		{
			vars.drum_vel = DRUM;
			break;
		}

		/*
		 * In cases where tempo is decreased check that the decreased value does not go negative
		 * before decreasing the variable.
		 */

		case 'o':
		{
			if(vars.tempo - 2 > 0)
			vars.tempo--;
			break;
		}
		case 'i':
		{
			vars.tempo ++;
			break;
		}

		// This sets the variable loop to 1, stopping the main loop and terminating the program.
		case ' ':
		{
			vars.loop = 1;
			break;
		}
		case '5':
		{

			/*
			 * When changing the instrument the variable scroll checks which instrument
			 * is currently playing, changes it to the next instrument and adds 1 to scroll.
			 * At the last instrument scroll is reset and so as the key 5 is repeatedly pressed
			 * its cycles through the possible instruments.
			 */

			switch(vars.instl_scroll)
			{						
				case 0:
				{
					program_change(1, 5);
					vars.instl_scroll++;
					break;
				}
				case 1:
				{
					program_change(1, 31);
					vars.instl_scroll++;
					break;
				}
				case 2:
				{
					program_change(1, 27);
					vars.instl_scroll++;
					break;
				}
				case 3:
				{
					program_change(1, 67);
					vars.instl_scroll++;
					break;
				}
				case 4:
				{
					program_change(1, 10);
					vars.instl_scroll = 5;
					break;
				}
				case 5:
				{
					program_change(1, 115);
					vars.instl_scroll = 0;
					break;
				}
			}
			break;
		}
		case 't':
		{
			switch(vars.instc_scroll)
			{						
				case 0:
				{
					program_change(2, 5);
					vars.instc_scroll++;
					break;
				}
				case 1:
				{
					program_change(2, 27);
					vars.instc_scroll++;
					break;
				}
				case 2:
				{
					program_change(2, 29 );
					vars.instc_scroll = 0;
					break;
				}						
			}
			break;
		}
		case 'g':
		{
			switch(vars.instb_scroll)
			{						
				case 0:
				{
					program_change(3, 33);
					vars.instb_scroll++;
					break;
				}
				case 1:
				{
					program_change(3, 34);
					vars.instb_scroll = 0;
					break;
				}						
			}
			break;
		}
		case 'l':
		{
			vars.key++;
			break;
		}
		case 'k':
		{
			vars.key--;
			break;
		}
		
		/*
		 * Here the user has chosen to restart the program so turn off all midi notes,
		 * clear the screen and print a message. Calls the user input functions
		 * again and display the user input messages.
		 */

		case 8:
		{
			midi_note(vars.oldlead, 1, 0);
			midi_note(vars.key, 1, 0);
			midi_note(vars.oldbass, 3, 0);
			midi_note(vars.key, 3, 0);
			midi_note(vars.key, 2, 0);
			midi_note(vars.key + 7, 2, 0);
			midi_note(vars.key + 9, 2, 0);
			midi_note(vars.key + 10, 2, 0);
			midi_note(vars.key + 12, 2, 0);
			midi_note(vars.key + 15, 2, 0);
			midi_note(vars.key + 16, 2, 0);

			system ("cls");

			printf("Starting again...\n\nRe-enter values:\n\n");

			vars.rhythm = rhythm();	
			vars.key  = pitch();
			vars.tempo = speed();
			vars = input_instrument(vars);	
			vars.loop = 0;
			vars.time = 0;
			vars.count = 0;
			vars.luck = 0;
			vars.shift = 0;

			messages( vars);
			break;
		}
		
		/*
		 * Here the user is changing the rhythm so set the key back to its original value,
		 * reset shift, time and count and set the variable rhythm to the approriate value.
		 */

		case '8':
		{
			vars.key = vars.original;
			vars.shift = 0;
			vars.rhythm = 1;
			vars.time = 0;
			vars.count = 0;
			break;
		}
		case '9':
		{
			vars.key = vars.original;
			vars.shift = 0;
			vars.rhythm = 2;
			vars.time = 0;
			vars.count = 0;
			break;
		}
		case '0':
		{
			vars.key = vars.original;
			vars.shift = 0;
			vars.rhythm = 3;
			vars.time = 0;
			vars.count = 0;
			break;
		}
	}

	fflush(stdin);	// Clear the standard input memory

	return(vars);	// Return the altered vars
}
