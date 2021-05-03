/**************************************************************************************
* Use the "Half-Window"-UI (Ncurses) to realize a value based input. The value are not	
* given by a numerial number instead of that with a increasing or decresing feature. 
* The range of the value are programmable and controlled/checked. The increasing and 
* decreasing function started with a eventbased Controlkey "arrow left" and "arrow right".
* 
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

static int c;

int kbhit(void){	/* Function "keybordhit" gives a 1 back		*/ 
					/* when a key is pressed 			*/
					/* otherwise a 0.				*/			
	int ch = getch();

	if(ch != ERR) {
		c = ch;
		return 1;
	} else{
		return 0;
	}
}
 

int main()
{

	int row, col;
	int val = 0;		/* Value 		*/
	int i, count;
	int delta_val = 5;	/*incremental/decremental value */
	initscr();
	keypad (stdscr, TRUE);
	noecho();
	cbreak();
	nodelay(stdscr, TRUE);
	scrollok(stdscr, TRUE);
	getmaxyx(stdscr, row, col);
	mvprintw (2, (col/2)-14, "TESTSCREEN FOR PROGRESS BAR");
	mvprintw (3, (col/2) -10, "CHANGE VALUE WITH");
	mvprintw (5, (col/2)-2," ");
	addch(ACS_LARROW);
	mvprintw (5, (col/2)+2," ");
	addch(ACS_RARROW);
	mvprintw (7, (col/2) -5, "RANGE 0 - 100");
	mvprintw (9, (col/2) -5, "Stopp with 'q'");
 	refresh();

	while (c != 113 ) {
		if (!kbhit()) {
			mvprintw (row-5, (col/2)-26, "[");
			mvprintw (row-5, (col/2)+25, "]");
			for(i = 0; i < 50; i++){
				mvprintw (row-5, (col/2)-25+i, " ");
			}
			count = 0;					/* Number of characters */
			while (count < val/2){
				mvprintw (row-5, (col/2)-25+count, "-");
				count++;
			}
			mvprintw (row-5, (col/2)+28, "VALUE --> %*d\n", 3, val);
			mvprintw(row-1,col-2, " ");		/* Move the cursur in bottom right position */
			refresh();
		}

		else{
			
			if (c == 261) /* Condition for checking right arrow press */
			{
				val = val + delta_val;
			}	 
			else if (c == 260) /* Condtion for checking left arrow press */
			{
				val = val - delta_val;
			}	
			if(val>100)
			{
				val =100;
			}
			if(val<0)
			{
				val =0;
			}
		}
    }
	endwin();

	return 0;
}
