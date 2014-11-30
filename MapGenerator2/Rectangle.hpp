/**
 * \file Rectangle.hpp
 * \class Rectangle
 * \brief Class definition for manipulating the rooms and halls of the dungeon
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 */
 
#ifndef __RECTANGLE_HPP__
#define __RECTANGLE_HPP__

class Rectangle {
    private:
        int x; /*!< X axis of the right left top corner */
        int y; /*!< AY axis of the right left top corner */
        int width; /*!< Width of the rectangle */
        int height;/*!< Height of the rectangle */
        int xCenter;/*!< X axis of the center of the rectangle */
        int yCenter;/*!< Y axis of the center of the rectangle */
        bool empty;/*!< Boolean telling if room 's empty or not */
     
    public:
        Rectangle(void);
        Rectangle(int x_, int y_, int width_, int height_);
        int getX(); //up left                   X/Y___________X2
        int getX2(); //up right                   |           |  
        int getY(); //up left                     |           |
        int getY2(); //bottom left               Y2___________Z
        int getZ();
        int getXCenter();
        int getYCenter();
        int distFromThis(Rectangle *r);
        void displayInfo();
        int getWidth();
        int getHeight();
        void getInfo();
};

#endif 

