#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED

#include <string>
#include "Case.h"
#include "Position.h"
#include "Modeles.h"

class Modeles;


enum Direction
{
    HAUT,
    BAS,
    GAUCHE,
    DROITE,
    NOMBRE_DIRECTIONS
};

enum Action
{
    DEPLACER,
    ATTAQUER,
    ACTIONNER,
    RIEN,
    NOMBRE_ACTIONS
};


class Personnage
{
    public:
        Personnage(std::string nom="joueur", int x=0, int y=0);
        ~Personnage();

        void afficher();
        void setAction(Action action);
        void executerAction();
        void deplacer();
        std::string getNom() const;
        void setCaseCible(const Case *caseCible);
        const Case* getCaseCible() const {return m_caseCible;};
        void setPosition(int x, int y);
        Position getPosition() const;
        bool isCaseCible(const Case* autre) const;
        int getSante() const;
        int getSanteMax() const;
        bool getVivant() const;
        bool getMourant() const;
        Action getActionCourante() const {return m_actionCourante;};
        Direction getDirection() const {return m_directionActuelle;};

    protected:
        void perdreSante(int degats);
        void attaquer(Personnage &autre);
        void interagir();
        Direction getDirectionFromCase(const Case *caseCible) const;

        std::string m_nom;
        int m_sante;
        int m_santeMax;
        int m_degats;
        Position m_position;
        Direction m_directionActuelle;
        const Case *m_caseCible;
        bool m_vivant;///pas utilis�??
        bool m_mourant;///anim� en phase ACTION_PNJ
        Action m_actionCourante;

};

#endif // PERSONNAGE_H_INCLUDED
