/*************************************************************************
                           Trip  -  description
                             -------------------
    début                : 2019-11-19
    copyright            : (C) 2019 BERTHOMET Guillaume & FORLER Corentin
    e-mail               : guillaume.berthomet@insa-lyon.fr
                           corentin.forler@insa-lyon.fr
*************************************************************************/

//---- Interface de la classe <Trip> (fichier Trip.h) ----------
#if !defined(TRIP_H)
#define TRIP_H

#include "City.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Rôle de la classe <Trip>
//  Trip est une classe abstraite qui est parente de
//  SimpleTrip et CompoundTrip.
// Elle permet de représenter un voyage entre deux villes.
//------------------------------------------------------------------------

class Trip
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    void Add(void *element);

    //-------------------------------------------- Constructeurs - destructeur
    virtual Trip(const Trip &aTrip);
    // Mode d'emploi (constructeur de copie) :

    virtual Trip();

    virtual ~Trip();

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    const City *startCity;
    const City *endCity;
};

//-------------------------------- Autres définitions dépendantes de <TRIP>

#endif // TRIP_H
