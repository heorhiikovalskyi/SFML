#include <math.h>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "SFML/System/Vector2.hpp"
//using namespace sf;
sf::RenderWindow window(sf::VideoMode(1500, 1000), "My window");
#include "Figures.h"
#include "Polygon.h"
#include "Circle.h"
#include "Intersections.h"
#include <memory>
#include <algorithm>
#include "SFMLPaint.h"
#include "PaintProccess.h"
int action;
int state = 3;
std::vector <std::shared_ptr<Figure>> figures;
std::vector <sf::Vector2f> nodes;
sf::ConvexShape triangle;
sf::RectangleShape line(sf::Vector2f(150.f, 5.f));
sf::Vector2i position;
sf::Vector2i new_position;
int main()
{
    triangle.setPointCount(5);
    //figures.erase(figures.begin(), std::remove_if(figures.begin(), figures.end(), [](const auto& fig)
      //  { return fig->isEmpty(); }));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                case sf::Keyboard::Num0:
                    action = 0;
                    break; //circle
                case sf::Keyboard::Num1:
                    action = 1;
                    break;//triangle
                case sf::Keyboard::Num2:
                    action = 2;
                    break;//quadr
                case sf::Keyboard::Num3:
                    action = 3;
                    break;//find intersections
                }

            }
            else if (action == 3) {
                int size_ = size(figures);
                sf::Color color(255, 0, 0);
                for (int j = size_ - 1; j >= 1; j--) {
                    for (int i = j - 1; i >= 0; i--) {
                        if (figures[j]->IsIntersect(&*figures[i])) {
                            figures[i]->SetShapeColor(color);
                            figures[j]->SetShapeColor(color);
                        }
                    }

                }
               
                action = -1;
            }

            else if (action == 2 and event.type == sf::Event::MouseButtonPressed)
                QuadraliteralPaint();

            else if (state == 2 and event.type == sf::Event::MouseMoved and action == 1)
                TrianglePaintFourthStep();

            else if (action == 1 and state == 2 and event.type == sf::Event::MouseButtonPressed)
                TrianglePaintFifthStep();

            else if (state == 1 and action == 1 and event.type == sf::Event::MouseMoved and sf::Mouse::isButtonPressed(sf::Mouse::Left))
                TrianglePaintSecondStep();

            else if (state == 3 and action == 1 and event.type == sf::Event::MouseButtonPressed)
                TrianglePaintFirstStep();

            else if (state == 1 and event.type == sf::Event::MouseButtonReleased and action == 1)
                TrianglePaintThirdStep();
             
            else if (action == 0 and event.type == sf::Event::MouseMoved and sf::Mouse::isButtonPressed(sf::Mouse::Left))
                CirclePaintSecondStep();
          
            else if (action == 0  and event.type == sf::Event::MouseButtonPressed)
                CirclePaintFirstStep();

           // else if (action == 0 and event.type == sf::Event::MouseButtonReleased) {
             //   Circle* circle = dynamic_cast<Circle*>((figures[size(figures) - 1]).get());
               // circle->radius = circle->shape->getRadius();
           // }
            
            else if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        PrintAllFigures();
        window.display();
    }
}
  