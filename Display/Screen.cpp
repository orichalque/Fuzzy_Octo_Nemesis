#include"Screen.hpp"

using namespace std;

/**
 * \fn Screen::Screen()
 * \brief Instancie l'écran
 * \param void
 * \return void
 */
Screen::Screen() {
	win = NULL;
	winTxt = NULL;
	winMap = NULL;
	winStat = NULL;
}

/**
 * \fn Screen::~Screen()
 * \brief Désalloue l'objet Screen
 * \param void 
 * \return void 
 */
Screen::~Screen() {
	if ((win != NULL) || (winTxt != NULL) || (winMap != NULL) || (winStat != NULL)) {
	    endwin();
	    //endwin() kill the WINDOW item from ncurses
	}
}

/**
 * \fn WINDOW* Screen::getWinStat(void)
 * \brief retourne la fenetre où sont affichées les statistiques
 * \param void 
 * \return WINDOW*
 */
WINDOW* Screen::getWinStat(void) {
    
    return winStat;
}

/**
 * \fn WINDOW* Screen::getWinTxt(void)
 * \brief retourne la fenetre où sont affichées les informations textuelles 
 * \param void 
 * \return WINDOW*
 */
WINDOW* Screen::getWinTxt(void) {
    return winTxt;
} 

/**
 * \fn WINDOW* Screen::getWinMap(void)
 * \brief retourne la fenetre ou est affichée la map
 * \param void 
 * \return WINDOW*
 */        
WINDOW* Screen::getWinMap(void) {
    return winMap;
}       

/**
 * \fn void Screen::clearTxt()
 * \brief Efface la fenetre de texte
 * \param void 
 * \return void
 */
void Screen::clearTxt() {
    wclear(winTxt);
    wborder(winTxt, '|', '|', '-', '-', '+', '+', '+', '+');
    wrefresh(winTxt);
}

/**
 * \fn void Screen::clearMap() 
 * \brief Efface la fenetre de la carte
 * \param void 
 * \return void 
 */    
void Screen::clearMap() {
    wclear(winMap);
    wborder(winMap, '|', '|', '-', '-', '+', '+', '+', '+');
    wrefresh(winMap);
}

/**
 * \fn void Screen::clearStat()
 * \brief Efface la fenetre des statistiques 
 * \param void 
 * \return void 
 */
void Screen::clearStat() {
    wclear(winStat);
    wborder(winStat, '|', '|', '-', '-', '+', '+', '+', '+');
    wrefresh(winStat);
}

/**
 * \fn void Screen::init(void)
 * \brief Initialise Ncurses et l'écran initial
 * \param void 
 * \return void 
 */        
void Screen::init(void) {
    initscr();
    refresh();
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    curs_set(0); //hide the cursor 
    keypad(stdscr, TRUE); //For keyboard complete use
    win = createWindow(LINES, COLS, 0, 0); //Initialise Main Window
    wrefresh(win);
}      

/**
 * \fn void Screen::displayMap(vector< vector<char> > map, int size, int level)
 * \brief Methode d'affichage de la carte
 *
 * \param vector< vector<char> > map, int size, int level
 * \return void
 *
 * Parcours la map du générateur, et l'affiche en fonction de la taille. Affiche aussi le niveau actuel en bas à droite
 */ 
void Screen::displayMap(vector< vector<char> > map, int size, int level) {
    clearMap();
    string line = "";
    string vLine = "";   
    // Add # at the top, the bottom, and the edges of the map for visual enhancement
    string fon = "~Fuzzy Octo Nemesis~";
    while (fon.length() != (size+2)) {
        fon = "#"+fon;
        fon = fon + "#";
    }
    
    for (int i = 0; i < (size + 2); ++i) {
        vLine = vLine + "#";
    }
      
    mvprintMap(7,1,fon);    
    mvprintMap(7,1+size+1,vLine);
    // parse each arrays of the matrix, put them in one string, and display it
    for (int i = 0; i < size; i++) {
        line = "";
        line = line + "#";
        for (int j = 0; j < size; j++) {
            line = line + map[j][i];
        }
        line = line + "#";
        mvprintMap(7, i+2, line);    
    }
    
    // level indicator
    mvprintMap(2, size +3, "Level "+to_string(level));
}
/**
 * \fn void Screen::displayIntro(void) 
 * \brief Affiche l'introduction
 * \param void 
 * \return void 

 */   
void Screen::displayIntro(void) {
    string s = "FUZZY OCTO NEMESIS";
    int x(COLS/2 - (0.5)*s.length());
    int y(LINES - 3); //Bottom of the window. -3 is meant to avoid erasing the borders of the window.
    while (y > LINES/2) {
         mvwprintW(x, y,this -> win, s);
         mvwprintW(x, y + 1 , this -> win, "                       ");
         wrefresh(win);
         y--;
         this_thread::sleep_for(chrono::milliseconds(150));
    }
    int ch(0);
    string s3 = "Browse - Kill - Loot - Repeat";
    mvwprintW(COLS/2 - (0.5)*s3.length(), y + 3, this -> win, s3);
    string s2 = "Press Enter";
    while (ch != 10) {
        mvwprintW(COLS/2 - (0.5)*s2.length(), y + 2, this -> win, s2);
        wrefresh(win);
        this_thread::sleep_for(chrono::milliseconds(500));
        mvwprintW(COLS/2 - (0.5)*s2.length(), y + 2, this -> win, "           ");
        wrefresh(win);
        ch = getch();
    } 
    win = createWindow(LINES, COLS, 0, 0); //Initialise Main Window
    wrefresh(win);
}

/**
 * \fn void Screen::windowBuilding(int size)
 * \brief Crée l'affichage de jeu en fonction de la taille de la map
 * \param int 
 * \return void
 */
void Screen::windowBuilding(int size) {
    //we assume that introduction has already been displayed
	winStat = createWindow(size +5 , 27, 0, 0);
	
	winMap = createWindow(size+5, size+13, 0, 27);
	
	winTxt = createWindow(LINES - (size + 5), COLS, LINES - 14, 0);
	getch();
}

/**
 * \fn void Screen::wprintW(WINDOW* win, string s)
 * \brief affiche une chaine de caracteres dans la fenetre en entrée
 * \param WINDOW* win, string s
 * \return void
 */
void Screen::wprintW(WINDOW* win, string s) {
    char* s2;
	s2 = (char*)s.c_str();
	wprintw(win, s2);
	wrefresh(win);
}

/**
 * \fn void Screen::mvprintStat(int x, int y, string s)
 * \brief affiche la chaine de caracteres en (X,Y) dans la fenetre stat
 * \param int x, int y, string s
 * \return void
 */
void Screen::mvprintStat(int x, int y, string s) {
    mvwprintW(x, y, winStat, s);
}

/**
 * \fn void Screen::mvprintMap(int x, int y, string s)
 * \brief affiche la chaine de caracteres en (X,Y) dans la fenetre map
 * \param int x, int y, string s
 * \return void
 */
void Screen::mvprintMap(int x, int y, string s) {
    mvwprintW(x, y, winMap, s);
}

/**
 * \fn void Screen::mvprintTxt(int x, int y, string s) 
 * \brief affiche la chaine de caracteres en (X,Y) dans la fenetre texte
 * \param int x, int y, string s
 * \return void
 */
void Screen::mvprintTxt(int x, int y, string s) {
    mvwprintW(x, y, winTxt, s);
}

/**
 * \fn void Screen::mvwprintW(int x, int y, WINDOW* win, string s)
 * \brief affiche la chaine de caracteres en (X,Y) dans la fenetre en entrée
 * \param int x, int y, WINDOW* win, string s
 * \return void
 */
void Screen::mvwprintW(int x, int y, WINDOW* win, string s) {
    char* s2;
	s2 = (char*)s.c_str();
	mvwprintw(win, y, x, "%s", s2);
	wrefresh(win);
}

/**
 * \fn void Screen::printW(std::string s)
 * \brief affichage la string sur l'écran
 * \param string s
 * \return void
 */
void Screen::printW(std::string s) {
    char* s2;
	s2 = (char*)s.c_str(); //most of ncurses methods don't allow string parameters, only char* ...
	printw(s2);
}

/** 
 * \fn shared_ptr<Character> Screen::chooseCharacter(void)
 * \brief Lance la séléction des personnages
 * \param void 
 * \return shared_ptr<Character>
 */
shared_ptr<Character> Screen::chooseCharacter(void) {
    /* Precondition : Screen already displayed, but not the maps */
    string choose = "Choisissez votre personnage";
    string key = "avec les touches directionnelles";
    int x = 0.5*(COLS - choose.length());
    int y = 2;
    mvwprintW(x, y, win, choose);
    x = 0.5*(COLS -key.length());
    mvwprintW(x, y+1, win, key);
    
    mvwprintW(13, 10, win, "Guerrier");
    mvwprintW(13, 12, win, "Un guerrier équilibré"  );
    mvwprintW(13, 13, win, "déjà armé d'un couteau");
    mvwprintW(13, 14, win, "et d'un bouclier");
    
    mvwprintW(45, 10, win, "Paladin");
    mvwprintW(45, 12, win, "Un soldat en armure" ); 
    mvwprintW(45, 13, win, "capable d'encaisser" );
    mvwprintW(45, 14, win, "des tonnes de dégats" );
    
    mvwprintW(13, 30, win, "Voleur");
    mvwprintW(13, 32, win, "Un rapide brigand"  );
    mvwprintW(13, 33, win, "armé d'une dague affutée");
    mvwprintW(13, 34, win, "et d'une bonne dexterité ");
    
    mvwprintW(45, 30, win, "Berserk");
    mvwprintW(45, 32, win, "Un sanguinaire"  );
    mvwprintW(45, 33, win, "assoiffé de combats, ");
    mvwprintW(45, 34, win, "fort et endurant. ");
    
	x = 10 ;
    y = 10 ;
    mvwprintW(x, y,win, "->");
    int button = getch();
    
    while (button != 10) {
    	mvwprintW(x, y,win, "->");
    	switch(button) {
    		case (KEY_UP):
    			if (y==30)  {
    				mvwprintW(x, y,win, "  ");
    				y = 10;
    			}
    			break;
    		case (KEY_DOWN):
    			if (y==10) {
    				mvwprintW(x, y, win,"  ");
    				y = 30;
    			}
    			break;
    		case (KEY_LEFT):
    			if (x==42)  {
    				mvwprintW(x, y,win, "  ");
    				x = 10;
    			}
    			break;
    		case (KEY_RIGHT):
    			if (x==10) {
    				mvwprintW(x, y, win,"  ");
    				x = 42;
    			}
    			break;
    	};
    	mvwprintW(x, y, win,"->");
    	
    	if (button != KEY_UP and button != KEY_DOWN and button != KEY_RIGHT and button != KEY_LEFT) {
		    mvwprintW(0.5*(COLS - 44), 40, win, "Choisissez avec les touches directionnelles!");
		    this_thread::sleep_for(chrono::milliseconds(1000));
		    mvwprintW(0.5*(COLS - 44), 40, win, "                                            ");
  		}
  		
    	button = getch();
    }

    
    if (x == 10 and y == 30) {
         mvwprintW(0.5*(COLS - 7), 40, win, "Voleur choisi !");
         this_thread::sleep_for(chrono::milliseconds(1000));
         return make_shared<Voleur>();
    } else if (x == 42 and y == 30) {
         mvwprintW(0.5*(COLS - 7), 40, win, "Berserk choisi !");
         this_thread::sleep_for(chrono::milliseconds(1000));
         return make_shared<Berserk>();
    } else if (x == 42 and y == 10) {
         mvwprintW(0.5*(COLS - 7), 40, win, "Paladin choisi !");
         this_thread::sleep_for(chrono::milliseconds(1000));
         return make_shared<Paladin>();
    } else if (x == 10 and y == 10) {
         mvwprintW(0.5*(COLS - 7), 40, win, "Guerrier choisi !");
         this_thread::sleep_for(chrono::milliseconds(1000));
         return make_shared<Guerrier>();
    }
}

/**
 * \fn void Screen::updateCharacterInfo(shared_ptr<Character> character)
 * \brief Affichage les informations du personnage dans la fenetre adéquate
 * \param shared_ptr<Character> character
 * \return void
 */
void Screen::updateCharacterInfo(shared_ptr<Character> character) {
    clearStat();
    mvprintStat(7, 1, character -> name());
    mvprintStat(1, 3, "Attaque: "+to_string(character -> getCombinedAtt()));
    mvprintStat(1, 4, "Defense: "+to_string(character -> getCombinedDef()));
    mvprintStat(1, 5, "Points de vie: "+to_string(character -> life()));
    mvprintStat(1, 6, "Dextérité: "+to_string(character -> getCombinedDext()));
 
    mvprintStat(7, 9, "Equipement");

    string s = "";
    if (character -> getShield() == NULL) {
        s = "Bouclier: Aucun";
    } else {
        s = "Bouclier: "+character -> getShield() -> getName();
    }
    mvprintStat(1, 11, s);   
    if (character -> getArmor() == NULL) {
        s = "Armure: Aucune";
    } else {
        s = "Armure: "+character -> getArmor() -> getName();
    }
    mvprintStat(1, 12, s);   
    if (character -> getHelmet() == NULL) {
        s = "Casque: Aucun";
    } else {
        s = "Casque: "+character -> getHelmet() -> getName();
    }
    mvprintStat(1, 13, s);   
    mvprintStat(1, 14, "Arme: "+character -> getWeapon() -> getName());
}

/**
 * \fn void Screen::updateMonsterInfo(shared_ptr<Character>monster)
 * \brief Affiche la vie du monstre pendant le combat
 * \param shared_ptr<Character> monster
 * \return void
 */
void Screen::updateMonsterInfo(shared_ptr<Character>monster) {
	mvprintTxt(COLS -22, 10, "Vie du monstre: "+to_string(monster -> life()));   
}

/**
 * \fn void Screen::getMyEquipement(shared_ptr<Equipement> equipement)
 * \brief affiche les statistiques de l'équipement actuel
 * \param shared_ptr<Equipement> equipement
 * \return void
 */
void Screen::getMyEquipement(shared_ptr<Equipement> equipement) {
    if (equipement == NULL) {
        mvprintTxt(2, 4, "Equipé: Rien") ;
        mvprintTxt(2, 5, "Attaque: 0"); 
        mvprintTxt(2, 6, "Defense: 0"); 
        mvprintTxt(2, 7, "Dexterité: 0"); 
    } else {
        mvprintTxt(2, 4, "Equipé: "+ equipement -> getName()) ;
        mvprintTxt(2, 5, "Attaque: "+ to_string(equipement -> getAtt())); 
        mvprintTxt(2, 6, "Defense: "+ to_string(equipement -> getDef())); 
        mvprintTxt(2, 7, "Dexterité: "+ to_string(equipement -> getDext())); 
    }
}

/**
 * \fn void Screen::getNewEquipement(shared_ptr<Equipement> equipement)
 * \brief Affiches les infos d'un nouvel équipement 
 * \param shared_ptr<Equipement> equipement
 * \return void
 */
void Screen::getNewEquipement(shared_ptr<Equipement> equipement) {
    mvprintTxt(40, 4, "Ramassé: "+ equipement -> getName()) ;
    mvprintTxt(40, 5, "Attaque: "+ to_string(equipement -> getAtt())); 
    mvprintTxt(40, 6, "Defense: "+ to_string(equipement -> getDef())); 
    mvprintTxt(40, 7, "Dexterité: "+ to_string(equipement -> getDext())); 
}

/**
 * \fn int Screen::chooseAction()
 * \brief Choisit les actions lors du combat et renvoit le choix associé
 * \param void 
 * \return int
 */        
int Screen::chooseAction() {
	enum choices:int { ATTACK = 1, DEFENSE=2, RUN=3};
	mvprintTxt(2, 9, "Choisissez votre action");
	mvprintTxt(4, 10, "Attaquer");
	mvprintTxt(16, 10, "Défendre");
	mvprintTxt(29, 10, "Fuir");
	mvprintTxt(2, 10, ">");
	int ch = getch();
	int x(2);
	while (ch != 10) {
		if (ch == KEY_RIGHT and x < 26) {
			mvprintTxt(x, 10, " ");
			mvprintTxt(x+12, 10, ">");
			x +=12;
		}
		
		if (ch == KEY_LEFT and x > 2) {
			mvprintTxt(x, 10, " ");
			mvprintTxt(x-12, 10, ">");
			x -=12;
		}
		ch = getch();
	}
	
	if (x == 2) {
		 mvprintTxt(x, 10, " "); 
		 return ATTACK;
	} else if (x == 14) {
		mvprintTxt(x, 10, " "); 
		return DEFENSE;
	} else if (x == 26) {
		mvprintTxt(x, 10, " "); 
		return RUN;
	}
	return ATTACK;
}

/**
 * \fn bool Screen::equip()
 * \brief Permet de choisir oui, ou non. Sert pour équiper un nouveau butin
 * \param void 
 * \return bool
 */
bool Screen::equip() { 
    int ch; int x(18);
    mvprintTxt(2, 9, "Equiper ?") ;
    mvprintTxt(x, 9, ">") ;
    mvprintTxt(20, 9, "Oui") ;
    mvprintTxt(30, 9, "Non") ;
    ch = getch();
    while (ch != 10) {
        if (ch == KEY_RIGHT and x == 18) {
            mvprintTxt(18, 9, " ") ;
            x += 10;
        }
           
        if (ch == KEY_LEFT and x == 28) {
            mvprintTxt(28, 9, " ") ;
            x -= 10;
        }
        mvprintTxt(x, 9, ">") ;
        ch = getch();
    }
        
    if (x == 18) {
        return true;        
    } else {
        return false;
    }
}

/**
 * \fn void Screen::endGameScreen(string s, shared_ptr<Character> character)
 * \brief Affiche l'écran de fin du jeu et le score
 * \param string s, shared_ptr<Character> character
 * \return void
 */ 
void Screen::endGameScreen(string s, shared_ptr<Character> character) {
	init();
	int x(COLS/2 - (0.5)*s.length());
    int y(LINES - 5); //Bottom of the window. -3 is meant to avoid erasing the borders of the window.
	while (y > 1) {
		mvwprintW(x, y, win, s);
		mvwprintW(x, y + 1 , win, "                ");
		wrefresh(win);
		y--;
		this_thread::sleep_for(chrono::milliseconds(150));
	}
	s = "Score : ";
	int score = character -> getCombinedDef() + character -> getCombinedDef() + character -> maxLife() + character -> getCombinedDext();
	s = s + to_string(score);
	y = LINES - 5;
	x = (COLS/2 - (0.5)*s.length());
	this_thread::sleep_for(chrono::milliseconds(1000));
	while (y > 2) {
	     mvwprintW(x, y, win, s);
	     mvwprintW(x, y + 1 , win, "                ");
	     wrefresh(win);
	     y--;
	     this_thread::sleep_for(chrono::milliseconds(150));
	}
	
	this_thread::sleep_for(chrono::milliseconds(1000));
	s = "Félicitations !";
	y = LINES - 5;	
	x = (COLS/2 - (0.5)*s.length());
	while (y > 3) {
	     mvwprintW(x, y, win, s);
	     mvwprintW(x, y + 1 , win, "                ");
	     wrefresh(win);					
	     y--;
	     this_thread::sleep_for(chrono::milliseconds(150));
	}
	string s2 = "Press Enter to exit";
	int ch(0);
	while (ch != 10) {
	    mvwprintW(COLS/2 - (0.5)*s2.length(), y + 2, win, s2);
	    wrefresh(win);
	    this_thread::sleep_for(chrono::milliseconds(1000));
	    mvwprintW(COLS/2 - (0.5)*s2.length(), y + 2, win, "                       ");
	    wrefresh(win);
	    ch = getch();
	}
}

/**
 * \fn WINDOW* Screen::createWindow(int height, int width, int starty, int startx)
 * \brief Crée la fenetre avec les paramètres entrés
 * \param int height, int width, int starty, int startx
 * \return WINDOW*
 */        
WINDOW* Screen::createWindow(int height, int width, int starty, int startx) {
	WINDOW *local_win;
	local_win = newwin(height, width, starty, startx);
	wattron(local_win, COLOR_PAIR(1));
	box(local_win, 0,0); // 0,0 : default characters for vertical and horizontal lines
	wborder(local_win, '|', '|', '-', '-', '+', '+', '+', '+');
	wrefresh(local_win); //show the box
	return local_win;
}

/**
 * \fn void Screen::destroyWindow(WINDOW* local_win)
 * \brief Détruit la fenêtre en entrée
 * \param WINDOW* local_win
 * \return void
 */
void Screen::destroyWindow(WINDOW* local_win) {
	wborder(local_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	//empty char for each corners and side of the window
	wrefresh(local_win);
	delwin(local_win);
}

