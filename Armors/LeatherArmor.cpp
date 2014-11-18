class LeatherArmor : public Armor {
    public:
        LeatherArmor() {
            Item::name_ = "Armure en cuir";
		    Item::desc_ = "Une armure en cuir. Souple mais peu résistante. ";
            Equipement::att = 0;
            Equipement::def = 8;
            Equipement::dext = 2;
                            
        }
};

