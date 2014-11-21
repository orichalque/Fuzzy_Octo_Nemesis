#include "Character.hpp"

using namespace std;


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~Constructor~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

Character::Character() {
}

Character::~Character() {
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Getters~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int Character::life(void) {
	return life_;
}

int Character::attack(void) {
	return attack_;
}

int Character::def(void) {
	return def_;
}

int Character::dext(void) {
	return dext_;
}


int Character::getCombinedAtt(void) {
    int x = attack_;
    if (weapon != NULL) {
        x += weapon -> getAtt();
    }
    if (shield != NULL) {
        x += shield -> getAtt();
    }
    if (armor != NULL) {
        x += armor -> getAtt();
    }
    if (helmet != NULL) {
        x += helmet -> getAtt();
    } 
	return x;
}

int Character::getCombinedDef(void) {
	int x = def_;
    if (weapon != NULL) {
        x += weapon -> getDef();
    }
    if (shield != NULL) {
        x += shield -> getDef();
    }
    if (armor != NULL) {
        x += armor -> getDef();
    }
    if (helmet != NULL) {
        x += helmet -> getDef();
    } 
	return x;
}

int Character::getCombinedDext(void) {
	int x = dext_;
    if (weapon != NULL) {
        x += weapon -> getDext();
    }
    if (shield != NULL) {
        x += shield -> getDext();
    }
    if (armor != NULL) {
        x += armor -> getDext();
    }
    if (helmet != NULL) {
        x += helmet -> getDext();
    } 
	return x;
}


int Character::x(void) {
	return x_;
}

int Character::y(void) {
	return y_;
}

string Character::name(void) {
	return name_;
}

string Character::desc(void) {
	return desc_;
}

char Character::getSymbol(void) {
	return symbol_;
}

shared_ptr<Equipement> Character::getWeapon() {
    return weapon;
}

shared_ptr<Equipement> Character::getShield() {
    return shield;
}

shared_ptr<Equipement> Character::getHelmet() {
    return helmet;
}

shared_ptr<Equipement> Character::getArmor() {
    return armor;
}   

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Setters~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void Character::setLife(int _life) {
	life_ = _life;
}

void Character::setAttack(int _attack) {
	attack_ = _attack;
}

void Character::setDef(int _def) {
	def_ = _def;
}

void Character::setDext(int _dext) {
	dext_ = _dext;
}

void Character::setX(int _x) {
	x_ = _x;
}

void Character::setY(int _y) {
	y_ = _y;
}

void Character::setName(string _name) {
	name_ = _name;
}

void Character::setDesc(string _desc) {
	desc_ = _desc;
}

void Character::setWeapon(shared_ptr<Equipement> weap) {
    weapon = weap;
}

void Character::setHelmet(shared_ptr<Equipement> helm) {
    helmet = helm;
}

void Character::setArmor(shared_ptr<Equipement> arm) {
    armor = arm;
}

void Character::setShield(shared_ptr<Equipement> shie) {
    shield = shie;
}
/*~~~~~~~~~~~~~~~~~~~~~~~OthersMethods~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/*
 * Substract life after taking damage
 */
void Character::substractLife(int damages) {
	assert(damages >= 0);
	life_ = life_ - damages;
}

/*
 * Obtain life after regenerating
 */
void Character::addLife(int heal) {
	assert(heal >= 0);
	life_ = life_ + heal;
}



/*
 * Define if an attack hits the ennemi
 */
bool Character::hitFoe(shared_ptr<Character> monster) {
	int dif = 100*(dext_ / monster -> dext());	 
	return (rand()%100 < dif);
}

/*
 * Attack the opposite monster
 */
int Character::attackFoe(shared_ptr<Character> monster) {
	int degats = getCombinedAtt() - (monster -> def());
	if (degats<0) {
		degats = 0;
	}
	monster -> setLife((monster -> life() - degats));
	return degats;
}
 
/*
 * Defend from the opposite monster
 */
int Character::defendFromFoe() {
	return (1.5 * getCombinedDef());
}

/*
 * Try to run away from the fight !
 */
bool Character::fleeFoe(shared_ptr<Character> monster) {
	int dif = 100*(dext_ / monster -> dext());	 
	return (rand()%100 < (dif+5));
}


/*~~~~~~~~~~~~~~~~~~~~~Deplacement methods~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void Character::updatePosition(int ch, int size, vector< vector<char> > map) {
    switch(ch) {
        case KEY_UP:
            if (y_ > 0 and map[x_][y_-1] != '#') {
                -- y_;
            }
            break;
        case KEY_DOWN:
            if (y_ < size-1 and map[x_][y_+1] != '#') {
                ++y_;
            }
            break;
        case KEY_RIGHT:
            if (x_ < size-1 and map[x_+1][y_] != '#') {
                ++x_;
            }
            break;
        case KEY_LEFT:
            if (x_ > 0 and map[x_ -1][y_] != '#') {
                --x_;
            }
            break;
    };
}



