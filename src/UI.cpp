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
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "UI.h"

//------------------------------------------------------------- Constantes
const int UI_BUFFER_SIZE = 256;

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
const char *UI::Ask(const char *question)
{
    cout << question;

    char *answer = new char[UI_BUFFER_SIZE];
    fgets(answer, UI_BUFFER_SIZE, stdin);

    if (!answer)
    {
        return nullptr;
    }

    unsigned int len = strlen(answer);
    while (len > 0 && (answer[len - 1] == '\n' || answer[len - 1] == '\r'))
    {
        answer[len - 1] = '\0';
        len--;
    }

    if (len == 0)
    {
        return nullptr;
    }
    return answer;
} //----- Fin de Méthode

/**
 * Contrats :
 * - la valeur de retour de la fonction est :
 *     soit -1,
 *     soit entre 1 et nChoices inclus.
 *
 */
int UI::Choose(const int nChoices, const char *choices[])
{
    int answer = 0;

    for (int i = 0; i < nChoices; i++)
    {
        cout << "| " << (i + 1) << ". \t" << choices[i] << EOL;
    }

    cin >> answer;
    cin.ignore(1, '\n'); // skip new line

    if (answer < 1 || answer > nChoices)
    {
        return -1;
    }

    return answer; // [1 ; nChoices]
} //----- Fin de Méthode

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
