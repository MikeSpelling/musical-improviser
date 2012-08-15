#include <stdio.h>
#include "midi_lib.h"
#include "header.h"

Tset counter(Tset vars)
{
	/*
	 * Add 20 to the variable time each loop unless it is equal or above 3200 at which point
	 * reset time to 0 and add 1 to the variable count. This keeps track of how many bars
     * of 3200ms have passed. It also generates a random number to assign to the
	 * variable luck.
	 */

	if(vars.time >= 3200)
	{
		vars.luck = random_number(1, 8);
		vars.time = 0;
		vars.count ++;
	}		
	else 
		vars.time += 20;
		
	/*
	 * To create structured bars of music change the pitch of notes when count reaches
	 * a certain amount, reset the count and then add 1 to the variable shift until the last
	 * change of pitch which resets the shift to bring it back to repeat itself. This creates
	 * a cyclic change of pitch.
	 */

	if(vars.melody > 1)
	{
		switch(vars.shift)
		{
			case 0:
			{
				if(vars.count == 2)
				{
					vars.key += 5;
					vars.shift = 1;
					vars.count = 0;
				}
				break;
			}
			case 1:
			{
				if(vars.count == 1)
				{
					vars.key -= 5;
					vars.shift = 2;
					vars.count = 0;
				}
				break;
			}
			case 2:
			{
				if(vars.count == 1)
				{
					vars.key += 7;
					vars.shift = 3;
					vars.count = 0;
				}
				break;
			}
			case 3:
			{
				if(vars.count == 1)
				{
					vars.key -= 2;
					vars.shift = 4;
					vars.count = 0;
				}
				break;
			}	
			case 4:
			{
				if(vars.count == 1)
				{
					vars.key -= 5;
					vars.shift = 5;
					vars.count = 0;
				}
				break;
			}	
			case 5:
			{
				if(vars.count == 2)
				{
					vars.key += 0;
					vars.shift = 0;
					vars.count = 0;
					vars.melody = random_number(1,3);
				}
				break;
			}	
		}
	}
	else
	{
		switch(vars.shift)
		{
			case 0:
			{
				if(vars.count == 2)
				{
					vars.key -= 2;
					vars.shift = 1;
					vars.count = 0;
				}
				break;
			}
			case 1:
			{
				if(vars.count == 1)
				{
					vars.key += 2;
					vars.shift = 2;
					vars.count = 0;
				}
				break;
			}
			case 2:
			{
				if(vars.count == 1)
				{
					vars.key += 7;
					vars.shift = 3;
					vars.count = 0;
				}
				break;
			}
			case 3:
			{
				if(vars.count == 1)
				{
					vars.key -= 2;
					vars.shift = 4;
					vars.count = 0;
				}
				break;
			}
			case 4:
			{
				if(vars.count == 1)
				{
					vars.key -= 5;
					vars.shift = 5;
					vars.count = 0;
				}
				break;
			}
			case 5:
			{
				if(vars.count == 2)
				{
					vars.shift = 0;
					vars.count = 0;
					vars.melody = random_number(1, 3);
				}
				break;
			}
		}
	}

	return(vars);	// Return the altered vars.
}
