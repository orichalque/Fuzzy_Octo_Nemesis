#ifndef __SHIELDFACTORY_HPP__
#define __SHIELDFACTORY_HPP__

class ShieldFactory : public Factory {
	private:
	
	public:
		ShieldFactory();
		~ShieldFactory();
		shared_ptr<Equipement> create(int i);
}

#endif
