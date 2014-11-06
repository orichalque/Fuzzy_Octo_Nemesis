
#ifndef DISPLAY_HPP
#define DISPLAY_HPP

class Display {
	private:
	
	public:
		Display(void);
		void display(std::string s);
		void windowBuilding(void);
		WINDOW* createWindow(int a, int b, int c, int d);
		void destroyWindow(WINDOW* local_win);
		void bold(void);
	
};

#endif

