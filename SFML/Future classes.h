#pragma once
class Triangle {
public:
    ConvexShape* shape;
    Vector2f nodes[3];
    Shape* GetShape() {
        return shape;
    }
    void SetShapeColor(Color) {
        return;
    }
    void draw() {
        window.draw(*shape);
    }

};


class Quadrilateral {
public:
    ConvexShape* shape;
    Vector2f nodes[4];
    Shape* GetShape() {
        return shape;
    }
    void SetShapeColor(Color) {
        return;
    }
    void draw() {
        window.draw(*shape);
    }


};