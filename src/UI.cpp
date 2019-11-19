/*************************************************************************
                           UI  -  description
                             -------------------
    début                : 2019-11-19
    copyright            : (C) 2019 BERTHOMET Guillaume & FORLER Corentin
    e-mail               : guillaume.berthomet@insa-lyon.fr
                           corentin.forler@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <UI> (fichier UI.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <cstdio>
#include <iostream>

//------------------------------------------------------ Include personnel
#include "UI.h"

//------------------------------------------------------------- Constantes
const int UI_BUFFER_SIZE = 256;

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
const char *
UI::Ask(const char *question)
{
    char *answer = new char[UI_BUFFER_SIZE];

    cout << question << " ";
    scanf("%255[^\n]", answer);
    getchar(); // skip new line

    return answer;
} //----- Fin de Méthode

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
