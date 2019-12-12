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
#include "App.h"
#include "Catalog.h"
#include "Trip.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
unsigned int Catalog::Size() const
{
    return trips->Size();
}

void Catalog::Add(Trip *trip)
{
    trips->Add(trip);
}

Trip *Catalog::Get(unsigned int i) const
{
    return trips->Get(i);
}

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

// Fonction "privée" à SearchV2, l'aidant à créer un Trip une fois trouvé
static Trip *createTrip(ArrayList *trips)
{
    if (trips.Size() == 1)
    {
        return trips.Get(0);
    }

    ArrayList *journey = new ArrayList();
    for (unsigned i = 0; i < trips->Size(); i++)
    {
        journey->Add(trips->Get[i]);
    }

    return new CompoundTrip(journey);
}

ArrayList *Catalog::SearchV2(const char *searchedStart, const char *searchedEnd) const
{
    ArrayList *result = new ArrayList();
    ArrayList usedTrip;
    ArrayList tripStack;
    ArrayList currentJourney;

    // Init. de la recherche avec tous les trajets partant de la ville de départ
    for (int i = 0; i < trajets->Size(); i++)
    {
        if (StringEquals(trajets->Get(i)->GetStart(), searchedStart))
        {
            tripStack.Add(trajets->Get(i));
        }
    }

    while (!tripStack.IsEmpty())
    {
        Trip *currentTrip = tripStack.Pop();
        usedTrip.Add(currentTrip);

        // Mise à jour du trajet actuellement testé
        const char *endCurrJourney = currentJourney.GetLast()->GetEnd();
        const char *startCurrTrip = currentTrip->GetStart();
        while (!currentJourney.IsEmpty() &&
               !StringEquals(endCurrJourney, startCurrTrip))
        {
            currentJourney.Pop();
            endCurrJourney = currentJourney.GetLast()->GetEnd();
        }
        currentJourney.Add(currentTrip);

        if (StringEquals(currentTrip->GetEnd(), searchedEnd))
        {
            result.Add(createTrip(&currentJourney));
        }

        for (int i = 0; i < trajets->Size(); i++)
        {
            Trip *next = trajets->Get(i);
            if (!usedTrip.Contains(next) && StringEquals(next->GetStart(), currentTrip->GetEnd()))
            {
                tripStack.Add(next);
            }
        }
    }

    return result;
} //----- Fin de SearchV2

//-------------------------------------------- Constructeurs - destructeur
Catalog::Catalog(const Catalog &aCatalog)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Catalog>" << endl;
#endif
    trips = new ArrayList(0);
    for (unsigned int i = 0; i < aCatalog.trips->Size(); i++)
    {
        Trip *trajet = aCatalog.trips->Get(i);
        trips->Add(trajet);
    }
} //----- Fin de Catalog (constructeur de copie)

Catalog::Catalog()
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalog>" << endl;
#endif
    trips = new ArrayList(16);
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
