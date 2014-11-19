#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

class Factory {
	private:
	
	public:
		Factory();
		~Factory();
		virtual shared_ptr<Equipement> create(int i) = 0;
	
};

#endif
