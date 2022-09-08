#pragma once
#include "Circle.h"
#include "Polygon.h"
#include "Geometry.h"
#include <iostream>
bool IsIntersectCP(const Circle* circle, const Polygon* polygon);
bool IsIntersectPP(const Polygon* f1, const Polygon* f2);
bool IsIntersectCC(const Circle* f1, const Circle* f2);
bool IsPointInPolygon(const Polygon* polygon, sf::Vector2f point);
  