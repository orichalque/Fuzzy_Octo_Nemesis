class Rapier : public Weapon {
    public:
        Rapier() {
            Item::name_ = "Rapière";
		    Item::desc_ = "Une fine lame horriblement affutée";
            Equipement::att = 33;
            Equipement::def = 7;
            Equipement::dext = 11;
        }
        
};
