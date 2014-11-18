#include"../Monster.cpp"

class Bully : public Monster {
	Bully() {
		desc_ = "Un orc en armure, il est enragé.";
		name_ = "Brute";
		attack_ = 60;
		def_ = 45;
		life_ = 200;
		dext_ = 29;
	}
};
