/*************************************************************************
                           City  -  description
                             -------------------
    début                : 2019-11-19
    copyright            : (C) 2019 BERTHOMET Guillaume & FORLER Corentin
    e-mail               : guillaume.berthomet@insa-lyon.fr
                           corentin.forler@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <City> (fichier City.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <cstring>
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "City.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
const char *City::GetName() const
{
    return name;
}

bool City::Equals(City *aCity) const
{
    return strcmp(this->name, aCity->name) == 0;
}

//-------------------------------------------- Constructeurs - destructeur
City::City(const City &aCity)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <City>" << endl;
#endif
    char *tmpName = new char[strlen(aCity.name) + 1];
    strcpy(tmpName, aCity.name);
    name = tmpName;
} //----- Fin de City (constructeur de copie)

City::City(const char *cityName)
{
#ifdef MAP
    cout << "Appel au constructeur de <City>" << endl;
#endif
    char *tmpName = new char[strlen(cityName) + 1];
    strcpy(tmpName, cityName);
    name = tmpName;
} //----- Fin de City

City::~City()
{
#ifdef MAP
    cout << "Appel au destructeur de <City>" << endl;
#endif
    delete[] name;
} //----- Fin de ~City
