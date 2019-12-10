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

//--------------------------------------------------- Interfaces utilisées
#include <iostream>

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
    virtual const char *GetStart() const = 0;

    virtual const char *GetEnd() const = 0;

    virtual void Display() const = 0;

    virtual Trip *Clone() const = 0;

    //-------------------------------------------- Constructeurs - destructeur
    Trip(const Trip &aTrip);
    // Mode d'emploi (constructeur de copie) :

    Trip();
    // Mode d'emploi : Trip s'occuppera de delete start et end

    virtual ~Trip();
    // Mode d'emploi : delete start, end et mode

    //------------------------------------------------------------------ PRIVE

protected:
    //------------------------------------------------- Constructeurs protégés

    //----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <TRIP>

#endif // TRIP_H
