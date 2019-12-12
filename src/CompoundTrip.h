/*************************************************************************
                           CoumpoundTrip  -  description
                             -------------------
    début                : 2019-11-19
    copyright            : (C) 2019 BERTHOMET Guillaume & FORLER Corentin
    e-mail               : guillaume.berthomet@insa-lyon.fr
                           corentin.forler@insa-lyon.fr
*************************************************************************/

//---- Interface de la classe <CompoundTrip> (fichier CompoundTrip.h) ----
#if !defined(COMPOUND_TRIP_H)
#define COMPOUND_TRIP_H

//--------------------------------------------------- Interfaces utilisées
#include "ListOfTrips.h"
#include "Trip.h"
#include <iostream>

//------------------------------------------------------------------------
// Rôle de la classe <CompoundTrip>
//
//
//------------------------------------------------------------------------

class CompoundTrip : public Trip
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    virtual const char *GetStart() const;
    virtual const char *GetEnd() const;

    ListOfTrips *GetTrips() const;
    // Mode d'emploi :
    //  Renvoie la liste des trips

    virtual void Display() const;

    // On désactive l'opérateur d'affectation
    CompoundTrip &operator=(const CompoundTrip &) = delete;

    //-------------------------------------------- Constructeurs - destructeur
    // On désactive le constructeur de copie
    CompoundTrip(const CompoundTrip &aCompoundTrip) = delete;

    CompoundTrip(ListOfTrips *trips);
    // Mode d'emploi :
    //  Construit un trajet composé de l'ensemble des trajets (dans l'ordre) de
    //  trips. CompoundTrip s'occuppera de delete la liste.
    // Contrat :
    //  trips doit contenir au moins un trip

    virtual ~CompoundTrip();
    // Mode d'emploi :
    //  Libère la liste

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Attributs protégés
    ListOfTrips *subtrips;
};

//-------------------------------- Autres définitions dépendantes de <CompoundTrip>

#endif // CompoundTrip_H
