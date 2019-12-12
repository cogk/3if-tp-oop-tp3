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

ListOfTrips *SearchResults::Remove(unsigned int index)
{
    ListOfTrips *removed = list[index];
    for (unsigned int i = index; i < currentSize - 1; i++)
    {
        list[i] = list[i + 1];
    }
    currentSize--;
    return removed;
} //---- Fin de Remove

ListOfTrips *SearchResults::Pop()
{
    return list[--currentSize];
} //----- Fin de Pop

ListOfTrips *SearchResults::Get(unsigned int index) const
{
    return list[index];
} //----- Fin de Get

ListOfTrips *SearchResults::GetLast() const
{
    return list[currentSize - 1];
} //----- Fin de GetLast

bool SearchResults::Contains(ListOfTrips *elem) const
{
    for (unsigned int i = 0; i < currentSize; i++)
        if (list[i] == elem)
            return true;

    return false;
} //----- Fin de Contains

unsigned int SearchResults::Size() const
{
    return currentSize;
} //----- Fin de Size

bool SearchResults::IsEmpty() const
{
    return Size() == 0;
} //----- Fin de IsEmpty

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
