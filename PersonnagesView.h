#ifndef PERSONNAGESVIEW_H
#define PERSONNAGESVIEW_H

#include "Vue.h"
#include "Personnage.h"

class PersonnagesView : public Vue
{
    public:
        PersonnagesView(sf::RenderWindow& window);
        virtual ~PersonnagesView();

        void draw() const;
        void drawPersonnage(const Personnage& personnage) const;

    private:
};

#endif // PERSONNAGESVIEW_H
