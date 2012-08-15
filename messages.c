#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "header.h"

void messages(Tset vars)
{	
	int bpm;
	bpm = 1600/vars.tempo;

	// Clear the screen and display the user interface.
	system ("cls");	

	printf("\n Music playing... (Press backspace to start again)\n\n\n");
	
	printf("        Jazz    Reggae   Rock     Speed Down  Speed Up   Pitch Down  Pitch Up\n");
	printf(" All:     8       9        0         I            O          K           L\n\n"); 
	
	printf("        Mute    Vol Down  Vol Up  Normal      Change Instrument        \n");
	printf(" Lead:    1       2        3         4            5\n");
	printf(" Chords:  Q       W        E         R            T\n");
	printf(" Bass:    A       S        D         F            G\n");
	printf(" Drums:   Z       X        C         V\n\n");

	/*
	 * Use a switch on scroll to determine which instrument is playing and display it.
	 */

	switch(vars.instl_scroll)
	{						
		case 1:
		{
			printf(" Lead:		Piano			Volume:	%d\n", vars.instl_velocity);
			break;
		}
		case 2:
		{
			printf(" Lead:		Distortion guitar	Volume:	%d\n", vars.instl_velocity);
			break;
		}
		case 3:
		{
			printf(" Lead:		Nylon guitar		Volume:	%d\n", vars.instl_velocity);
			break;
		}
		case 4:
		{
			printf(" Lead:		Sax			Volume:	%d\n", vars.instl_velocity);
			break;
		}
		case 5:
		{
			printf(" Lead:		Glockenspiel		Volume:	%d\n", vars.instl_velocity);
			break;
		}
		case 0:
		{
			printf(" Lead:		Steel Drums		Volume:	%d\n", vars.instl_velocity);
			break;
		}
	}
	
	switch(vars.instc_scroll)
	{						
		case 1:
		{
			printf(" Chords:	Piano			Volume:	%d\n", vars.instc_velocity);
			break;
		}
		case 2:
		{
			printf(" Chords:	Nylon guitar		Volume:	%d\n", vars.instc_velocity);
			break;
		}
		case 0:
		{
			printf(" Chords:	Muted guitar		Volume:	%d\n", vars.instc_velocity);
			break;
		}
	}

	switch(vars.instb_scroll)
	{						
		case 1:
		{
			printf(" Bass:		Acoustic bass		Volume:	%d\n", vars.instb_velocity);
			break;
		}
		case 0:
		{
			printf(" Bass:		Electric Bass		Volume:	%d\n", vars.instb_velocity);
			break;
		}
	}

	switch(vars.rhythm)
	{
		case 1:
		{
			printf(" Drums:		Jazz			Volume:	%d\n", vars.drum_vel);
			break;
		}
		case 2:
		{
			printf(" Drums:		Reggae			Volume:	%d\n", vars.drum_vel);
			break;
		}
		case 3:
		{
			printf(" Drums:		Rock			Volume:	%d\n", vars.drum_vel);
			break;
		}
	}

	printf("\n Speed: %d BPM\n", bpm);
		
	printf("\n Press spacebar to exit");

	return;
}