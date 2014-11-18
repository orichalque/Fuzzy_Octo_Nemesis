class IronHelm : public Helmet {
    public:
        IronHelm() {
            Item::name_ = "Casque en fer";
		    Item::desc_ = "Un casque en fer, avec des renforts latéraux en cuir. ";
            Equipement::att = 0;
            Equipement::def = 9;
            Equipement::dext = 0;
                            
        }
};

