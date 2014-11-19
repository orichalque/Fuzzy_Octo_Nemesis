class Berserk : public Character {
    public: 
        Berserk() {
            Character::desc_ = "Un violent combattant assoiffé de bataille. Bonne attaque et bonne santé. ";
            Character::name_ = "Berserk";
            Character::attack_ = 17;
            Character::def_ = 6;
            Character::life_ = 125;
	        Character::dext_ = 5;
        }
};
