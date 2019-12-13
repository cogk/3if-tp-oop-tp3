/*************************************************************************
                           Catalog  -  description
                             -------------------
    début                : 2019-11-19
    copyright            : (C) 2019 BERTHOMET Guillaume & FORLER Corentin
    e-mail               : guillaume.berthomet@insa-lyon.fr
                           corentin.forler@insa-lyon.fr
*************************************************************************/

//--------- Interface de la classe <Catalog> (fichier Catalog.h) ---------------
#if !defined(CATALOG_H)
#define CATALOG_H

//--------------------------------------------------- Interfaces utilisées
#include "ListOfTrips.h"
#include "SearchResults.h"
#include "Trip.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalog>
// Représente une liste de trajets qui peut être affichée sur la sortie
// standard, et qui permet de rechercher des trajets.
//------------------------------------------------------------------------

class Catalog : public ListOfTrips
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    SearchResults *Search(const char *searchedStart, const char *searchedEnd) const;
    // Mode d'emploi :
    //

    SearchResults *SearchV2(const char *searchedStart, const char *searchedEnd) const;
    // Mode d'emploi :
    //

    void Display() const;
    // Mode d'emploi :
    // Affiche sur la sortie standard une représentation des trajets contenus
    // dans le catalogue.

    // On désactive l'opérateur d'affectation
    Catalog &operator=(const Catalog &) = delete;

    //-------------------------------------------- Constructeurs - destructeur
    // On désactive le constructeur de copie
    Catalog(const Catalog &aCatalog) = delete;

    Catalog();
    // Mode d'emploi : Crée un catalogue vide

    virtual ~Catalog();
    // Mode d'emploi : Libère les trajets contenus dans le catalogue

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Attributs protégés
};

#endif // CATALOG_H
