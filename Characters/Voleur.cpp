class Voleur : public Character {
    public:
        Voleur() {
            Character::desc_ = "Un brigand au pas souple et rapide. Bonne dextérité. ";
            Character::name_ = "Voleur";
            Character::attack_ = 9;
            Character::def_ = 7;
            Character::life_ = 70;
	        Character::dext_ = 10;
        }
};
