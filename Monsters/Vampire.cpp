#include"../Monster.cpp"

class Vampire : public Monster {
	Vampire() {
		desc_ = "Un vampire assoiffé de sang";
		name_ = "Vampire";
		attack_ = 36;
		def_ = 25;
		life_ = 86;
		dext_ = 24;
	}
};
