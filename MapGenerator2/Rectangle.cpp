
#include"Rectangle.hpp"

using namespace std;

/**
 * \fn Rectangle::Rectangle()
 * \brief Instancie un rectangle vide
 * \param void 
 * \return void
 */
Rectangle::Rectangle() {
    x = y = width = height = 0;
    xCenter = yCenter = 0;

}

/**
 * \fn Rectangle::Rectangle(int x_, int y_, int width_, int height_) 
 * \brief Instancie un rectangle avec les paramètres en entrée
 * \param int x_, int y_, int width_, int height_
 * \return void
 */
Rectangle::Rectangle(int x_, int y_, int width_, int height_) {
    x = x_;
    y = y_;
    width = width_;
    height = height_; 
    xCenter = x + (0.5)*width;
    yCenter = y + (0.5)*height;
}

/**
 * \fn void Rectangle::displayInfo()
 * \brief Affiche les infos sur le rectangle. Pour le debug
 * \param void
 * \return void
 * \deprecated Déprécié
 */
void Rectangle::displayInfo() {
    cout << "Coordonnées :"<<x<<"*"<<y<<" Dimensions :"<<width<<"*"<<height<<endl;
}

/** 
 * \fn void Rectangle::getInfo()
 * \brief Affiche les infos sur le rectangle. Pour le debug
 * \param void 
 * \return void
 * \deprecated Déprécié
 */
void Rectangle::getInfo() {
	cout << "("<<x<<","<<y<<") de taille "<<width<<"*"<<height<<" ."<<endl;
}

/**
 * \fn int Rectangle::distFromThis(Rectangle *r)
 * \brief return the cell distance between 2 rectangles
 * \param Rectangle *r
 * \return int
 */
int Rectangle::distFromThis(Rectangle *r) { 
    return (abs(xCenter - (r -> getXCenter())) + abs(yCenter - (r -> getYCenter())));
}

/**
 * \fn int Rectangle::getX()
 * \brief return the X axis of a rectangle
 * \param void 
 * \return int
 */
int Rectangle::getX() {
    return x;
}

/**
 * \fn int Rectangle::getY()
 * \brief return the Y axis of a rectangle
 * \param void 
 * \return int
 */
int Rectangle::getY() {
    return y;
}

/**
 * \fn int Rectangle::getXCenter()
 * \brief return the X axis of the center of a rectangle
 * \param
 * \return
 */
int Rectangle::getXCenter() {
    return xCenter;
}

/**
 * \fn int Rectangle::getYCenter()
 * \brief return the Y axis of the center of a rectangle
 * \param
 * \return
 */
int Rectangle::getYCenter() {
    return yCenter;
}

/**
 * \fn int Rectangle::getX2()
 * \brief return the X axis of the up left corner
 * \param void 
 * \return int
 */
int Rectangle::getX2() { 
    return (x+width);
}

/**
 * \fn int Rectangle::getY2()
 * \brief Return the Y axis of the bottom right corner
 * \param void
 * \return int
 */
int Rectangle::getY2() { 
    return (y+height);
}

/**
 * \fn int Rectangle::getWidth()
 * \brief return the Width of a rectangle
 * \param void 
 * \return int
 */
int Rectangle::getWidth() {
    return width;
}

/**
 * \fn int Rectangle::getHeight()
 * \brief return the height of a rectangle
 * \param void 
 * \return int
 */
int Rectangle::getHeight() {
    return height;
}


