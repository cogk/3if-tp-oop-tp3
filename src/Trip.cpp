/*************************************************************************
                           Trip  -  description
                             -------------------
    début                : 2019-11-19
    copyright            : (C) 2019 BERTHOMET Guillaume & FORLER Corentin
    e-mail               : guillaume.berthomet@insa-lyon.fr
                           corentin.forler@insa-lyon.fr
*************************************************************************/

//---- Réalisation de la classe <Trip> (fichier Trip.cpp) ------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <cstring>
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "App.h"
#include "Trip.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
const char *Trip::GetStart() const
{
    return this->startCity;
} //----- Fin de GetStart

const char *Trip::GetEnd() const
{
    return this->endCity;
} //----- Fin de GetEnd

//-------------------------------------------- Constructeurs - destructeur
Trip::Trip(const Trip &aTrip)
    : Trip::Trip(aTrip.startCity, aTrip.endCity)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Trip>" << endl;
#endif
} //----- Fin de Trip (constructeur de copie)

Trip::Trip(const char *start, const char *end)
{
#ifdef MAP
    cout << "Appel au constructeur de <Trip>" << endl;
#endif
    if (start != nullptr)
    {
        char *tmpStartCity = new char[strlen(start) + 1];
        strcpy(tmpStartCity, start);
        this->startCity = tmpStartCity;
    }
    else
    {
        this->startCity = nullptr;
    }

    if (end != nullptr)
    {
        char *tmpEndCity = new char[strlen(end) + 1];
        strcpy(tmpEndCity, end);
        this->endCity = tmpEndCity;
    }
    else
    {
        this->endCity = nullptr;
    }
} //----- Fin de Trip

Trip::~Trip()
{
#ifdef MAP
    cout << "Appel au destructeur de <Trip>" << endl;
#endif
    delete[] startCity;
    delete[] endCity;
} //----- Fin de ~Trip

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
