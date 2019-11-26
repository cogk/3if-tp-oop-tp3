/*************************************************************************
                           App  -  description
                             -------------------
    début                : 2019-11-19
    copyright            : (C) 2019 BERTHOMET Guillaume & FORLER Corentin
    e-mail               : guillaume.berthomet@insa-lyon.fr
                           corentin.forler@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <App> (fichier App.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "App.h"
#include "UI.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
int App::Run()
{
    cout << "Hello, World!" << EOL;

    const char *answer = UI::Ask("Comment allez-vous ?");
    cout << answer << EOL;

    const int nChoices = 3;
    const char *choices[nChoices] = {
        "Lorem",
        "Ipsum",
        "Dolor"};
    const int ans = UI::Choose(nChoices, choices);

    if (ans == -1)
    {
        cout << "Cette option n'existe pas." << EOL;
    }
    else
    {
        cout << "Vous avez choisi " << ans << " - " << choices[ans - 1] << "." << EOL;
    }

    return 0;
} //----- Fin de Méthode

//-------------------------------------------- Constructeurs - destructeur

App::App()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <App>" << endl;
#endif
} //----- Fin de App

App::~App()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <App>" << endl;
#endif
} //----- Fin de ~App

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
