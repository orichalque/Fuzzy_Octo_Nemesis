#include"EquipementFactory.hpp"

using namespace std;

EquipementFactory::EquipementFactory() {
	
}

EquipementFactory::~EquipementFactory() {

}

shared_ptr<Equipement> EquipementFactory::create(int i) {
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
		case 10:
			return make_shared<LeatherHelm>();
			break;
		case 11:
			return make_shared<IronHelm>();
			break;
		case 12:
			return make_shared<SteelHelm>();
			break;
		case 13:
			return make_shared<MithrilHelm>();
			break;
		case 14:
			return make_shared<Kunee>();
			break;
		case 15:
			return make_shared<Barrel>();
			break;
		case 16: 
		    return make_shared<LeatherShield>();
		    break;
		case 17:
			return make_shared<IronShield>();
			break;
		case 18:
			return make_shared<SteelShield>();
			break;
		case 19:
			return make_shared<Egid>();
			break;
		case 20:
			return make_shared<LeatherArmor>();
			break;
		case 21:
			return make_shared<IronArmor>();
			break;
		case 22:
			return make_shared<SteelArmor>();
			break;
		case 23:
			return make_shared<MithrilArmor>();
			break;
		case 24:
			return make_shared<Wall>();
			break;
	};
}


