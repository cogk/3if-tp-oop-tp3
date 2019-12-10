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
#include "ArrayList.h"
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

    ArrayList *GetTrips() const;
    // Mode d'emploi :
    //  Renvoie la liste des trips

    virtual void Display(std::ostream &) const;

    virtual Trip *Clone() const;

    //-------------------------------------------- Constructeurs - destructeur
    CompoundTrip(const CompoundTrip &aCompoundTrip);
    // Mode d'emploi (constructeur de copie) :
    //  Copie le trajet "aCompoundTrip" en copiant en profondeur sa liste
    // d'étapes ainsi que sa ville de départ et d'arrivée

    CompoundTrip(ArrayList *trips);
    // Mode d'emploi :
    //  Construit un trajet composé de l'ensemble des trajets (dans l'ordre) de
    // trips. CompoundTrip s'occuppera de delete la liste.
    // Contrat :
    //  trips doit contenir au moins un trip

    virtual ~CompoundTrip();
    // Mode d'emploi :
    //  Libère la liste

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Attributs protégés
    ArrayList *subtrips;
};

//-------------------------------- Autres définitions dépendantes de <CompoundTrip>

#endif // CompoundTrip_H
