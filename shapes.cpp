#include "shapes.h"
#include <cmath>

Circle::Circle(){
    this->radius = 1;
}


Circle::Circle(float radius){
    this->radius = radius;
}

float Circle::perimeter() const{
    return 2 * Circle::PI * radius;
}

float Circle::area() const{
    return Circle::PI * radius * radius;
}

Rectangle::Rectangle(){
    this->width = 1;
    this->height = 1;
}

Rectangle::Rectangle(float width, float height){
    this->width = width;
    this->height = height;
}

float Rectangle::perimeter() const{
    return 2 * (width + height);
}

float Rectangle::area() const{
    return width * height;
}

Triangle::Triangle(){
    this->a = 1;
    this->b = 1;
    this->c = 1;
}

Triangle::Triangle(float a, float b, float c){
    this->a = a;
    this->b = b;
    this->c = c;
}

float Triangle::perimeter() const{
    return a + b + c;
}

float Triangle::area() const{
    float p = Triangle::perimeter() * 0.5;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
