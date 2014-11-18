
#ifndef EQUIPEMENT_HPP
#define EQUIPEMENT_HPP

class Equipement : public Item {
	private :
		int att;
	    int def;
		int dext;
	
	public:
		virtual bool isEquipement() const = 0;
		int getAtt();
		int getDef();
		int getDext();
		
};

#endif
