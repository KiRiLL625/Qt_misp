#ifndef SHAPE_H
#define SHAPE_H


class Shape
{
public:
    const double PI = 3.14159;
    virtual float perimeter() const = 0;
    virtual float area() const = 0;
};

class Circle: public Shape{
private:
    float radius;
public:
    Circle();
    Circle(float radius);
    float perimeter() const override;
    float area() const override;
};

class Rectangle: public Shape{
private:
    float width;
    float height;
public:
    Rectangle();
    Rectangle(float width, float height);
    float perimeter() const override;
    float area() const override;
};

class Triangle: public Shape{
private:
    float a;
    float b;
    float c;
public:
    Triangle();
    Triangle(float a, float b, float c);
    float perimeter() const override;
    float area() const override;
};

#endif // SHAPE_H
