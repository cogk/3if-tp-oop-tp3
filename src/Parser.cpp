/*************************************************************************
                           Parser  -  description
                             -------------------
    début                : 2019-11-19
    copyright            : (C) 2019 FADILI Zineb & FORLER Corentin
    e-mail               : zineb.fadili@insa-lyon.fr
                           corentin.forler@insa-lyon.fr
*************************************************************************/

// - Réalisation de la classe <Parser> (fichier Parser.cpp) --
//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <fstream>
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "CompoundTrip.h"
#include "ListOfTrips.h"
#include "Parser.h"
#include "SimpleTrip.h"

//----------------------------------------------------------------- PUBLIC
ListOfTrips *Parser::Parse(ifstream &input)
{
    ListOfTrips *parseResults = new ListOfTrips();

    unsigned int lineIndex = 0;
    string line;

    while (std::getline(input, line))
    {
        lineIndex += 1;

        if (line == ">")
        {
            string startCity;
            string endCity;
            string mode;

            std::getline(input, startCity);
            std::getline(input, endCity);
            std::getline(input, mode);
            lineIndex += 3;

            Trip *trip = new SimpleTrip(startCity.c_str(), endCity.c_str(), mode.c_str());
            parseResults->Add(trip);
        }
        else if (line == "@")
        {
            unsigned int nSubTrips;
            input >> nSubTrips;
            std::getline(input, line); // on ignore les caractères restants sur la ligne

            if (line != "")
            {
                cerr << "Erreur de lecture: la ligne " << lineIndex << " doit ne contenir qu'un nombre" << endl;
                cerr << "  mais “" << line << "” trouvé après le nombre lu (" << nSubTrips << ")." << endl;
                input.close();
                return nullptr;
            }

            ListOfTrips *subtrips = new ListOfTrips(nSubTrips);

            string city1;
            string city2;
            string mode;

            std::getline(input, city1);
            lineIndex += 1;

            // On lit <nSubTrips> éléments, soit 2 * nSubTrips lignes au total.
            for (unsigned int i = 0; i < nSubTrips; i++)
            {
                std::getline(input, city2);
                std::getline(input, mode);
                lineIndex += 2;

                SimpleTrip *theSubtrip = new SimpleTrip(city1.c_str(), city2.c_str(), mode.c_str());
                subtrips->Add(theSubtrip);

                city1 = city2;
            }

            Trip *trip = new CompoundTrip(subtrips);
            parseResults->Add(trip);
        }
        else
        {
            cerr << "Erreur de lecture: caractère invalide à la ligne " << lineIndex << "." << endl;
            cerr << "  ‘@’ ou ‘>’ attendu" << endl;
            cerr << "  mais “" << line << "” trouvé." << endl;
            input.close();
            return nullptr;
        }
    }

    return parseResults;
}

ListOfTrips *Parser::FiltreParType(ListOfTrips *trips, Trip::TYPE typeTrajet)
{
    unsigned int nRemoved = 0;

    for (unsigned int i = 0; i < trips->Size(); i++)
    {
        const unsigned int j = i - nRemoved;
        if (trips->Get(j)->GetType() != typeTrajet)
        {
            trips->Remove(j);
            nRemoved++;
        }
    }

    return trips;
}

ListOfTrips *Parser::FiltreParIndex(ListOfTrips *trips, unsigned int debut, unsigned int fin)
{
    unsigned int nRemoved = 0;
    const unsigned int n = trips->Size();

    for (unsigned int i = 0; i < debut; i++)
    {
        trips->Remove(i - nRemoved);
        nRemoved++;
    }

    for (unsigned int i = fin + 1; i < n; i++)
    {
        trips->Remove(i - nRemoved);
        nRemoved++;
    }

    return trips;
}

//----------------------------------------------------- Méthodes publiques

//-------------------------------------------- Constructeurs - destructeur

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
