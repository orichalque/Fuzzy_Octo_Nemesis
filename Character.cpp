
using namespace std;


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~Constructor~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

Character::Character(string _name, string _desc) {
	name = _name;
	desc = _desc
	life = 0;
	attack = 0;
	def = 0;
	dext = 0;
	x = 0;
	y = 0;
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

void Character::substractLife(int damages) {
	assert(
}
