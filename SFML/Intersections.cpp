#include "Intersections.h"

using namespace sf;

bool IsIntersectPP(const Polygon* f1, const Polygon* f2) {
    Vector2f point(0,0);
    std::array<float, 3> equation;
    std::array<float, 3> perp;
    int nodes_count_f1 = size(f1->nodes);
    int nodes_count_f2 = size(f2->nodes);
    std::vector <Vector2f> f1_projection;
    std::vector <Vector2f> f2_projection;
    for (int i = 0; i < nodes_count_f1; i++) {
        equation = FindEquation(f1->nodes[i % nodes_count_f1], f1->nodes[(i + 1) % nodes_count_f1]);
        perp = FindPerpendic(equation, point);

        for (int j = 0; j < nodes_count_f1; j++) 
            f1_projection.push_back(GetProjection(perp, f1->nodes[j]));

        for (int j = 0; j < nodes_count_f2; j++) 
            f2_projection.push_back(GetProjection(perp, f2->nodes[j]));

        if (!AreIntervalsIntersect(GetInterval(f1_projection), GetInterval(f2_projection)))
            return false;

        for (int j = 0; j < nodes_count_f1; j++)
            f1_projection.pop_back();
        for (int j = 0; j < nodes_count_f2; j++)
            f2_projection.pop_back();
    }
    for (int i = 0; i < nodes_count_f2; i++) {
        equation = FindEquation(f2->nodes[i % nodes_count_f2], f2->nodes[(i + 1) % nodes_count_f2]);
        perp = FindPerpendic(equation, point);

        for (int j = 0; j < nodes_count_f1; j++)
            f1_projection.push_back(GetProjection(perp, f1->nodes[j]));

        for (int j = 0; j < nodes_count_f2; j++)
            f2_projection.push_back(GetProjection(perp, f2->nodes[j]));

        if (!AreIntervalsIntersect(GetInterval(f1_projection), GetInterval(f2_projection)))
            return false;

        for (int j = 0; j < nodes_count_f1; j++)
            f1_projection.pop_back();
        for (int j = 0; j < nodes_count_f2; j++)
            f2_projection.pop_back();
    }
    return true;
}

bool IsIntersectCP(const Circle* circle, const Polygon* polygon) {
    Vector2f center;
    Vector2f point1;
    Vector2f point2;
    Vector2f projection;
    Vector2f min;
    center.x = circle->center.x;
    center.y = circle->center.y;
    int nodes_count = size(polygon->nodes);
    for (int i = 0; i < nodes_count; i++) {
        if (Length(center, polygon->nodes[i]) <= circle->radius)
            return true;
        point1 = polygon->nodes[i % nodes_count];
        point2 = polygon->nodes[(i + 1) % nodes_count];
        projection = GetProjection(FindEquation(point1, point2), center);
        if (point1.x > point2.x) {
            min = point2;
            point2 = point1;
            point1 = min;
        }
        if (Length(projection, center) <= circle->radius and projection.x >= point1.x and projection.x <= point2.x)
            return true;
    }
    return IsPointInPolygon(polygon, center);
}

bool IsIntersectCC(const Circle* f1, const Circle* f2) {
    float distance = Length(Vector2f((f1->center).x, (f1->center).y),Vector2f((f2->center).x,(f2->center).y));
    if (distance <= f1->radius + f2->radius)
        return true;
    return false;
}

bool IsPointInPolygon(const Polygon* polygon,sf:: Vector2f point) {
    Vector2f point1;
    Vector2f point2;
    int type = polygon->TypeOfOrder();
    int nodes_count = size(polygon->nodes);
    for (int i = 0; i < nodes_count; i++) {
        point1 = polygon->nodes[i % nodes_count];
        point2 = polygon->nodes[(i + 1) % nodes_count];
        if (type == 1) {
            if ((point.x - point1.x) * (point2.y - point1.y) - (point.y - point1.y) * (point2.x - point1.x) >= 0)
                return false;
        }
        else {
            if ((point.x - point1.x) * (point2.y - point1.y) - (point.y - point1.y) * (point2.x - point1.x) <= 0)
                return false;
        }
    }
    return true;
}