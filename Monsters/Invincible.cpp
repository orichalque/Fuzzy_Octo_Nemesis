class Invincible : public Monster {
    public: 
	Invincible() {
		desc_ = "THE big boss";
		name_ = "L\'invincible";
		attack_ = 100;
		def_ = 100;
		life_ = 1000;
		dext_ = 50;
		Character::symbol_ = "I";
		Monster::lootList = {9, 14, 19, 24};
	}
};
