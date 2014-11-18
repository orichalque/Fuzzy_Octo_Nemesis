#include"../Monster.cpp"

class ArchMagus : public Monster {
	ArchMagus() {
		desc_ = "Un archimage dégageant une aura sinistre";
		name_ = "Archimage";
		attack_ = 52;
		def_ = 23;
		life_ = 99;
		dext_ = 27;
	}
};
