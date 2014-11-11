
#include<iostream>
#include"Rectangle.hpp"

using namespace std;

Rectangle::Rectangle() {
    x = y = width = height = 0;
    xCenter = yCenter = 0;
}

Rectangle::Rectangle(int x_, int y_, int width_, int height_) {
    x = x_;
    y = y_;
    width = width_;
    height = height_; 
    xCenter = x + (0.5)*width;
    yCenter = y + (0.5)*height;
}

void Rectangle::displayInfo() {
    cout << "Coordonnées :"<<x<<"*"<<y<<" Dimensions :"<<width<<"*"<<height<<endl;
}

void Rectangle::getInfo() {
	cout << "("<<x<<","<<y<<") de taille "<<width<<"*"<<height<<" ."<<endl;
}

int Rectangle::distFromThis(Rectangle *r) { //Cell Distance
    return (abs(xCenter - (r -> getXCenter())) + abs(yCenter - (r -> getYCenter())));
}

int Rectangle::getX() {
    return x;
}

int Rectangle::getY() {
    return y;
}

int Rectangle::getXCenter() {
    return xCenter;
}

int Rectangle::getYCenter() {
    return yCenter;
}

int Rectangle::getX2() { //up left corner
    return (x+width);
}

int Rectangle::getY2() { //bottom right corner
    return (y+height);
}


int Rectangle::getWidth() {
    return width;
}

int Rectangle::getHeight() {
    return height;
}

