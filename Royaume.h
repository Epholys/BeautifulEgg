#ifndef ROYAUME_H
#define ROYAUME_H

#include <vector>
#include "Zone.h"

class Royaume
{
    public:
        Royaume();
        virtual ~Royaume();

        void ajouterZone(Zone* zone);
        void chargerFichier();

        Case& get(int i, int j);
        const Case& get(int i, int j) const;
        int getLargeur() const;
        int getHauteur() const;

    private:
        std::vector<Zone*> m_zones;
        int m_zoneCourante;
};

#endif // ROYAUME_H
