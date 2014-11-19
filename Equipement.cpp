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

