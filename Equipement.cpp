#include "Equipement.hpp"

Equipement::~Equipement() {

}

bool Equipement::isEquipement() {
	return true;
}	    

int Equipement::getAtt() {
	return att;
}

int Equipement::getDef() {
	return def;
}
		
int Equipement::getDext() {
	return dext;
}

bool Equipement::isHelmet() {
    return false;
}

bool Equipement::isShield(){
    return false;
}

bool Equipement::isArmor(){
    return false;
}

bool Equipement::isWeapon(){
    return false;
}
