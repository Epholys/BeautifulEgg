#include "Animation.h"
#include "Vues.h"

std::map<Action, std::string> Animation::m_actions = 
{
    {DEPLACER, "marche"},
    {ATTAQUER, "attaque"},
    {ACTIONNER, "actionne"},
    {RIEN, "rien"}
};
std::map<Direction, std::string> Animation::m_directions = 
{
    {HAUT, "haut"},
    {BAS, "bas"},
    {GAUCHE, "gauche"},
    {DROITE, "droite"}
};

Animation::Animation(sf::RenderWindow& window, const Personnage& personnage) :
    Vue(window),
    m_spriteLargeur(100),
    m_spriteHauteur(100),
    m_tempsIntervalle(sf::milliseconds(100)),
    m_totalFrames(3),
    m_animationCourante(personnage.getNom() + "_marche_bas"),
    m_frameCourante(0),
    m_personnage(personnage)
{
    std::string nomFichier = "animations/" + m_animationCourante + ".png";
    std::cout << "Ouverture du fichier d'animation " << nomFichier << std::endl;
    m_texture.loadFromFile(RESSOURCES + nomFichier);
    m_texture.setSmooth(true);

    m_sprite.setTexture(m_texture);
    m_sprite.setTextureRect(sf::IntRect(0, 0, m_spriteLargeur, m_spriteHauteur));
}

Animation::~Animation()
{
    //dtor
}

void Animation::demarrer()
{
    m_clock.restart();
}

void Animation::update(sf::Time deltaTemps)
{
    std::string animationSuivante = "";
    animationSuivante += m_personnage.getNom();
    animationSuivante += "_" + actionToString(m_personnage.getActionCourante());
    animationSuivante += "_" + directionToString(m_personnage.getDirection());
    if(m_animationCourante != animationSuivante)
    {
        m_texture.loadFromFile(RESSOURCES "animations/" + animationSuivante + ".png");
        m_sprite.setTexture(m_texture);
        m_animationCourante = animationSuivante;
    }

    sf::Vector2f vect = Vues::getPersonnageSFPosition(m_personnage);
    vect.x += TAILLE_CASE_X - m_spriteLargeur;
    vect.y += TAILLE_CASE_Y - m_spriteHauteur;
    m_sprite.setPosition(vect);

    sf::Time tempsDepuisDebut = m_clock.getElapsedTime();

    int prochaineFrame = ((int)(tempsDepuisDebut / m_tempsIntervalle)) % m_totalFrames;
    if(m_frameCourante != prochaineFrame)
    {
        m_frameCourante = prochaineFrame;
        m_sprite.setTextureRect(sf::IntRect(m_spriteLargeur * m_frameCourante, 0, m_spriteLargeur, m_spriteHauteur));
    }
}

void Animation::draw() const
{
    m_window.draw(m_sprite);
}

std::string Animation::actionToString(Action act)
{
    return m_actions[act];
}

std::string Animation::directionToString(Direction dir)
{
    return m_directions[dir];
}
