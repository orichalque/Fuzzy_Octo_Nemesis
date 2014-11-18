class SteelHelm : public Helmet {
    public:
        SteelHelm() {
            Item::name_ = "Casque en acier";
		    Item::desc_ = "Un casque en acier hérissé de pointes métalliques. ";
            Equipement::att = 2;
            Equipement::def = 12;
            Equipement::dext = 1;
                            
        }
};

