#include "Character.hpp"

using namespace std;


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~Constructor~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/**
 * \fn Character::Character()
 * \brief Constructeur de Character. Abstrait.
 *
 * \param void
 * \return nouvelle instance de Character
 *
 * Crée le personnage. Abstrait
 */ 
Character::Character() {
}

/**
 * \fn Character::~Character()
 * \brief Destructeur de Character
 *
 * \param void
 * \return void
 *
 * Aucun attribut a désallouer. 
 */ 
Character::~Character() {
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Getters~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/**
 * \fn int Character::life()
 * \brief getter de l'attribut vie
 *
 * \param void
 * \return int
 *
 */
int Character::life(void) {
	return life_;
}

/**
 * \fn int Character::attack()
 * \brief getter de l'attribut attack
 *
 * \param void
 * \return int
 *
 */
int Character::attack(void) {
	return attack_;
}

/**
 * \fn int Character::def()
 * \brief getter de l'attribut defense
 *
 * \param void
 * \return int
 *
 */
int Character::def(void) {
	return def_;
}

/**
 * \fn int Character::dext()
 * \brief getter de l'attribut dexterité
 *
 * \param void
 * \return int
 *
 */
int Character::dext(void) {
	return dext_;
}

/**
 * \fn int Character::maxLife()
 * \brief getter de l'attribut maxLife
 *
 * \param void
 * \return int
 *
 */
int Character::maxLife(void) {
	return maxLife_;
}

/**
 * \fn int Character::x()
 * \brief getter de l'attribut d'abscisse
 *
 * \param void
 * \return int
 *
 */
int Character::x(void) {
	return x_;
}

/**
 * \fn int Character::y()
 * \brief getter de l'attribut d'ordonnée
 *
 * \param void
 * \return int
 *
 */
int Character::y(void) {
	return y_;
}

/**
 * \fn string Character::name()
 * \brief getter de l'attribut nom
 *
 * \param void
 * \return string
 *
 */
string Character::name(void) {
	return name_;
}

/**
 * \fn string Character::desc()
 * \brief getter de l'attribut description
 *
 * \param void
 * \return string
 *
 */
string Character::desc(void) {
	return desc_;
}

/**
 * \fn char Character::getSymbol()
 * \brief getter de l'attribut symbol
 *
 * \param void
 * \return int
 *
 * Retourne le symbole du personnage, pour l'affichage graphique
 */
char Character::getSymbol(void) {
	return symbol_;
}

/**
 * \fn int Character::getCombinedAtt()
 * \brief renvoit l'attaque réelle du personnage
 *
 * \param void
 * \return int
 *
 * Parcourt les équipement et cumule leur attaque.
 */
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

/**
 * \fn int Character::getCombinedDef()
 * \brief renvoit la défense réelle du personnage
 *
 * \param void
 * \return int
 *
 * Parcourt les équipement et cumule leurs defenses.
 */
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

/**
 * \fn int Character::getEquipementDef()
 * \brief renvoit la défense cumulée des équipements du personnage
 *
 * \param void
 * \return int
 *
 * Parcourt les équipement et cumule leur attaque.
 */
int Character::getEquipementDef(void) {
	int x (0);
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

/**
 * \fn int Character::getCombinedDext()
 * \brief renvoit la dexterité réelle du personnage
 *
 * \param void
 * \return int
 *
 * Parcourt les équipement et cumule leurs dextérités.
 */
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

/**
 * \fn shared_ptr<Equipement> Character::getWeapon()
 * \brief renvoit l'arme du personnage
 *
 * \param void
 * \return shared_ptr<Equipement>
 *
 */
shared_ptr<Equipement> Character::getWeapon() {
    return weapon;
}

/**
 * \fn shared_ptr<Equipement> Character::getShield()
 * \brief renvoit le bouclier du personnage
 *
 * \param void
 * \return shared_ptr<Equipement>
 *
 */
shared_ptr<Equipement> Character::getShield() {
    return shield;
}

/**
 * \fn shared_ptr<Equipement> Character::getHelmet()
 * \brief renvoit le casque du personnage
 *
 * \param void
 * \return shared_ptr<Equipement>
 *
 */
shared_ptr<Equipement> Character::getHelmet() {
    return helmet;
}

/**
 * \fn shared_ptr<Equipement> Character::getArmor()
 * \brief renvoit l'armure du personnage
 *
 * \param void
 * \return shared_ptr<Equipement>
 *
 */
shared_ptr<Equipement> Character::getArmor() {
    return armor;
}   

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Setters~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/**
 * \fn void Character::setLife(int _life)
 * \brief modifie la vie du personnage
 *
 * \param int value
 * \return void
 *
 */
void Character::setLife(int _life) {
	life_ = _life;
}

/**
 * \fn void Character::setAttack(int value)
 * \brief modifie l'attaque du personnage
 *
 * \param int value
 * \return void
 *
 */
void Character::setAttack(int _attack) {
	attack_ = _attack;
}

/**
 * \fn void Character::setDef(int value)
 * \brief modifie la defense du personnage
 *
 * \param int value
 * \return void
 *
 */
void Character::setDef(int _def) {
	def_ = _def;
}

/**
 * \fn void Character::setDext(int value)
 * \brief modifie la dexterité du personnage
 *
 * \param int value
 * \return void
 *
 */
void Character::setDext(int _dext) {
	dext_ = _dext;
}

/**
 * \fn void Character::setX(int value)
 * \brief modifie l'ordonnée du personnage
 *
 * \param int value
 * \return void
 *
 */
void Character::setX(int _x) {
	x_ = _x;
}

/**
 * \fn void Character::setY(int value)
 * \brief modifie l'ordonnée du personnage
 *
 * \param int value
 * \return void
 *
 */
void Character::setY(int _y) {
	y_ = _y;
}

/**
 * \fn void Character::setName(string value)
 * \brief modifie le nom du personnage
 *
 * \param string value
 * \return void
 *
 */
void Character::setName(string _name) {
	name_ = _name;
}

/**
 * \fn void Character::setDesc(string value)
 * \brief modifie la description du personnage
 *
 * \param string value
 * \return void
 *
 */
void Character::setDesc(string _desc) {
	desc_ = _desc;
}

/**
 * \fn void Character::setWeapon(shared_ptr<Equipement> equipement)
 * \brief modifie l'arme du personnage
 *
 * \param shared_ptr<Equipement> equipement
 * \return void
 *
 */
void Character::setWeapon(shared_ptr<Equipement> weap) {
    weapon = weap;
}

/**
 * \fn void Character::setHelmet(shared_ptr<Equipement> equipement)
 * \brief modifie le casque du personnage
 *
 * \param shared_ptr<Equipement> equipement
 * \return void
 *
 */
void Character::setHelmet(shared_ptr<Equipement> helm) {
    helmet = helm;
}

/**
 * \fn void Character::setArmor(shared_ptr<Equipement> equipement)
 * \brief modifie l'armure du personnage
 *
 * \param shared_ptr<Equipement> equipement
 * \return void
 *
 */
void Character::setArmor(shared_ptr<Equipement> arm) {
    armor = arm;
}

/**
 * \fn void Character::setShield(shared_ptr<Equipement> equipement)
 * \brief modifie le bouclier du personnage
 *
 * \param shared_ptr<Equipement> equipement
 * \return void
 *
 */
void Character::setShield(shared_ptr<Equipement> shie) {
    shield = shie;
}

/*~~~~~~~~~~~~~~~~~~~~~~~OthersMethods~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/**
 * \fn void Character::substractLife(int damages)
 * \brief soustrait de la vie au personnage
 *
 * \param int damages
 * \return void
 *
 */
void Character::substractLife(int damages) {
	assert(damages >= 0);
	life_ = life_ - damages;
}


/**
 * \fn void Character::addLife(int heal)
 * \brief ajoute de la vie au personnage
 *
 * \param int heal
 * \return void
 * 
 */
void Character::addLife(int heal) {
	assert(heal >= 0);
	life_ = life_ + heal;
}

/**
 * \fn void Character::heal()
 * \brief ajoute de la vie au personnage
 *
 * \param int heal
 * \return void
 * 
 * Soigne le personnage de 0.05% de sa vie maximum
 */
void Character::heal() {
	int heal = 0.05*maxLife_;
	((life_+heal) <= maxLife_) ? addLife(heal) : addLife(maxLife_ - life_);
	
}


/**
 * \fn bool Character::hitFoe(shared_ptr<Character> monster)
 * \brief teste si une attaque touche l'ennemi
 *
 * \param shared_ptr<Character> monster
 * \return bool
 * 
 * Compare les dextérités, rajoute de l'aléatoire, et retourne vrai ou faux, si ça touche, ou nom.
 */
bool Character::hitFoe(shared_ptr<Character> monster) {
	//srand(time(NULL)+monster -> life());
	int value(0);
	if (getCombinedDext() >= monster -> getCombinedDext()) {
		value = 80;
	} else {
		value = 100*(getCombinedDext() / monster -> getCombinedDext());
		if (value < 50) value = 50;
	}
	
	return (rand()%100 < value);
}

/**
 * \fn int Character::attackFoe(shared_ptr<Character> opposant)
 * \brief soustrait les dégats à l'opposant
 *
 * \param shared_ptr<Character> monster
 * \return bool
 * 
 * Compare la défense combinée de l'attaquant à la défense combinée de l'adversaire, et soustrait la vie correspondante
 */
int Character::attackFoe(shared_ptr<Character> opposant) {
	int degats = getCombinedAtt() - (opposant -> getCombinedDef());
	if (degats<0) {
		degats = 0;
	}
	opposant -> substractLife(degats);
	return degats;
}
 
/**
 * \fn int Character::defendFromFoe()
 * \brief retourne une défense améliorée. 
 *
 * \param void
 * \return bool
 * 
 * Equivalent à getDef() * 1.5
 */
int Character::defendFromFoe() {
	return (def_ * 1.5) ;
}

/**
 * \fn bool Character::fleeFoe()
 * \brief teste si le personnage peut fuir
 *
 * \param shared_ptr<Character> monster
 * \return bool
 * 
 * compare les dextérités du personnage et de son opposant
 */
bool Character::fleeFoe(shared_ptr<Character> monster) {
	int dif = 100*(getCombinedDef() / monster -> dext());	 
	return (rand()%100 < (dif+5));
}


/*~~~~~~~~~~~~~~~~~~~~~Deplacement methods~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/**
 * \fn void Character::updatePosition(int ch, int size, vector< vector<char> > map)
 * \brief déplace le personnage
 *
 * \param int ch, int size, vector< vector<char> > map
 * \return void
 * 
 * déplace le personnage sur la map, et modifie la matrice d'affichage
 */
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



