
class Gobelin : public Monster {
    public: 
	    Gobelin() {
		    Character::desc_ = "Un gobelin verreux";
		    Character::name_ = "Gobelin";
		    Character::attack_ = 12;
		    Character::def_ = 5;
		    Character::life_ = 35;
		    Character::dext_ = 8;
	    }
};
