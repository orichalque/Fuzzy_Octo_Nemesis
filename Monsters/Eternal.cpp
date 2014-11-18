#include"../Monster.cpp"

class Eternal : public Monster {
	Eternal() {
		desc_ = "Un magicien qui déchaine les éléments";
		name_ = "Eternel";
		attack_ = 85;
		def_ = 34;
		life_ = 115;
		dext_ = 32;
	}
};
