/*************************************************************************
                           SearchResults  -  description
                             -------------------
    début                : 2019-11-19
    copyright            : (C) 2019 BERTHOMET Guillaume & FORLER Corentin
    e-mail               : guillaume.berthomet@insa-lyon.fr
                           corentin.forler@insa-lyon.fr
*************************************************************************/

//---- Interface de la classe <SearchResults> (fichier SearchResults.h) ----------
#if !defined(SEARCH_RESULTS_H)
#define SEARCH_RESULTS_H

//--------------------------------------------------- Interfaces utilisées
#include "ListOfTrips.h"
#include <iostream>
using namespace std;

//------------------------------------------------------------- Constantes
const unsigned int SEARCH_RESULTSDEFAULT_SIZE = 4;

//------------------------------------------------------------------------
// Rôle de la classe <SearchResults>
//  SearchResults permet de stocker et manipuler une liste de taille variable
// de ListOfTrips
//  Via les méthodes Pop et Add, il est aussi possible de l'utiliser comme
// une pile
//------------------------------------------------------------------------

class SearchResults
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    void Add(ListOfTrips *elem);
    // Mode d'emploi : Ajoute un élément à la fin de la liste

    ListOfTrips *Get(unsigned int index) const;
    // Contrat : index < Size()

    ListOfTrips *GetLast() const;
    // Contrat : Size() > 0

    unsigned int Size() const;
    // Mode d'emploi : Retourne la taille actuelle de la liste

    // On désactive l'opérateur d'affectation
    SearchResults &operator=(const SearchResults &) = delete;

    //-------------------------------------------- Constructeurs - destructeur
    // On désactive le constructeur de copie
    SearchResults(const SearchResults &anSearchResults) = delete;

    SearchResults(unsigned int startingMaxSize = SEARCH_RESULTSDEFAULT_SIZE);
    // Mode d'emploi : maxSize indique la taille que la liste allouera pour
    //   stocker ses éléments (qui pourra varier si besoin)
    // Contrat : startingMaxSize >= 1

    virtual ~SearchResults();

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées
    void DoubleSize();
    // Mode d'emploi : double la taille actuellement allouée à la list

    //----------------------------------------------------- Attributs protégés
    unsigned int currentSize;
    unsigned int maxSize;

    ListOfTrips **list;
};

#endif // SEARCH_RESULTS_H
