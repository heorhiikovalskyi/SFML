#pragma once
class PaintVisitor {
public:
	virtual void VisitCircle(sf::CircleShape*) = 0;
	virtual void VisitPolygon(sf::ConvexShape*) = 0;
};