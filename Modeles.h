#ifndef MODELES_H
#define MODELES_H

#include <vector>

#include "Royaume.h"
#include "Personnage.h"
//#include "Objet.h"



//class Personnage;


class Modeles
{

  public:

        struct Position {int x,y;};


        static Royaume m_royaume;
        static Personnage m_joueur;
        static std::vector<Personnage*> m_monstres;

       // static std::vector<Objet*> m_objets;





};

#endif // MODELES_H
