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
#include "ListOfTrips.h"
#include "SearchResults.h"
#include "Trip.h"
#include "UI.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Catalog::Display() const
{
    const unsigned int nTrajets = Size();

    if (nTrajets == 0)
    {
        cout << "Pas de trajets dans le catalogue." << EOL << EOL;
    }
    else
    {
        cout << "Il y a " << nTrajets << " trajet" << (nTrajets > 1 ? "s" : "") << " dans le catalogue." << EOL << EOL;

        for (unsigned int i = 0; i < nTrajets; i++)
        {
            Trip *trajet = Get(i);
            cout << "[" << (i + 1) << "]: ";
            trajet->Display();
        }
        cout << EOL;
    }
}

bool StringEquals(const char *a, const char *b)
{
    return !strcmp(a, b);
}

SearchResults *Catalog::Search(const char *searchedStart, const char *searchedEnd) const
{
    SearchResults *results = new SearchResults();

    for (unsigned int i = 0; i < Size(); i++)
    {
        const char *currStart = Get(i)->GetStart();
        const char *currEnd = Get(i)->GetEnd();
        if (StringEquals(currStart, searchedStart) && StringEquals(currEnd, searchedEnd))
        {
            ListOfTrips *toAdd = new ListOfTrips(1);
            toAdd->Add(Get(i));
            results->Add(toAdd);
        }
    }

    return results;
}

// Fonction "privée" à SearchV2, l'aidant à créer un Trip une fois trouvé
static ListOfTrips *cloneList(ListOfTrips &trips)
{
    ListOfTrips *cloned = new ListOfTrips();
    for (unsigned int i = 0; i < trips.Size(); i++)
    {
        cloned->Add(trips.Get(i));
    }

    return cloned;
}

SearchResults *Catalog::SearchV2(const char *searchedStart, const char *searchedEnd) const
{
    SearchResults *results = new SearchResults();
    ListOfTrips usedTrip;
    ListOfTrips tripStack;
    ListOfTrips currentJourney;

    // Init. de la recherche avec tous les trajets partant de la ville de départ
    for (unsigned int i = 0; i < Size(); i++)
    {
        if (StringEquals(Get(i)->GetStart(), searchedStart))
        {
            tripStack.Add(Get(i));
        }
    }

    while (!tripStack.IsEmpty())
    {
        Trip *currentTrip = tripStack.Pop();
        usedTrip.Add(currentTrip);

        // Mise à jour du trajet actuellement testé
        if (!currentJourney.IsEmpty())
        {
            const char *endCurrJourney = currentJourney.GetLast()->GetEnd();
            const char *startCurrTrip = currentTrip->GetStart();
            while (!StringEquals(endCurrJourney, startCurrTrip))
            {
                currentJourney.Pop();
                if (currentJourney.IsEmpty())
                    break;
                endCurrJourney = currentJourney.GetLast()->GetEnd();
            }
        }
        currentJourney.Add(currentTrip);

        if (StringEquals(currentTrip->GetEnd(), searchedEnd))
        {
            results->Add(cloneList(currentJourney));
        }

        for (unsigned int i = 0; i < Size(); i++)
        {
            Trip *next = Get(i);
            if (!usedTrip.Contains(next) && StringEquals(next->GetStart(), currentTrip->GetEnd()))
            {
                tripStack.Add(next);
            }
        }
    }

    return results;
} //----- Fin de SearchV2

//-------------------------------------------- Constructeurs - destructeur
Catalog::Catalog()
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalog>" << endl;
#endif
} //----- Fin de Catalog

Catalog::~Catalog()
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalog>" << endl;
#endif
    for (unsigned int i = 0; i < Size(); i++)
    {
        Trip *trip = Get(i);
        delete trip;
    }
} //----- Fin de ~Catalog
