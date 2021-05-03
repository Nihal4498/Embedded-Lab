/**************************************************************************************
* Use the "Half-Window"-UI (Ncurses) to realize LED-Switching function. The LED can	
* be activated by a event based key-function (keyboard hit kbhit). A small dialog shows
* the possible actions (set, reset and quit) 
* 03.06.2020
*
*/

/**************************************************************************************
*/

#include <stdio.h>
#include <sys/types.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

#include <wiringPi.h>
static int c;

int kbhit(void){	/* Function "keybordhit" gives a 1 back		*/ 
					/* when a key is pressed 			*/
					/* otherwise a 0.				*/			
	int ch = getch();

	if(ch != ERR) 
	{
		c = ch;
		return 1;
	} 
	else
	{
		return 0;
	}
}
 

int main()
{

	int row, col;
	int status = 0;		/* LED status		*/
	initscr();
	keypad (stdscr, TRUE);
	noecho();
	cbreak();
	nodelay(stdscr, TRUE);
	scrollok(stdscr, TRUE);
	getmaxyx(stdscr, row, col);
	mvprintw (2, (col/2)-14, "TESTSCREEN FOR LED");
	mvprintw (5, (col/2)-14, "Stopp Application with 'q'");
	mvprintw (11, (col/2)-14, "Set LED with 's'");
	mvprintw (12, (col/2)-14, "Reset LED with 'r'");
 	refresh();

	while (c != 113 ) {
		if (!kbhit()) {
			if (status == 0)
			{
				mvprintw (row-5, (col/2)-14, "LED = OFF");
			//	addch(' ');
			}
			else
			{
				mvprintw (row-5, (col/2)-14, "LED = ON ");
			//	addch(ACS_DIAMOND);
			}
			
			mvprintw(row-1,col-2, " ");		/* Move the cursur in bottom right position */
			refresh();
		}

		else{
			if (c == 115)       /* Condition for character 's' == 115  */
			{
				status = 1;
			}
			else if (c == 114)  /* Condition for character 'r' == 114  */
			{
				status = 0;
			}
		}
    }
	endwin();

	return 0;
}
