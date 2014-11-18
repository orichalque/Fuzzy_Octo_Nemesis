class MithrilHelm : public Helmet {
    public:
        MithrilHelm() {
            Item::name_ = "Casque en mithril";
		    Item::desc_ = "Un casque en mithril, léger et pourtant très resistant. ";
            Equipement::att = 2;
            Equipement::def = 17;
            Equipement::dext = 5;
                            
        }
};

