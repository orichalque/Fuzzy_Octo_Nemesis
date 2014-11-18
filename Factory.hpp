#ifndef FACTORY_HPP
#define FACTORY_HPP

class Factory {
    private:
    
    public:
        Factory();
        ~Factory();
        virtual Character create(int i) = 0;
}

#endif
