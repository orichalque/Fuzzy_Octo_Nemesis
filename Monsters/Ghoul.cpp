class Ghoul : public Monster {
    public: 
	Ghoul() {
		Character::desc_ = "Une goule en décomposition, dégueulasse";
		Character::name_ = "Goule";
		Character::symbol_ = "G";
		Character::attack_ = 27;
		Character::def_ = 34;
		Character::life_ = 100;
		Character::dext_ = 22;
		Monster::lootList = {22};
	}
};
