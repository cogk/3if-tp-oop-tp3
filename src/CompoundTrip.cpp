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
#include "CompoundTrip.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
ArrayList * CompoundTrip::GetTrips() const
{
    return trips;
}

//-------------------------------------------- Constructeurs - destructeur
CompoundTrip::CompoundTrip(const CompoundTrip &aCompoundTrip)
    : Trip::Trip(nullptr, nullptr, nullptr)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <CompoundTrip>" << endl;
#endif
    trips = new ArrayList();
    for (unsigned int i = 0; i < aCompoundTrip.trips->Size(); i++)
    {
        trips->Add(new Trip(*( aCompoundTrip.trips->Get(i) )));
    }
    startCity = trips->Get(0)->GetStart();
    endCity = trips->GetLast()->GetEnd();
    mode = nullptr;
} //----- Fin de CompoundTrip (constructeur de copie)

CompoundTrip::CompoundTrip(ArrayList * trips)
    : Trip::Trip(trips->Get(0)->GetStart(), trips->GetLast()->GetEnd(), nullptr)
{
#ifdef MAP
    cout << "Appel au constructeur de <CompoundTrip>" << endl;
#endif
    this->trips = trips;
    mode = nullptr;
} //----- Fin de CompoundTrip

CompoundTrip::~CompoundTrip()
{
#ifdef MAP
    cout << "Appel au destructeur de <CompoundTrip>" << endl;
#endif
    delete trips;
} //----- Fin de ~CompoundTrip

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
