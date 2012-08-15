/*Lead is played on channel 1, chord on channel 2, bass on channel 3 and drums on the */
/*midi drum channel 10. Define the velocities for the instruments to be easily changed*/
#define BASS 60
#define CHORD 70
#define LEAD 65
#define DRUM 60

/*Define the times at which the lead could be played*/
#define LEAD_TIME (vars.time == 200  || vars.time == 400  || vars.time == 600  ||vars.time == 800 || vars.time == 1000 || vars.time == 1200 || vars.time == 1400 || vars.time == 1600 || vars.time == 1800 || vars.time == 2000 || vars.time == 2200 || vars.time == 2400 || vars.time == 2600 || vars.time == 2800 || vars.time == 3000 || vars.time == 3200)

/*Define a structure to hold all variables that need to be passed between functions*/
typedef struct
{
	int tempo, loop, time, luck, count, key, shift, oldlead, oldbass, rhythm, original, melody;
	int instb, instl, instc, instb_velocity, instb_scroll, instl_velocity, instl_scroll, instc_velocity, instc_scroll, drum_vel;
} Tset;

/*Declare all functions*/
Tset input_instrument();
Tset keypress(Tset vars);
Tset counter(Tset vars);
Tset lead(Tset vars);
Tset jazzbass(Tset vars);
Tset reggaebass(Tset vars);
Tset rockbass(Tset vars);
void messages(Tset vars);
void end(Tset vars);
void jazzchord(Tset vars);
void reggaechord(Tset vars);
void rockchord(Tset vars);
void jazzdrum(Tset vars);
void reggaedrum(Tset vars);
void rockdrum(Tset vars);
int rhythm();
int pitch();
int speed();