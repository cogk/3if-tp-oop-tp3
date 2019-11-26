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
//  Trip représente un voyage entre deux villes
//------------------------------------------------------------------------

class Trip
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    const City *GetStart() const;

    const City *GetEnd() const;

    const char *GetMode() const;

    //-------------------------------------------- Constructeurs - destructeur
    Trip(const Trip &aTrip);
    // Mode d'emploi (constructeur de copie) :

    Trip(const City *start, const City *end, const char *mode);
    // Mode d'emploi : Trip s'occuppera de delete start et end

    virtual ~Trip();
    // Mode d'emploi : delete start, end et mode

    //------------------------------------------------------------------ PRIVE

protected:
    //------------------------------------------------- Constructeurs protégés
    Trip(const City *start, const City *end);

    //----------------------------------------------------- Attributs protégés
    const City *startCity;
    const City *endCity;
    const char *mode;
};

//-------------------------------- Autres définitions dépendantes de <TRIP>

#endif // TRIP_H
