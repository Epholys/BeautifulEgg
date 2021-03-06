#ifndef PERSONNAGESVIEW_H
#define PERSONNAGESVIEW_H

#include "Vue.h"
#include "Personnage.h"
#include "Animation.h"
//class Zone;

class PersonnagesView : public Vue
{
    public:
        PersonnagesView();
        virtual ~PersonnagesView();

        void init(Zone* zone);

        void update(sf::Time deltaTemps);
        void draw() const;
        void drawPersonnage(const Personnage& personnage) const;

    private:
        static Animation* m_joueurAnimation;
        std::vector<Animation*> m_animations;

        ///redondant avec m_animations, mais ordonn� selon coord y
        std::multimap<int, Animation*> m_yOrderAnims;
};

#endif // PERSONNAGESVIEW_H
