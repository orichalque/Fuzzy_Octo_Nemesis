#include"../Monster.cpp"

class Ghoul : public Monster {
	Ghoul() {
		desc_ = "Un Golem de pierre d'au moins cinq mètres de haut !";
		name_ = "Golem";
		attack_ = 37;
		def_ = 40;
		life_ = 150;
		dext_ = 19;
	}
};
