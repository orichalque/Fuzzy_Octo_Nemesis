#include <cassert>
#include <string>
#include "Equipement.cpp"
#include "Shield.hpp"

using namespace std;

Shield::Shield() 
{

}

Shield::~Shield() {

}

bool Shield::isShield()
{
	return true;
}

bool Shield::isEquipement()  {
    return true;
}


