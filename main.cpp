
//#include <SFML/Graphics.hpp>
//#include "Personnage.h"
//#include "Case.h"

#include "Modeles.h"
#include "Vues.h"


int main()
{
    /*


int a(10);


    Personnage *perso1=new Personnage("p1");
    Personnage *perso2=new Personnage("p2");
    Case case1, case2(3,5);


    while (window.isOpen())
    {


        sf::Event event;
        while (window.pollEvent(event))
        {

              if (event.type == sf::Event::Closed)
                window.close();


        }


            std::cout<<std::endl;
            std::cout<<"appuyer sur un chiffre pour continuer"<<std::endl;
            std::cin>>a;
            std::cout<<std::endl;


            perso1->setCaseCible(&case1);
            case1.setPersonnage(perso2);

            perso1->setAction(ATTAQUER);
            perso1->executerAction();



            perso1->afficher();
            perso1->setCaseCible(&case2);
            perso1->setAction(DEPLACER);
            perso1->executerAction();
            perso1->afficher();



          std::cout<<"============================================="<<std::endl;


        window.clear();
        window.draw(shape);
        window.display();


    }


    }*/
    for(int i=0; i<2000; i++)
        Vues::draw();


    return 0;
}
