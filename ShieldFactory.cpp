#include"Factory.cpp"
#include"ShieldFactory.hpp"


ShieldFactory::ShieldFactory() {
	
}

ShieldFactory::~ShieldFactory() {

}

shared_ptr<Equipement> ShieldFactory::create(int i) {
	switch(i) {
		case 1:
			return make_shared<LeatherShield>();
			break;
		case 2:
			return make_shared<IronShield>();
			break;
		case 3:
			return make_shared<SteelShield>();
			break;
		case 4:
			return make_shared<MithrilShield>();
			break;
		case 5:
			return make_shared<Egid>();
			break;
	};
}
