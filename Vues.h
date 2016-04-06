#ifndef VUES_H
#define VUES_H

#include <SFML/Graphics.hpp>

#include "RoyaumeView.h"
#include "IHMView.h"
#include "PersonnagesView.h"

class Vues
{
    public:
        static void init();
        static void update(sf::Time deltaTemps);
        static void draw();

        static sf::Vector2f positionToVect2f(const Position& position);
        static Position vect2fToPosition(const sf::Vector2f& vect);

    public:
        static RoyaumeView m_royaumeView;
        static IHMView m_IHMView;
        static PersonnagesView m_personnagesView;

        static sf::RenderWindow m_window;
};

#endif // VUES_H
