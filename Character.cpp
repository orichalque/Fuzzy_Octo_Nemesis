#include"Armor.cpp"
#include"Helmet.cpp"
#include"Weapon.cpp"
#include<memory>
#include<iostream>
#include<cassert>
#include<string>
#include "Character.hpp"

using namespace std;


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~Constructor~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

Character::Character(string _name, string _desc) {
	name_ = _name;
	desc_ = _desc;
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


/*~~~~~~~~~~~~~~~~~~~~~Deplacement methods~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void Character::moveRight(void) {
	/*
	* add map size assertion 
	*/
	x_ = x_ + 1;
}

void Character::moveLeft(void) {
	/*
	* add map size assertion 
	*/
	x_ = x_ - 1;
}

void Character::moveUp(void) {
	/*
	* add map size assertion 
	*/
	y_ = y_ - 1;
}

void Character::moveDown(void) {
	/*
	* add map size assertion 
	*/
	y_ = y_ + 1;
}

int main() {

}

