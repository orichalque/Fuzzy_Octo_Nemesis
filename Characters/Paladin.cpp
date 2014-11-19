class Paladin : public Character {
    public:
        Paladin() {
            Character::desc_ = "Un soldat en armure. Bonne défense. ";
            Character::name_ = "Guerrier";
            Character::attack_ = 10;
            Character::def_ = 14;
            Character::life_ = 75;
	        Character::dext_ = 5;
        }
};
