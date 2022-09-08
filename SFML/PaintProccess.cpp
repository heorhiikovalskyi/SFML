#include "PaintProccess.h"

using namespace sf;

void PrintAllFigures() {
    for (int i = 0; i < size(figures); i++) {
        SFMLPaintVisitor* visitor = new SFMLPaintVisitor;
        figures[i]->accept(visitor);
        delete visitor;
       // std::cout << " ";
    }
   // std::cout << "\n";
}

void CirclePaintFirstStep() {
    position = Mouse::getPosition(window);
    CircleShape* shape_ = new CircleShape;
    shape_->setRadius(0);
    shape_->setPosition(0, 0);
    shape_->setFillColor(Color(100, 250, 50));
    Circle* circle = new Circle(shape_, position);
    figures.emplace_back(circle);
}

void CirclePaintSecondStep() {
    float radius;
    new_position = Mouse::getPosition(window);
    radius = Length(Vector2f(new_position.x, new_position.y), Vector2f(position.x, position.y));
    CircleShape* circle = dynamic_cast<CircleShape*>(figures[size(figures) - 1]->GetShape());
    circle->setRadius(radius);
    circle->setPosition(-circle->getRadius() + position.x, position.y - circle->getRadius());
}
   // shape.setRadius(radius);
   // shape.setPosition(-shape.getRadius() + position.x, position.y - shape.getRadius());
    //window.clear();
    //PrintAllFigures();
    //window.draw(shape);


/*void CirclePaintThirdStep() {
    CircleShape* shape_ = new CircleShape;
    shape_->setRadius(shape.getRadius());
    shape_->setPosition(shape.getPosition());
    shape_->setFillColor(Color(100, 250, 50));
    Circle* circle = new Circle(shape_, position);
    figures.emplace_back(circle);
}*/

void TrianglePaintFirstStep() {
    position = Mouse::getPosition(window);
    line.setPosition(position.x, position.y);
    state = 1;
}

void TrianglePaintSecondStep() {
    float angle;
    new_position = Mouse::getPosition(window);
    Vector2f vector_(Length(Vector2f(new_position.x, new_position.y), Vector2f(position.x, position.y)), 3.5f);
    line.setSize(vector_);
    if (vector_.x != 0) {
        if (new_position.x == position.x) {
            if (new_position.y > position.y)
                angle = 3 * M_PI / 2;
            else
                angle = M_PI / 2;
        }
        else {
            angle = atan(static_cast<float>(abs(new_position.y - position.y)) / abs(new_position.x - position.x));
            if (new_position.x < position.x and new_position.y <= position.y)
                angle = M_PI - angle;
            else if (new_position.x < position.x and new_position.y > position.y)
                angle = M_PI + angle;
            else if (new_position.x > position.x and new_position.y > position.y)
                angle = 2 * M_PI - angle;
        }
        line.setRotation(360 - angle * 57.295779513);
    }
    window.clear();
    PrintAllFigures();
    window.draw(line);
}

void TrianglePaintThirdStep() {
    triangle.setPointCount(3);
    triangle.setPoint(0, Vector2f(position.x, position.y));
    triangle.setPoint(1, Vector2f(new_position.x, new_position.y));
    state = 2;
}

void TrianglePaintFourthStep() {
    new_position = Mouse::getPosition(window);
    triangle.setPoint(2, Vector2f(new_position.x, new_position.y));
    window.clear();
    PrintAllFigures();
    window.draw(triangle);
}

void TrianglePaintFifthStep() {
    new_position = Mouse::getPosition(window);
    triangle.setPoint(2, Vector2f(new_position.x, new_position.y));
    ConvexShape* shape = new ConvexShape;
    *shape = triangle;
    Polygon* triangle_ = new Polygon(shape);
    figures.emplace_back(triangle_);
    triangle.setPointCount(5);
    state = 3;
}

void QuadraliteralPaint() {
    position = Mouse::getPosition(window);
    nodes.push_back(Vector2f(position.x, position.y));
    if (size(nodes) == 4) {
        ConvexShape* shape = new ConvexShape;
        shape->setPointCount(4);
        for (int i = 0; i < size(nodes); i++) {
            shape->setPoint(i, nodes[i]);
        }
        Polygon* quadrilateral = new Polygon(shape);
        figures.emplace_back(quadrilateral);
        PrintAllFigures();
        for (int i = 0; i < 4; i++)
            nodes.pop_back();
    }
}