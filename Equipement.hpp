
#ifndef EQUIPEMENT_HPP
#define EQUIPEMENT_HPP

class Equipement : public Item {
	protected :
		int att;
	    int def;
		int dext;
	
	public:
	    Equipement();
	    ~Equipement();
		virtual bool isEquipement() = 0;
		int getAtt();
		int getDef();
		int getDext();
		
};

#endif
