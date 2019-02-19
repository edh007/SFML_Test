/******************************************************************************/
/*!
\file   main.cpp
\author Dongho Lee
\par    email: jeykop14\@gmail.com
\date   2019/02/19(yy/mm/dd)

\description
    main

*/
/******************************************************************************/
#include "BaseEngine.h"

int main(int argc, char** argv)
{
    DHL::BaseEngine(800, 600, "SFML");
}

//int main()
//{
//    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
//    sf::CircleShape shape(100.f);
//    shape.setFillColor(sf::Color::Green);
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        window.clear();
//        window.draw(shape);
//        window.display();
//    }
//
//    return 0;
//}