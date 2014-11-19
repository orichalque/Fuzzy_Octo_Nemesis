#ifndef __HELMETFACTORY_HPP__
#define __HELMETFACTORY_HPP__

class HelmetFactory : public Factory {
	
	private:
	
	public:
		HelmetFactory();
		~HelmetFactory();
		shared_ptr<Equipement> create(int i);
}

#endif
