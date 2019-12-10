/*************************************************************************
                           CompoundTrip  -  description
                             -------------------
    début                : 2019-11-19
    copyright            : (C) 2019 BERTHOMET Guillaume & FORLER Corentin
    e-mail               : guillaume.berthomet@insa-lyon.fr
                           corentin.forler@insa-lyon.fr
*************************************************************************/

// - Réalisation de la classe <CompoundTrip> (fichier CompoundTrip.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "App.h"
#include "CompoundTrip.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
ArrayList *CompoundTrip::GetTrips() const
{
    return trips;
}

void CompoundTrip::Display(std::ostream &out) const
{
    const unsigned int N = trips->Size();
    out << "Trajet Composé: " << startCity << " -> " << endCity;
    out << " (" << N << " sous-trajets)" << EOL;
    for (unsigned int i = 0; i < N; i++)
    {
        Trip *trajet = trips->Get(i);
        out << "     | [" << (i + 1) << "]: ";
        trajet->Display(cout);
    }
}

// Méthode virtuelle qui construit une copie de l'objet
// à l'aide du constructeur de copie
Trip *CompoundTrip::Clone() const
{
    return new CompoundTrip(*this);
}

//-------------------------------------------- Constructeurs - destructeur
CompoundTrip::CompoundTrip(const CompoundTrip &aCompoundTrip)
    : Trip::Trip(aCompoundTrip.trips->Get(0)->GetStart(), aCompoundTrip.trips->GetLast()->GetEnd())
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <CompoundTrip>" << endl;
#endif
    trips = new ArrayList();
    for (unsigned int i = 0; i < aCompoundTrip.trips->Size(); i++)
    {
        trips->Add(aCompoundTrip.trips->Get(i)->Clone());
    }
} //----- Fin de CompoundTrip (constructeur de copie)

CompoundTrip::CompoundTrip(ArrayList *trips)
    : Trip::Trip(trips->Get(0)->GetStart(), trips->GetLast()->GetEnd())
{
#ifdef MAP
    cout << "Appel au constructeur de <CompoundTrip>" << endl;
#endif
    this->trips = trips;
} //----- Fin de CompoundTrip

CompoundTrip::~CompoundTrip()
{
#ifdef MAP
    cout << "Appel au destructeur de <CompoundTrip>" << endl;
#endif
    for (unsigned int i = 0; i < trips->Size(); i++)
    {
        delete trips->Get(i);
    }
    delete trips;
} //----- Fin de ~CompoundTrip

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
