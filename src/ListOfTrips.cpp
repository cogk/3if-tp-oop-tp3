/*************************************************************************
                           ListOfTrips  -  description
                             -------------------
    début                : 2019-11-19
    copyright            : (C) 2019 BERTHOMET Guillaume & FORLER Corentin
    e-mail               : guillaume.berthomet@insa-lyon.fr
                           corentin.forler@insa-lyon.fr
*************************************************************************/

// - Réalisation de la classe <ListOfTrips> (fichier ListOfTrips.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "ListOfTrips.h"
#include "Trip.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void ListOfTrips::Add(Trip *element)
{
    if (currentSize == maxSize)
    {
        DoubleSize();
    }

    list[currentSize++] = element;
} //----- Fin de Add

Trip *ListOfTrips::Remove(unsigned int index)
{
    Trip *removed = list[index];
    for (unsigned int i = index; i < currentSize - 1; i++)
    {
        list[i] = list[i + 1];
    }
    currentSize--;
    return removed;
} //---- Fin de Remove

Trip *ListOfTrips::Pop()
{
    return list[--currentSize];
} //----- Fin de Pop

Trip *ListOfTrips::Get(unsigned int index) const
{
    return list[index];
} //----- Fin de Get

Trip *ListOfTrips::GetLast() const
{
    return list[currentSize - 1];
} //----- Fin de GetLast

bool ListOfTrips::Contains(Trip *elem) const
{
    for (unsigned int i = 0; i < currentSize; i++)
        if (list[i] == elem)
            return true;

    return false;
} //----- Fin de Contains

unsigned int ListOfTrips::Size() const
{
    return currentSize;
} //----- Fin de Size

bool ListOfTrips::IsEmpty() const
{
    return Size() == 0;
} //----- Fin de IsEmpty

//-------------------------------------------- Constructeurs - destructeur

ListOfTrips::ListOfTrips(unsigned int startingMaxSize)
    : currentSize(0), maxSize(startingMaxSize)
{
#ifdef MAP
    cout << "Appel au constructeur de <ListOfTrips>" << endl;
#endif
    if (maxSize == 0)
        maxSize = 1;

    list = new Trip *[maxSize];
} //----- Fin de ListOfTrips

ListOfTrips::~ListOfTrips()
{
#ifdef MAP
    cout << "Appel au destructeur de <ListOfTrips>" << endl;
#endif
    delete[] list;
} //----- Fin de ~ListOfTrips

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

void ListOfTrips::DoubleSize()
{
    maxSize *= 2;
    Trip **oldList = list;
    list = new Trip *[maxSize];
    for (unsigned int i = 0; i < currentSize; i++)
    {
        list[i] = oldList[i];
    }
    delete[] oldList;
}