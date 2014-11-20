#ifndef GENERATOR_HPP
#define GENERATOR_HPP


class Generator {
    private:
        int static const SIZE = 32; //we assume using a square map.
        std::vector<Leaf*> leafs; //vector avec toutes les feuilles terminales
        std::vector<Rectangle*> halls;
        Leaf* root;  
        std::vector< std::vector<char> > mat;
                 
    public:
        Generator();
        ~Generator();
        int getSize();
        void split();
        void createRoom();
        void createHalls();
        void buildMap();
        bool findLeaf(Rectangle* l);
        void init();
        shared_ptr<Rectangle> placeCharacter(shared_ptr<Character> c);
        shared_ptr<Monster> placeBoss(int level, shared_ptr<BossFactory> f);
        vector< shared_ptr<Monster> > placeMonsters(int level, shared_ptr<MonsterFactoryConcrete> mfc);
        vector< vector<char> >  getMap();
    
};

#endif

