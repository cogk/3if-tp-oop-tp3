/*************************************************************************
                           SearchResults  -  description
                             -------------------
    début                : 2019-11-19
    copyright            : (C) 2019 BERTHOMET Guillaume & FORLER Corentin
    e-mail               : guillaume.berthomet@insa-lyon.fr
                           corentin.forler@insa-lyon.fr
*************************************************************************/

// - Réalisation de la classe <SearchResults> (fichier SearchResults.cpp) --
//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "ListOfTrips.h"
#include "SearchResults.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void SearchResults::Add(ListOfTrips *element)
{
    if (currentSize == maxSize)
    {
        DoubleSize();
    }

    list[currentSize++] = element;
} //----- Fin de Add

ListOfTrips *SearchResults::Get(unsigned int index) const
{
    return list[index];
} //----- Fin de Get

ListOfTrips *SearchResults::GetLast() const
{
    return list[currentSize - 1];
} //----- Fin de GetLast

unsigned int SearchResults::Size() const
{
    return currentSize;
} //----- Fin de Size

//-------------------------------------------- Constructeurs - destructeur

SearchResults::SearchResults(unsigned int startingMaxSize)
    : currentSize(0), maxSize(startingMaxSize)
{
#ifdef MAP
    cout << "Appel au constructeur de <SearchResults>" << endl;
#endif
    if (maxSize == 0)
        maxSize = 1;

    list = new ListOfTrips *[maxSize];
} //----- Fin de SearchResults

SearchResults::~SearchResults()
{
#ifdef MAP
    cout << "Appel au destructeur de <SearchResults>" << endl;
#endif
    delete[] list;
} //----- Fin de ~SearchResults

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

void SearchResults::DoubleSize()
{
    maxSize *= 2;
    ListOfTrips **oldList = list;
    list = new ListOfTrips *[maxSize];
    for (unsigned int i = 0; i < currentSize; i++)
    {
        list[i] = oldList[i];
    }
    delete[] oldList;
}
