/*************************************************************************
                           SimpleTrip  -  description
                             -------------------
    début                : 2019-11-19
    copyright            : (C) 2019 BERTHOMET Guillaume & FORLER Corentin
    e-mail               : guillaume.berthomet@insa-lyon.fr
                           corentin.forler@insa-lyon.fr
*************************************************************************/

//---- Interface de la classe <SimpleTrip> (fichier SimpleTrip.h) ----------
#if !defined(SIMPLE_TRIP_H)
#define SIMPLE_TRIP_H

//--------------------------------------------------- Interfaces utilisées
#include "Trip.h"
#include <cstring>
#include <iostream>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Rôle de la classe <SimpleTrip>
//  SimpleTrip représente un voyage entre deux villes
//------------------------------------------------------------------------

class SimpleTrip : public Trip
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    virtual const char *GetStart() const;
    virtual const char *GetEnd() const;
    const char *GetMode() const;

    virtual void Display() const;

    virtual Trip *Clone() const;

    // On désactive l'opérateur d'affectation
    SimpleTrip &operator=(const SimpleTrip &) = delete;

    //-------------------------------------------- Constructeurs - destructeur
    SimpleTrip(const SimpleTrip &aSimpleTrip);
    // Mode d'emploi (constructeur de copie) :

    SimpleTrip(const char *inStart, const char *inEnd, const char *inMode);
    // Mode d'emploi : Trip s'occuppera de delete start et end

    virtual ~SimpleTrip();
    // Mode d'emploi : delete start, end et mode

    //------------------------------------------------------------------ PRIVE

protected:
    //------------------------------------------------- Constructeurs protégés

    //----------------------------------------------------- Attributs protégés
    const char *startCity;
    const char *endCity;
    const char *mode;
};

//-------------------------------- Autres définitions dépendantes de <SimpleTrip>

#endif // SIMPLE_TRIP_H
