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
#include "Trip.h"
#include "ArrayList.h"

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
    ArrayList * GetTrips() const;
    // Mode d'emploi :
    //  Renvoie la liste des trips

    //-------------------------------------------- Constructeurs - destructeur
    CompoundTrip(const CompoundTrip &aCompoundTrip);
    // Mode d'emploi (constructeur de copie) :
    //  Copie le trajet "aCompoundTrip" en copiant en profondeur sa liste
    // d'étapes ainsi que sa ville de départ et d'arrivée

    CompoundTrip(ArrayList * trips);
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
    ArrayList * trips;
};

//-------------------------------- Autres définitions dépendantes de <CompoundTrip>

#endif // XXX_H
