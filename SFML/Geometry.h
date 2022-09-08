#pragma once
#include <SFML/Graphics.hpp>
#include "Polygon.h"
#include "Circle.h"
#include <array>
std::array<float, 3> FindEquation(sf::Vector2f node1, sf::Vector2f node2);
sf::Vector2f GetProjection(std::array<float, 3> line, sf::Vector2f point);
std::array<float, 3> FindPerpendic(std::array<float, 3>, sf::Vector2f point);
sf::Vector2f GetLinesIntersect(std::array<float, 3> line1, std::array<float, 3> line2);

using interval_t = std::pair<float, float>;

interval_t GetInterval(std::vector <sf::Vector2f> points);
bool AreIntervalsIntersect(const interval_t& interval1, const interval_t& interval2);
float Length(sf::Vector2f point1, sf::Vector2f point2);
