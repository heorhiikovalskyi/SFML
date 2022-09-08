#include "Geometry.h"
using namespace sf;
std::array<float,3> FindEquation(sf::Vector2f node1, sf::Vector2f node2) {
    std::array<float, 3> equation;
    //y = kx + b
    float b = ((node2.x - node1.x) * node1.y - (node2.y - node1.y) * node1.x) / (node2.x - node1.x);
    float k = (node2.y - node1.y) / (node2.x - node1.x);
    k *= -1;
    b *= -1;
    equation[0] = 1;
    equation[1] = k;
    equation[2] = b;
    return equation;
}
sf::Vector2f GetProjection(std::array<float, 3> line, sf::Vector2f point) {
    Vector2f projection;
    projection.y = (line[1] * point.y - line[0] * point.x - line[2] * line[0] / line[1]) / (line[0] * line[0] / line[1] + line[1]);
    projection.x = (-line[2] - line[0] * projection.y) / line[1];
    return projection;
}

std::array<float, 3> FindPerpendic(std::array<float, 3> line, sf::Vector2f point) {
    std::array<float, 3> equation;
    float a = line[0];
    equation[0] = 1;
    equation[1] = -1 / (line[1] / a);
    equation[2] = -point.y - equation[1] * point.x;
    return equation;
}

sf::Vector2f GetLinesIntersect(std::array<float, 3> line1, std::array<float, 3> line2) {
    sf::Vector2f point;
    point.x = (line2[2] - line1[2]) / (line1[1] - line2[1]);
    point.y = -line1[1] * point.x - line1[2];
    return point;
}

interval_t GetInterval(std::vector <sf::Vector2f> points) {
    interval_t interval;
    float max = points[0].y;
    float min = points[0].y;
    for (int i = 1; i < size(points); i++) {
        if (min > points[i].y)
            min = points[i].y;
        if (max < points[i].y)
            max = points[i].y;
    }
    interval.first = min;
    interval.second = max;
    return interval;
}
bool AreIntervalsIntersect(const interval_t& interval1, const interval_t& interval2) {
    const bool intr = (((interval2.first >= interval1.first && interval2.first <= interval1.second)
                    || (interval2.second >= interval1.first && interval2.second <= interval1.second)) 
                    || ((interval1.first >= interval2.first && interval1.first <= interval2.second) 
                    || (interval1.second >= interval2.first && interval1.second <= interval2.second)));

    return intr;
}

float Length(sf::Vector2f point1, sf::Vector2f point2) {
    return pow(pow(point1.x - point2.x, 2) + pow(point1.y - point2.y, 2), 0.5);
}