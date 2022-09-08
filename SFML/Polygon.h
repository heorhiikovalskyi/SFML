#pragma once
#include <SFML/Graphics.hpp>
#include "Figures.h"
extern sf::RenderWindow window;
bool IsIntersectCP(const Circle* circle, const Polygon* polygon);
bool IsIntersectPP(const Polygon* f1, const Polygon* f2);
bool IsIntersectCC(const Circle* f1, const Circle* f2);
class Polygon : public Figure {
public:
    sf::ConvexShape* shape;
    std::vector <sf::Vector2f> nodes;
    sf::Shape* GetShape() override {
        return shape;
    }
    void SetShapeColor(sf::Color color) override {
        shape->setFillColor(color);
    }
    bool IsIntersect(Figure* figure) override {
        return figure->IsIntersectP(this);
    }

    bool IsIntersectC(Circle* circle) override {
        return IsIntersectCP(circle, this);
    }

    bool IsIntersectP(Polygon* polygon) override {
        return IsIntersectPP(polygon, this);
    }
    float GetRadius() override {
        return 0;
    }

    int TypeOfOrder() const {
        sf::Vector2f point1;
        sf::Vector2f point2;
        int nodes_count = size(nodes);
        int sum = 0;
        for (int i = 0; i < nodes_count; i++) {
            point1 = nodes[i % nodes_count];
            point2 = nodes[(i + 1) % nodes_count];
            sum += (point2.x - point1.x) * (point2.y + point1.y);
        }
        if (sum < 0)//counter clockwise
            return 1;
        else if (sum > 0)// clockwise
            return 2;
    }
    void accept(PaintVisitor* visitor) override{
        visitor->VisitPolygon(shape);
    }

    Polygon(sf::ConvexShape* shape){
        this->shape = shape;
        for (int i = 0; i < (*shape).getPointCount(); i++)
            (this->nodes).push_back((*shape).getPoint(i));
        }

    ~Polygon() {
        delete shape;
    }

};
