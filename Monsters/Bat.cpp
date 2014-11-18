#include"../Monster.cpp"

class Bat : public Monster {
	Bat() {
		desc_ = "Une chauve-souris sanguinaire !";
		name_ = "Chauve-Souris";
		attack_ = 8;
		def_ = 4;
		life_ = 23;
		dext_ = 19;
	}
//string _name, string _desc, int life_, int attack_, int def_, int dext_
};
