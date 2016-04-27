#include "Controleur.h"
#include "Vues.h"

void Controleur::init()
{

}

void Controleur::jouer()
{
    sf::Event event;
    sf::Clock clock;

    while (Vues::m_window.isOpen())
    {
        sf::Time deltaTemps(clock.restart());
        Modeles::m_phaseDeltaTempsMs += deltaTemps.asMilliseconds();


        ///TODO intro (cinematique)
        if (Modeles::m_phase == Modeles::PRET)
        {
            pollEvent(event);
        }
        if (Modeles::m_phase == Modeles::ACTION_PJ)
        {
            Modeles::updatePhasePJ();
        }
        if (Modeles::m_phase == Modeles::ACTION_PNJ)
        {
            Modeles::updatePhasePNJ();
        }
        ///TODO FIN (cinematique)

        Vues::update(deltaTemps);
        Vues::draw();

        Modeles::m_nouvellePhase = false;
    }
}

void Controleur::pollEvent(sf::Event& event)
{
    if(Vues::m_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            Vues::m_window.close();
        }
        if(event.type == sf::Event::KeyPressed)
        {
            bool joueurAgit(false);
            bool deplacementVoulu(false);
            Position posJoueur = Modeles::m_joueur.getPosition();
            Position posCibleTmp = posJoueur;//temporairement
            switch(event.key.code)
            {
            case sf::Keyboard::Z:
                deplacementVoulu = true;
                posCibleTmp.setPositionY(posJoueur.getPositionY()-1);
                break;
            case sf::Keyboard::S:
                deplacementVoulu = true;
                posCibleTmp.setPositionY(posJoueur.getPositionY()+1);
                break;
            case sf::Keyboard::Q:
                deplacementVoulu = true;
                posCibleTmp.setPositionX(posJoueur.getPositionX()-1);
                break;
            case sf::Keyboard::D:
                deplacementVoulu = true;
                posCibleTmp.setPositionX(posJoueur.getPositionX()+1);
                break;
            default:
                break;
            }
            if(deplacementVoulu)
            {
                Modeles::m_royaume.retirerMonstresMorts();

                const Case& caseCible = Modeles::m_royaume.get(
                    posCibleTmp.getPositionX(), posCibleTmp.getPositionY());
                bool caseOk = caseCible.navigable() &&
                    caseCible.getPersonnage() == 00;
                if(caseOk)
                {
                    Modeles::m_joueur.setAction(DEPLACER);
                }
                else if(caseCible.getPersonnage() != 00)
                {
                    Modeles::m_joueur.setAction(ATTAQUER);
                }
                Modeles::m_joueur.setCaseCible(&caseCible);
                ////todo direction
                joueurAgit = true;
            }

            if(joueurAgit)
            {
                Modeles::updatePhasePret();
            }
        }
    }
}
