/*************************************************************************
                           ArrayList  -  description
                             -------------------
    début                : 2019-11-19
    copyright            : (C) 2019 BERTHOMET Guillaume & FORLER Corentin
    e-mail               : guillaume.berthomet@insa-lyon.fr
                           corentin.forler@insa-lyon.fr
*************************************************************************/

//---- Réalisation de la classe <ArrayList> (fichier ArrayList.cpp) ------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "ArrayList.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void ArrayList::Add(void *element)
{
    if (currentSize == maxSize)
    {
        DoubleSize();
    }

    list[currentSize++] = element;
} //----- Fin de Add

void *ArrayList::Get(unsigned int index) const
{
    return list[index];
} //----- Fin de Get

unsigned int ArrayList::Size() const
{
    return currentSize;
} //----- Fin de Size

//-------------------------------------------- Constructeurs - destructeur
ArrayList::ArrayList(const ArrayList &anArrayList)
    : currentSize(0), maxSize(anArrayList.maxSize)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <ArrayList>" << endl;
#endif
    list = new void *[maxSize];
    for (unsigned int i = 0; i < anArrayList.Size(); i++)
    {
        Add(anArrayList.Get(i));
    }
} //----- Fin de ArrayList (constructeur de copie)

ArrayList::ArrayList(unsigned int startingMaxSize)
    : currentSize(0), maxSize(startingMaxSize)
{
#ifdef MAP
    cout << "Appel au constructeur de <ArrayList>" << endl;
#endif
    list = new void *[maxSize];
} //----- Fin de ArrayList

ArrayList::~ArrayList()
{
#ifdef MAP
    cout << "Appel au destructeur de <ArrayList>" << endl;
#endif
    delete[] list;
} //----- Fin de ~ArrayList

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void ArrayList::DoubleSize()
{
    maxSize *= 2;
    void **oldList = list;
    list = new void *[maxSize];
    for (unsigned int i = 0; i < currentSize; i++)
    {
        list[i] = oldList[i];
    }
    delete[] oldList;
}
