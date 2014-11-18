#include"../Monster.cpp"

class Harpy : public Monster {
	Harpy() {
		desc_ = "Une femme-oiseau extremement rapide.";
		name_ = "Harpie";
		attack_ = 36;
		def_ = 34;
		life_ = 115;
		dext_ = 32;
	}
};
