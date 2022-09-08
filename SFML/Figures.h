#pragma once
class Polygon;
class Circle;
//#include <SFML/Graphics.hpp>

#include "PaintVisitor.h"
//namespace nf
//{
  //  class Shape;
    //class Color;
//}

class Figure {
public:
    Figure() {};
    virtual ~Figure() {};
    virtual void SetShapeColor(sf::Color) = 0;
    virtual sf::Shape* GetShape() = 0;
    virtual bool IsIntersect(Figure*) = 0;
    virtual bool IsIntersectP(Polygon*) = 0;
    virtual bool IsIntersectC(Circle*) = 0;
    virtual bool isEmpty() { return true; };
    virtual void accept(PaintVisitor*) = 0;
    virtual float GetRadius() = 0;
};

