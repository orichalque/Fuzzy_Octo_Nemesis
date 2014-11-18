class SteelShield : public Shield {
    public:
        SteelShield() {
            Item::name_ = "Bouclier en acier";
		    Item::desc_ = "Un solide bouclier d'acier. Très lourd. ";
            Equipement::att = 0;
            Equipement::def = 14;
            Equipement::dext = -4;                         
        }
};

