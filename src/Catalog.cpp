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
    return this->trips->Size();
}
void Catalog::Add(Trip *trip)
{
    this->trips->Add(trip);
}
Trip *Catalog::Get(unsigned int i) const
{
    return this->trips->Get(i);
}

bool StringEquals(const char *a, const char *b)
{
    return !strcmp(a, b);
}

ArrayList *Catalog::Search(const char *searchedStart, const char *searchedEnd) const
{
    ArrayList *result = new ArrayList();

    for (unsigned int i = 0; i < trips->Size(); i++)
    {
        const char *currStart = trips->Get(i)->GetStart();
        const char *currEnd = trips->Get(i)->GetEnd();
        if (StringEquals(currStart, searchedStart) && StringEquals(currEnd, searchedEnd))
        {
            result->Add(trips->Get(i));
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

    for (unsigned int i = 0; i < trips->Size(); i++)
    {
        const char * currStart = trips->Get(i)->GetStart();
        const char * currEnd = trips->Get(i)->GetEnd();
        if (currStart->Equals(searchStart) &&
            !currentTrips->Contains(trips->Get(i)))
        {
            currentTrips->Add(trips->Get(i));
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
    while (!end && trips->Size() != 0)
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
    this->trips = new ArrayList(0);
    for (unsigned int i = 0; i < aCatalog.trips->Size(); i++)
    {
        Trip *trajet = aCatalog.trips->Get(i);
        this->trips->Add(trajet);
    }
} //----- Fin de Catalog (constructeur de copie)

Catalog::Catalog()
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalog>" << endl;
#endif
    this->trips = new ArrayList(16);
} //----- Fin de Catalog

Catalog::~Catalog()
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalog>" << endl;
#endif
    for (unsigned int i = 0; i < trips->Size(); i++)
    {
        Trip *trajet = trips->Get(i);
        delete trajet;
    }
    delete trips;
} //----- Fin de ~Catalog
