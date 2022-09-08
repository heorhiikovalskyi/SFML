#pragma once
#include <SFML/Graphics.hpp>
#include "Figures.h"
extern sf::RenderWindow window;
bool IsIntersectCP(const Circle* circle, const Polygon* polygon);
bool IsIntersectPP(const Polygon* f1, const Polygon* f2);
bool IsIntersectCC(const Circle* f1, const Circle* f2);
class Circle : public Figure {
public:
    sf::CircleShape* shape;
    sf::Vector2i center;
    float radius;
    sf::Shape* GetShape() override {
        return shape;
    }
    float GetRadius() override {
        return radius;
    }
    void SetShapeColor(sf::Color color) override {
        shape->setFillColor(color);
    }
   
    bool IsIntersect(Figure* figure) override {
        return figure->IsIntersectC(this);
    }

    bool IsIntersectC(Circle* circle) override {
        return IsIntersectCC(this, circle);
    }

    bool IsIntersectP(Polygon* polygon) override {
        return IsIntersectCP(this, polygon);
    }
    Circle(sf::CircleShape* shape, sf::Vector2i center) {
        this->shape = shape;
        this->radius = (*shape).getRadius();
        this->center = center;
    }

    ~Circle() {
        delete shape;
    }
    void accept(PaintVisitor* visitor) override {
        visitor->VisitCircle(shape);
    }
};
