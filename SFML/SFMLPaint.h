#pragma once
#include <SFML/Graphics.hpp>
#include "PaintVisitor.h"
extern sf::RenderWindow window;
class SFMLPaintVisitor: public PaintVisitor{
public:
	void VisitCircle(sf::CircleShape* circle) override {
		std::cout << circle->getRadius();
		window.draw(*circle);
	}
	void VisitPolygon(sf::ConvexShape* polygon) override {
		window.draw(*polygon);
	}
};