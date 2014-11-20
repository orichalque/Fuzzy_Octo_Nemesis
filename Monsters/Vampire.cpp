class Vampire : public Monster {
    public: 
	Vampire() {
		Character::desc_ = "Un vampire assoiffé de sang";
		Character::name_ = "Vampire";
		Character::symbol_ = 'V';
		Character::attack_ = 36;
		Character::def_ = 25;
		Character::life_ = 86;
		Character::dext_ = 24;
		Monster::lootList = {5,17};
	}
};
