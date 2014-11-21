class Guerrier : public Character {
    public:
        Guerrier() {
            Character::desc_ = "Un guerrier habitué du combat. Bonne attaque et défense. ";
            Character::name_ = "Guerrier";
            Character::attack_ = 12;
            Character::def_ = 10;
            Character::life_ = 75;
            Character::maxLife_ = 75;
	        Character::dext_ = 5;
	        
	        Character::weapon = make_shared<Dagger>();
	        Character::armor = make_shared<LeatherArmor>();
        }
};

