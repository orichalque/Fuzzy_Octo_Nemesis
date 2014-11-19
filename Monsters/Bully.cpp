class Bully : public Monster {
    public: 
	Bully() {
		Character::desc_ = "Un orc en armure, il est enragé.";
        Character::name_ = "Brute";
        Character::attack_ = 60;
        Character::def_ = 45;
        Character::life_ = 200;
	    Character::dext_ = 29;
	    Character::symbol_ = "B";
	    Monster::lootList = {9,24};
	}
};


