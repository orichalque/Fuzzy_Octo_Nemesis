#include"../Monster.cpp"

class Invincible : public Monster {
	Invincible() {
		desc_ = "THE big boss";
		name_ = "L\'invincible";
		attack_ = 100;
		def_ = 100;
		life_ = 1000;
		dext_ = 50;
	}
};
