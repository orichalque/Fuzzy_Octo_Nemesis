#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

class Rectangle {
    private:
        int x;
        int y;
        int width;
        int height;
       
     
    public:
        Rectangle(void);
        Rectangle(int x_, int y_, int width_, int height_);
        int getX(); //up left                   X/Y___________X2
        int getX2(); //up right                   |           |  
        int getY(); //up left                     |           |
        int getY2(); //bottom left               Y2___________Z
        int getZ();
        void displayInfo();
        int getWidth();
        int getHeight();
        void getInfo();
};

#endif 
