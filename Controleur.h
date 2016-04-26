#ifndef CONTROLEUR_H
#define CONTROLEUR_H

#include <SFML/Window.hpp>

class Controleur
{
    public:
        static void init();
        static void jouer();

    private:
        static void pollEvent(sf::Event& event);
};

#endif // CONTROLEUR_H