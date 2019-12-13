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
//  Trip représente un voyage entre deux villes.
//  Trip est une classe abstraite.
//------------------------------------------------------------------------

class Trip
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    virtual const char *GetStart() const = 0;
    // Méthode virtuelle pure
    // Mode d'emploi :
    // Accesseur de la propriété startCity.
    // Renvoie un pointeur vers une chaîne de caractères.

    virtual const char *GetEnd() const = 0;
    // Méthode virtuelle pure
    // Mode d'emploi :
    // Accesseur de la propriété endCity.
    // Renvoie un pointeur vers une chaîne de caractères.

    virtual void Display() const = 0;
    // Méthode virtuelle pure
    // Mode d'emploi :
    // Affiche sur la sortie standard une représentation du trajet.

    // On désactive l'opérateur d'affectation
    Trip &operator=(const Trip &) = delete;

    //-------------------------------------------- Constructeurs - destructeur
    // On désactive le constructeur de copie
    Trip(const Trip &aTrip) = delete;

    Trip();
    // Mode d'emploi : constructeur vide

    virtual ~Trip();
    // Mode d'emploi : destructeur vide

    //------------------------------------------------------------------ PRIVE

protected:
    //------------------------------------------------- Constructeurs protégés

    //----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <TRIP>

#endif // TRIP_H
