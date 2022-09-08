#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Figures.h"
#include "SFMLPaint.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "Circle.h"
#include "Polygon.h"
#include <memory>
#include "Geometry.h"
extern sf::RenderWindow window;
extern int action;
extern int state;
extern std::vector <std::shared_ptr<Figure> > figures;
extern std::vector <sf::Vector2f> nodes;
extern sf::ConvexShape triangle;
extern sf::RectangleShape line;
extern sf::Vector2i position;
extern sf::Vector2i new_position;
void PrintAllFigures();
void CirclePaintFirstStep();
void CirclePaintSecondStep();
//void CirclePaintThirdStep();
void TrianglePaintFirstStep();
void TrianglePaintSecondStep();
void TrianglePaintThirdStep();
void TrianglePaintFourthStep();
void TrianglePaintFifthStep();
void QuadraliteralPaint();