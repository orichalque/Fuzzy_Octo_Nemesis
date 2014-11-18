class LeatherHelm : public Helmet {
    public:
        LeatherHelm() {
            Item::name_ = "Casque en cuir";
		    Item::desc_ = "Un casque en cuir, léger mais peu résistant. ";
            Equipement::att = 0;
            Equipement::def = 4;
            Equipement::dext = 1;
                            
        }
};

