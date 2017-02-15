#include <ncurses.h>
#include <string.h>
#include <signal.h>
#include <curses.h>
#include <signal.h>

int row, col, max_col, num_cols, selected, running, ch, x, y;
/*
Row 
*/

int getcollength(char *strings[], int argc) {
    int collength = strlen(strings[1]);
    for (int i=1; i<argc; i++) {
        if (strlen(strings[i]) > collength) {
            collength = strlen(strings[i]);
        }
    }
    return collength;
}

void update_screen(char *strings[], int argc, int highlights[]) {
	clear();
	int counter = 0;
	x = 0; y = 0;
	for (int i =1; i< argc;i++) {
		if (selected == i && highlights[i] == 1) {
			attrset(A_STANDOUT | A_UNDERLINE);
		}
		else if (selected == i) {
			attrset(A_UNDERLINE);
		}
		else if(highlights[i] == 1) {
			attrset(A_STANDOUT);
		}
		else {
			attrset(A_NORMAL);
		}
		mvprintw(y, x, strings[i]);
		y++;
		counter++;

		if (counter >= row) {
			x = x + max_col;
            y = 0;
            counter = 0;
		}
	}
	refresh();
}

void print(char *strings[], int argc, int highlights[]) {
	for (int i=1;i< argc;i++) {
		if (highlights[i] == 1) {
			printf("%s", strings[i]);
			printf(" ");
		}
	}
	printf("\n");
}


int main(int argc, char *argv[]) {

	int highlights[argc];
	if (argc < 2) {
		printf("Usage: %s <a c file name>\n", argv[0]);
		return 1;
	}
    /*Find the max columnlength out of the arg values*/
    max_col = getcollength(argv, argc-1); 


	clear(); 
	initscr();		//Put terminal into curses mode
	keypad(stdscr, TRUE);
	curs_set(0);
	raw();
	cbreak();
	noecho();
    running = 1;
	while (running) {
		clear();
		getmaxyx(stdscr, row, col); //Finds boundaries of the screen and keeps them in row and column

		if (max_col != 0) {
			num_cols = col/max_col;
		}
		else {
			num_cols = 0;
		}
		update_screen(argv, argc, highlights);

        if(num_cols * row < argc-1) {
            clear();
            printw("Please enlarge the window.");
            refresh();
        }

        ch = getch();

        if(ch == 27) {
            endwin();
            running = 0;
        }
        else if(ch == 32) {    //Space Character, adds to selected
            if(highlights[selected] == 0) {
                highlights[selected] = 1;
                selected++;
            }
            else {
                highlights[selected] = 0;
            }
        }
        else if(ch == KEY_RIGHT) {
            selected += row;
            if(selected >= argc) {
                selected = argc-1;
            }
        }
        else if(ch == KEY_LEFT) {
            selected -= row;
            if(selected < 1) {
                selected = 1;
            }
        }
        else if(ch == KEY_UP) {
            selected--;
        }
        else if(ch == KEY_DOWN) {
            selected++;
        }
        else if(ch == '\n') {
            endwin();
            running = 0;
            print(argv, argc, highlights);
        }

        if(selected >= argc) {
            selected = 1;
        }
        else if(selected < 1) {
            selected = argc-1;
        }

    }

    return 0;
}