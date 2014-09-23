
using namespace std;


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~Constructor~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

Character::Character(string _name, string _desc) {
	name = _name;
	desc = _desc;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Getters~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int Character::life(void) {
	return life;
}

int Character::attack(void) {
	return attack;
}

int Character::def(void) {
	return def;
}

int Character::dext(void) {
	return dext;
}

int Character::x(void) {
	return x;
}

int Character::y(void) {
	return y;
}

string Character::name(void) {
	return name;
}

string Character::desc(void) {
	return desc;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Setters~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void Character::setLife(int _life) {
	life = _life;
}

void Character::setAttack(int _attack) {
	attack = _attack;
}

void Character::setDef(int _def) {
	def = _def;
}

void Character::setDext(int _dext) {
	dext = _dext;
}

void Character::setX(int _x) {
	x = _x;
}

void Character::setY(int _y) {
	y = _y;
}

void Character::setName(string _name) {
	name = _name;
}

void Character::setDesc(string _desc) {
	desc = _desc;
}

/*~~~~~~~~~~~~~~~~~~~~~~~OthersMethods~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/*
* Substract life after taking damage
*/
void Character::substractLife(int damages) {
	assert(damages >= 0);
	life = life - damages;
}

/*
* Obtain life after regenerating
*/
void Character::addLife(int heal) {
	assert(heal >= 0);
	life = life + heal;
}


/*~~~~~~~~~~~~~~~~~~~~~Deplacement methods~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void Character::moveRight(void) {
	/*
	* add map size assertion 
	*/
	x = x + 1;
}

void Character::moveLeft(void) {
	/*
	* add map size assertion 
	*/
	x = x - 1;
}

void Character::moveUp(void) {
	/*
	* add map size assertion 
	*/
	y = y - 1;
}

void Character::moveDown(void) {
	/*
	* add map size assertion 
	*/
	y = y + 1;
}
