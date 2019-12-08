/*************************************************************************
                           Catalog  -  description
                             -------------------
    début                : 2019-11-19
    copyright            : (C) 2019 BERTHOMET Guillaume & FORLER Corentin
    e-mail               : guillaume.berthomet@insa-lyon.fr
                           corentin.forler@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Catalog> (fichier Catalog.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <cstring>
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalog.h"
#include "Trip.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
unsigned int Catalog::Size() const
{
    return this->trajets->Size();
}
void Catalog::Add(Trip *trip)
{
    this->trajets->Add(trip);
}
Trip *Catalog::Get(unsigned int i) const
{
    return this->trajets->Get(i);
}

bool StringEquals(const char *a, const char *b)
{
    return !strcmp(a, b);
}

ArrayList *Catalog::Search(const char *searchedStart, const char *searchedEnd) const
{
    ArrayList *result = new ArrayList();

    for (unsigned int i = 0; i < trajets->Size(); i++)
    {
        const char *currStart = trajets->Get(i)->GetStart();
        const char *currEnd = trajets->Get(i)->GetEnd();
        if (StringEquals(currStart, searchedStart) && StringEquals(currEnd, searchedEnd))
        {
            result->Add(trajets->Get(i));
        }
    }

    return result;
}

/*
bool Catalog::SearchNextTrip(ArrayList *currentTrips, const char *searchedEnd,
            const unsigned nbSearched, const unsigned nbMax)
{
    if (nbSearched == nbMax)
        return false;

    char *searchedStart = currentTrips->GetLast()->GetEnd();

    for (unsigned int i = 0; i < trajets->Size(); i++)
    {
        const char * currStart = trajets->Get(i)->GetStart();
        const char * currEnd = trajets->Get(i)->GetEnd();
        if (currStart->Equals(searchStart) &&
            !currentTrips->Contains(trajets->Get(i)))
        {
            currentTrips->Add(trajets->Get(i));
            if (currEnd->Equals(searchedEnd))
            {
                return true;
            }
        }
    }
}

ArrayList *Catalog::SearchV2(const char *start, const char *end, unsigned int nbMaxTrip) const
{
    ArrayList *result = new ArrayList();

    bool end = false;
    while (!end && trajets->Size() != 0)
    {
        ArrayList *currSearch = new ArrayList();
        bool found = false;
        for (unsigned i = 0; i < nbMaxTrip; i++)
        {

        }
    }

    return result;
}
*/

//-------------------------------------------- Constructeurs - destructeur
Catalog::Catalog(const Catalog &aCatalog)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Catalog>" << endl;
#endif
    this->trajets = new ArrayList(0);
    for (unsigned int i = 0; i < aCatalog.trajets->Size(); i++)
    {
        Trip *trajet = aCatalog.trajets->Get(i);
        this->trajets->Add(trajet);
    }
} //----- Fin de Catalog (constructeur de copie)

Catalog::Catalog()
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalog>" << endl;
#endif
    this->trajets = new ArrayList(16);
} //----- Fin de Catalog

Catalog::~Catalog()
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalog>" << endl;
#endif
    for (unsigned int i = 0; i < trajets->Size(); i++)
    {
        Trip *trajet = trajets->Get(i);
        delete trajet;
    }
    delete trajets;
} //----- Fin de ~Catalog
