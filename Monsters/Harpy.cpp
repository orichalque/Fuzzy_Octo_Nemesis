class Harpy : public Monster {
    public: 
	Harpy() {
		Character::desc_ = "Une femme-oiseau extremement rapide.";
		Character::name_ = "Harpie";
		Character::attack_ = 36;
		Character::def_ = 34;
		Character::life_ = 115;
		Character::dext_ = 32;
	}
};
