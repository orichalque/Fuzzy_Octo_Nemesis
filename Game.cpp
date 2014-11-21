#include<iostream>
#include<cassert>
#include<string>
#include<memory>
#include<vector>
#include<ncurses.h>

#include "Item.cpp"
#include "Equipement.cpp"
#include "Shield.cpp"
#include "Armor.cpp"
#include "Weapon.cpp"
#include "Helmet.cpp"
#include "Weapons.hpp"
#include "Armors.hpp"
#include "Helmets.hpp"
#include "Shields.hpp"
#include "Character.cpp"
#include "Monster.cpp"
#include "Characters.hpp"
#include "Monsters.hpp"
#include "Weapons.hpp"
#include "Armors.hpp"
#include "Helmets.hpp"
#include "Shields.hpp"

#include "Factory.cpp"
#include "MonsterFactory.cpp"
#include "MonsterFactoryConcrete.cpp"

#include "BossFactory.cpp"
#include "EquipementFactory.cpp"

#include "Display/Screen.cpp"
#include "MapGenerator2/Rectangle.cpp"
#include "MapGenerator2/Leaf.cpp"
#include "MapGenerator2/Generator.cpp"


#include"Game.hpp"



Game::Game() {
    generator = make_shared<Generator>();
    screen = make_shared<Screen>();
    monsterFactory = make_shared<MonsterFactoryConcrete>();
    bossFactory = make_shared<BossFactory>();
    equipementFactory = make_shared<EquipementFactory>();
    level = 1;
}

Game::~Game() {
    //All Hail for the SmartPointers !
}

void Game::launchGame() {
    int x = 40 + generator -> getSize();
    int y = 18 + generator -> getSize();
    string str = "resize -s "+to_string(y)+" "+to_string(x);
    //resizing the window with a bash script
    system((char*)str.c_str());    
    screen -> init(); 
    //screen -> displayIntro(); 
    character = (screen -> chooseCharacter());
    screen -> windowBuilding(generator -> getSize());
}

void Game::moveCharacter() {
    int ch = getch();
    if ((ch == KEY_UP) or (ch == KEY_DOWN) or (ch == KEY_RIGHT) or (ch == KEY_LEFT)) {
        /* Update the model */
        character -> updatePosition(ch, generator -> getSize(), generator -> getMap());        
        /* Warn the view */ 
        generator -> updateCharPosition(character);
    }
}

void Game::equip(shared_ptr<Equipement> equipement) {
    if (equipement -> isWeapon()) {
        character -> setWeapon(equipement);
    } else 
    if (equipement -> isArmor()) {
        character -> setArmor(equipement);
    } else 
    if (equipement -> isHelmet()) {
        character -> setHelmet(equipement);
    } else
    if (equipement -> isShield()) {
        character -> setShield(equipement);
    }
    screen -> updateCharacterInfo(character);
}

void Game::generateMap() {
    generator -> init();
    generator -> split();
    generator -> createRoom();
    generator -> createHalls();
    generator -> buildMap();
    generator -> placeCharacter(character);
    generator -> placeMonsters(level, monsterFactory, bossFactory);
    screen -> updateCharacterInfo(character);
}

void Game::displayMap() {
    screen -> clearMap();
    vector< vector<char> > map = generator -> getMap();
    string line = "";
    string vLine = "";   
    for (int i = 0; i < (generator -> getSize() + 2); ++i) {
        vLine = vLine + "#";
    }   
    wattron(screen -> getWinMap(), COLOR_PAIR(1));
    screen -> mvprintMap(7,1,vLine);    
    screen -> mvprintMap(7,1+generator->getSize()+1,vLine);
    for (int i = 0; i < generator -> getSize(); i++) {
        line = "";
        line = line + "#";
        for (int j = 0; j < generator -> getSize(); j++) {
            line = line + map[j][i];
        }
        line = line + "#";
        screen -> mvprintMap(7, i+2, line);    
    }
    screen -> mvprintMap(2, generator -> getSize() +3, "Level "+to_string(level));
}

int Game::fight(shared_ptr<Character> monster) {
	bool fightEnd = false;
	int choice;
	int defense = character -> def();
	screen -> updateMonsterInfo(monster);
	while(!fightEnd) {
		screen -> mvprintTxt(2, 1, "Combat contre: "+monster -> name());
		choice = screen -> chooseAction();
		switch(choice){
			case 1: //attack
				screen -> mvprintTxt(2, 2, "Vous attaquez le monstre: "+monster -> name());
				this_thread::sleep_for(chrono::milliseconds(500));
				if (character -> hitFoe(monster)) {
					screen -> mvprintTxt(2, 3, "L'attaque inflige");
					screen -> mvprintTxt(22, 3, to_string(character -> attackFoe(monster)));
					screen -> mvprintTxt(26, 3, "points de dégats à l'adversaire!");
					
					if (monster -> life() <= 0) {
						fightEnd = true;
						/* loot */
					}
				} else {
					screen -> mvprintTxt(2, 3, "Mais l'attaque échoue! ");
				}
				break;
			case 2:
				screen -> mvprintTxt(2, 2, "Vous vous protégez! ");
				screen -> mvprintTxt(2, 3, "Défense améliorée pendant un tour." );
				screen -> mvprintTxt(2, 4, "Vous récouvrez un peu de votre vitalité." );
				character -> setDef(character -> defendFromFoe());
				character -> heal();
				break;
				
			case 3:
				screen -> mvprintTxt(2, 2, "Vous essayez de prendre la fuite, lâche ! ");
				
				if (character -> fleeFoe(monster)) {
					screen -> mvprintTxt(2, 3, "Vous réussissez à vous enfuir ! ");
					fightEnd = true;
				} else {
					screen -> mvprintTxt(2, 3, "L'ennemi vous rattrape!");
				}
				break;
		};
		
		screen -> updateCharacterInfo(character);
		screen -> updateMonsterInfo(monster);
		this_thread::sleep_for(chrono::milliseconds(500));		
		if (!fightEnd and character -> life() >= 0) {
			screen -> mvprintTxt(2, 5, "Tour de l'ennemi") ;
			screen -> mvprintTxt(2, 6, "L'ennemi vous attaque! ");
			if (monster -> hitFoe(character)) {
				screen -> mvprintTxt(2, 7, "Vous perdez "+ to_string(monster -> attackFoe(character))+ " points de vie!" );
				screen -> updateCharacterInfo(character);
				if (character -> life() <= 0) {
					fightEnd = true;
					/* SWITCH TO DEATH STATE */
					screen -> clearTxt();
					screen -> mvprintTxt(27, 2, "Vous êtes mort..." );
					getch();
				}
			} else {
				screen -> mvprintTxt(2, 7, "Mais son attaque échoue !" );
			} 
		} else {
			screen -> mvprintTxt(2, 5, "Victoire !") ;
			screen -> mvprintTxt(2, 6, "Vous récupérez un peu de santé. ");
			/* SWITCH TO LOOT STATE */
		}
		character -> setDef(defense);
		getch();
		screen -> clearTxt();
	}
}

int Game::loot(shared_ptr<Monster> monster) {
	screen -> clearTxt();
	vector< shared_ptr<Equipement> > loots;
    shared_ptr<Equipement> equipement;
    int ch; int x(18);
	for (int i : monster -> getLootList()) {
	    loots.push_back(equipementFactory -> create(i));
	}	
	
	while (not loots.empty()) {
   	    screen -> clearTxt();
	    equipement = loots.back();
	    screen -> mvprintTxt(2, 2, "Vous ramassez l'équipement: "+ equipement -> getName()+" !") ;
        screen -> getNewEquipement(equipement);
        if (equipement -> isWeapon()) {
            screen -> getMyEquipement(character -> getWeapon());
            if (screen -> equip()) {
                character -> setWeapon(equipement);
            }
        } else 
        if (equipement -> isHelmet()) {
            screen -> getMyEquipement(character -> getHelmet());
             if (screen -> equip()) {
                character -> setHelmet(equipement);
            }
        } else 
        if (equipement -> isArmor()) {
            screen -> getMyEquipement(character -> getArmor());
             if (screen -> equip()) {
                character -> setArmor(equipement);
            }
        } else 
        if (equipement -> isShield()) {
            screen -> getMyEquipement(character -> getShield());
             if (screen -> equip()) {
                character -> setShield(equipement);
            }
        }
		screen -> updateCharacterInfo(character);
    	this_thread::sleep_for(chrono::milliseconds(300));		
	    loots.pop_back();
	}
	
	screen -> mvprintTxt(2, 11, "Appuyez sur entrée") ;
	while ((ch=getch())!=10) {
	    
	}
	screen -> clearTxt();
	//end looting back to map
}

int main() {
    Game game;
    game.launchGame();
    game.generateMap();
    game.displayMap();
    game.generateMap();
    game.displayMap();
//    game.fight(make_shared<Troll>());
    game.loot(make_shared<HellHound>());
    while (true) {
        game.moveCharacter();
        game.displayMap();
    }
            
    /* endwin(); */
}
