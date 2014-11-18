class LeatherShield : public Shield {
    public:
        LeatherShield() {
            Item::name_ = "Bouclier en cuir";
		    Item::desc_ = "Un bouclier en bois, recouvert de cuir. ";
            Equipement::att = 0;
            Equipement::def = 8;
            Equipement::dext = -1;
                            
        }
};

