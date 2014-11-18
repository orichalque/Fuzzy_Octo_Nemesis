class IronShield : public Shield {
    public:
        IronShield() {
            Item::name_ = "Bouclier en fer";
		    Item::desc_ = "Un classique bouclier en fer. Encombrant. ";
            Equipement::att = 0;
            Equipement::def = 11;
            Equipement::dext = -2;
                            
        }
};

