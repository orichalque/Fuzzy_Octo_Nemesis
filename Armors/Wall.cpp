class Wall : public Armor {
    public:
        Wall() {
            Item::name_ = "La Muraille";
		    Item::desc_ = "L\'armure ultime, réputée infranchissable. ";
            Equipement::att = 5;
            Equipement::def = 40;
            Equipement::dext = 5;
                            
        }
};

