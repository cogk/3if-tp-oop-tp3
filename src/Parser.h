/*************************************************************************
                           Parser  -  description
                             -------------------
    début                : 2019-11-19
    copyright            : (C) 2019 FADILI Zineb & FORLER Corentin
    e-mail               : zineb.fadili@insa-lyon.fr
                           corentin.forler@insa-lyon.fr
*************************************************************************/

//---- Interface de la classe <Parser> (fichier Parser.h) ----------
#if !defined(PARSER_H)
#define PARSER_H

//--------------------------------------------------- Interfaces utilisées
#include "ListOfTrips.h"
#include <fstream>
#include <iostream>
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Rôle de la classe <Parser>
//  Parser permet de lire une liste de Trip à partir d'un fichier
//------------------------------------------------------------------------

class Parser
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    static ListOfTrips *Parse(ifstream &input);

    static void FiltreParType(ListOfTrips *trips, Trip::TYPE typeTrajet);

    static void FiltreParIndex(ListOfTrips *trips, unsigned int debut, unsigned int fin);

    static void FiltreParNom(ListOfTrips *trips, const char *startCitySearch, const char *endCitySearch);

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
};

#endif // PARSER_H
