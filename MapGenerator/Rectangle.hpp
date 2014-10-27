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
        int getX();
        int getY();
        int getWidth();
        int getHeight();
};

#endif 
