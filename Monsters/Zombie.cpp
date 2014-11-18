class Zombie : public Monster {
    public: 
	Zombie() {
		Character::desc_ = "Un zombie ... Il danse ?!";
		Character::name_ = "Zombie";
		Character::attack_ = 34;
		Character::def_ = 36;
		Character::life_ = 120;
		Character::dext_ = 23;
	}
};
