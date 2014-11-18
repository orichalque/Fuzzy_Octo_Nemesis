class Egid : public Shield {
    public:
        Egid() {
            Item::name_ = "Egide";
		    Item::desc_ = "L'égide, l'assurance d'une protection fiable. ";
            Equipement::att = 0;
            Equipement::def = 24;
            Equipement::dext = -6;                         
        }
};

