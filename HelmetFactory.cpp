#include "HelmetFactory.hpp"


HelmetFactory::HelmetFactory() {
	
}

HelmetFactory::~HelmetFactory() {

}

shared_ptr<Equipement> HelmetFactory::create(int i) {
	switch(i) {
		case 1:
			return make_shared<LeatherHelmet>();
			break;
		case 2:
			return make_shared<IronHelmet>();
			break;
		case 3:
			return make_shared<SteelHelmet>();
			break;
		case 4:
			return make_shared<MithrilHelmet>();
			break;
		case 5:
			return make_shared<Kunee>();
			break;

	};
}

int main () {
	HelmetFactory h;
	cout << h.create(1) -> getDescription() << endl;
}	
