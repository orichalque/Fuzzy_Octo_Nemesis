class LongSword : public Weapon {
    public:
        LongSword() {
            Item::name_ = "Epee longue";
		    Item::desc_ = "Une épée longue tranchante comme un rasoir. ";
            Equipement::att = 24;
            Equipement::def = 6;
            Equipement::dext = 6;
        }
        
};
