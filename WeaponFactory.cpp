#include "header.hpp"
#include "WeaponFactory.hpp"


WeaponFactory::WeaponFactory() {
	
}

WeaponFactory::~WeaponFactory() {

}

shared_ptr<Equipement> WeaponFactory::create(int i) {
	switch(i) {
		case 1:
			return make_shared<Knife>();
			break;
		case 2:
			return make_shared<Dagger>();
			break;
		case 3:
			return make_shared<ShortSword>();
			break;
		case 4:
			return make_shared<LongSword>();
			break;
		case 5:
			return make_shared<Claymore>();
			break;
		case 6:
			return make_shared<Rapier>();
			break;
		case 7:
			return make_shared<Excalibur>();
			break;
		case 8:
			return make_shared<Mjollnir>();
			break;
		case 9:
			return make_shared<Ragnarok>();
			break;	
	};
}

int main() {
	WeaponFactory f;
	cout << f.create(9) -> getDescription() << endl;
}
