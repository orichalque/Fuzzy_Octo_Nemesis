#include <cassert>
#include <string>
#include "Equipement.cpp"
#include "Helmet.hpp"

using namespace std;

Helmet::Helmet() 
{

}

Helmet::~Helmet() {

}

bool Helmet::isHelmet()
{
	return true;
}

bool Helmet::isEquipement()  {
    return true;
}


