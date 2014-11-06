#include<string>
#include<iostream>
#include<ncurses.h>
#include"Display.hpp"


/*http://en.tldp.org/HOWTO/NCURSES-Programming-HOWTO/windows.html*/
using namespace std;
void printW(string s);

Display::Display() {

}


WINDOW* Display::createWindow(int height, int width, int starty, int startx) {
	WINDOW *local_win;
	local_win = newwin(height, width, startx, starty);
	box(local_win, 0,0); // 0,0 : default characters for vertical and horizontal lines
	wrefresh(local_win); //show the box
	return local_win;
}

void Display::destroyWindow(WINDOW* local_win) {
	wborder(local_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	//empty char for each corners and side of the window
	wrefresh(local_win);
	delwin(local_win);
}

void Display::windowBuilding(void) {
	WINDOW *win;
	int x, y, width, height;
	int ch;
	initscr(); //start curses mode
	cbreak(); //line buffering disabled
	keypad(stdscr, TRUE);
	
	height = 5;
	width = 5;
	y = (LINES-height)/2; //calculation for a center placement
	x = (COLS - width) /2; //of the window
	printW("Press END to exit");
	refresh();
	win = createWindow(height, width, y, x);
	
	while ((ch=getch()) != KEY_END) {
		switch(ch) {
			case KEY_LEFT:
				destroyWindow(win);
				win = createWindow(height, width, y, --x);
				break;
			case KEY_RIGHT:
				destroyWindow(win);
				win = createWindow(height, width, y, ++x);
				break;
			case KEY_UP:
				destroyWindow(win);
				win = createWindow(height, width, --y, x);
				break;
			case KEY_DOWN:
				destroyWindow(win);
				win = createWindow(height, width, ++y, x);
				break;
		};
	}
	endwin();
	
}

void Display::display(string s){
	initscr();	
	printW(s);
	refresh();
	getch();
	endwin();
}


void Display::bold(){
	int ch;
	char* str;
	
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	
	printW("Type smthing to see it in bold");
	ch = getch();
	
	while(ch != KEY_END) {
		printW("The key pressed is: ");
		attron(A_BOLD);
		printw("%c\n", ch);
		attroff(A_BOLD);
		refresh();
		ch = getch();
	}
	endwin();
	
}

void printW(string s) {
	char* s2;
	s2 = (char*)s.c_str();
	printw(s2);
}

int main() {
	Display d;
	d.windowBuilding();
}
