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
#include "ArrayList.h"
#include "Trip.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalog>
//   Représente une ville
//------------------------------------------------------------------------

class Catalog
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    unsigned int Size() const;
    void Add(Trip *trip);
    Trip *Get(unsigned int i) const;
    ArrayList<ArrayList<Trip>> *Search(const char *searchedStart, const char *searchedEnd) const;
    ArrayList<ArrayList<Trip>> *SearchV2(const char *searchedStart, const char *searchedEnd) const;
    void Display() const;

    // On désactive l'opérateur d'affectation
    Catalog &operator=(const Catalog &) = delete;

    //-------------------------------------------- Constructeurs - destructeur
    Catalog(const Catalog &aCatalog);
    // Mode d'emploi (constructeur de copie)

    Catalog();
    // Mode d'emploi : Crée un catalogue vide

    virtual ~Catalog();
    // Mode d'emploi : Libère name

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Attributs protégés
    ArrayList<Trip> *trips;
};

#endif // CATALOG_H
