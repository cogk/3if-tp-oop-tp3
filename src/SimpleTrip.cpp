/*************************************************************************
                           SimpleTrip  -  description
                             -------------------
    début                : 2019-11-19
    copyright            : (C) 2019 BERTHOMET Guillaume & FORLER Corentin
    e-mail               : guillaume.berthomet@insa-lyon.fr
                           corentin.forler@insa-lyon.fr
*************************************************************************/

// - Réalisation de la classe <SimpleTrip> (fichier SimpleTrip.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <cstring>
#include <iostream>

//------------------------------------------------------ Include personnel
#include "App.h"
#include "SimpleTrip.h"
#include "Trip.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
const char *SimpleTrip::GetStart() const
{
    return startCity;
} //----- Fin de GetStart

const char *SimpleTrip::GetEnd() const
{
    return endCity;
} //----- Fin de GetEnd

const char *SimpleTrip::GetMode() const
{
    return mode;
} //----- Fin de GetMode

void SimpleTrip::Display() const
{
    cout << "Trajet Simple: " << startCity << " -> " << endCity << " (" << mode << ")" << EOL;
}

// Méthode virtuelle qui construit une copie de l'objet
// à l'aide du constructeur de copie
Trip *SimpleTrip::Clone() const
{
    return new SimpleTrip(*this);
}

//-------------------------------------------- Constructeurs - destructeur
SimpleTrip::SimpleTrip(const SimpleTrip &aSimpleTrip)
    : SimpleTrip(aSimpleTrip.startCity, aSimpleTrip.endCity, aSimpleTrip.mode)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <SimpleTrip>" << endl;
#endif
} //----- Fin de SimpleTrip (constructeur de copie)

SimpleTrip::SimpleTrip(const char *inStart, const char *inEnd, const char *inMode)
{
#ifdef MAP
    cout << "Appel au constructeur de <SimpleTrip>" << endl;
#endif
    /*
     POURQUOI COPIER LES CHAINES DE CARACTÈRES PASSÉES EN PARAMÈTRE ?

     La raison est que l'espace mémoire consommé par les chaînes
       données en paramètre est égal à la taille du buffer UI_BUFFER_SIZE.
     On peut rapidement arriver à de fortes consommations
       de mémoire de manière inutile.

     Nous avons donc fait le choix de systématiquement copier les chaines
       données en paramètre dans un espace mémoire de taille adapté.

     Cependant, ce choix a un coût :
       - le constructeur est plus lent ;
       - le constructeur est plus complexe (ce qui augmente le risque de bug) ;
       - l'espace mémoire risque d'être fragmenté plus facilement.

     Nous considérons cependant que ce choix est une bonne manière
       de satisfaire un certain nombre de contraintes rigoureuses que
       nous nous sommes fixées (notamment le fait que les paramètres
       en entrée doivent être tous `const`).

     Enfin, ce choix est en adéquation avec le Guide de Style imposé,
       notamment la règle C-3 : « Le constructeur doit allouer lui-même
       toutes les zones dynamiques de l'objet. »
    */

    if (inStart != nullptr)
    {
        char *tmpStartCity = new char[strlen(inStart) + 1];
        strcpy(tmpStartCity, inStart);
        startCity = tmpStartCity;
    }
    else
    {
        startCity = nullptr;
    }

    if (inEnd != nullptr)
    {
        char *tmpEndCity = new char[strlen(inEnd) + 1];
        strcpy(tmpEndCity, inEnd);
        endCity = tmpEndCity;
    }
    else
    {
        endCity = nullptr;
    }

    if (inMode != nullptr)
    {
        char *tmpMode = new char[strlen(inMode) + 1];
        strcpy(tmpMode, inMode);
        mode = tmpMode;
    }
    else
    {
        mode = nullptr;
    }
} //----- Fin de SimpleTrip

SimpleTrip::~SimpleTrip()
{
#ifdef MAP
    cout << "Appel au destructeur de <SimpleTrip>" << endl;
#endif
    delete[] startCity;
    delete[] endCity;
    delete[] mode;
} //----- Fin de ~SimpleTrip

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées