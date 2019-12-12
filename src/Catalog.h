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

class Catalog : public ArrayList<Trip>
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    ArrayList<ArrayList<Trip>> *Search(const char *searchedStart, const char *searchedEnd) const;
    ArrayList<ArrayList<Trip>> *SearchV2(const char *searchedStart, const char *searchedEnd) const;

    void Display() const;

    // On désactive l'opérateur d'affectation
    Catalog &operator=(const Catalog &) = delete;

    //-------------------------------------------- Constructeurs - destructeur
    // On désactive le constructeur de copie
    Catalog(const Catalog &aCatalog) = delete;

    Catalog();
    // Mode d'emploi : Crée un catalogue vide

    virtual ~Catalog();
    // Mode d'emploi : Libère name

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Attributs protégés
};

#endif // CATALOG_H
