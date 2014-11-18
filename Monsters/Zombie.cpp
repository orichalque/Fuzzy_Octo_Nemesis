#include"../Monster.cpp"

class Zombie : public Monster {
	Zombie() {
		desc_ = "Un zombie ... Il danse ?!";
		name_ = "Zombie";
		attack_ = 34;
		def_ = 36;
		life_ = 120;
		dext_ = 23;
	}
};
