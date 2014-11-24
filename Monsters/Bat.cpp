class Bat : public Monster {
    public: 
	Bat() {
		Character::name_ = "Chauve-Souris";
        Character::attack_ = 8;
        Character::def_ = 4;
        Character::life_ = 23;
        Character::dext_ = 11;
        Character::desc_ = "Une chauve-souris sanguinaire !";
        Character::symbol_ = 'B';
        Monster::lootList = {2, 15};
	}
};
