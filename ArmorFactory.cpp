#include"Factory.cpp"
#include"ArmorFactory.hpp"


ArmorFactory::ArmorFactory() {
	
}

ArmorFactory::~ArmorFactory() {

}

shared_ptr<Equipement> ArmorFactory::create(int i) {
	switch(i) {
		case 1:
			return make_shared<LeatherArmor>();
			break;
		case 2:
			return make_shared<IronArmor>();
			break;
		case 3:
			return make_shared<SteelArmor>();
			break;
		case 4:
			return make_shared<MithrilArmor>();
			break;
		case 5:
			return make_shared<Wall>();
			break;

	};
}
