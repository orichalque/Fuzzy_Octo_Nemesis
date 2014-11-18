#include"../Monster.cpp"

class Ghoul : public Monster {
	Ghoul() {
		desc_ = "Une goule en décomposition, dégueulasse";
		name_ = "Goule";
		attack_ = 27;
		def_ = 34;
		life_ = 100;
		dext_ = 22;
	}
};
