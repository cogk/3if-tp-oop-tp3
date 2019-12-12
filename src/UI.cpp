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

    char *answer = new char[UI_BUFFER_SIZE]{0};

    cin.getline(answer, UI_BUFFER_SIZE);

    if (answer[0] == '\0')
    {
        // length == 0
        delete[] answer;
        return nullptr;
    }

    return answer;
} //----- Fin de UI::Ask

/**
 * Contrats :
 * - la valeur de retour de la fonction est :
 *     soit -1,
 *     soit entre 0 et nChoices inclus.
 */
int UI::Choose(const unsigned int nChoices, const char *choices[])
{
    unsigned int answer = 0;

    for (unsigned int i = 1; i < nChoices; i++)
    {
        cout << "| " << i << ". " << choices[i] << EOL;
    }

    // Quitter ou retourner au menu précédent
    cout << "| " << 0 << ". " << choices[0] << EOL;

    cin >> answer;
    cin.clear(); // on efface les bits d'erreur du flux std::cin

    cin.ignore(10000, '\n'); // skip new line

    if (answer > nChoices)
    {
        return -1;
    }

    return answer; // [0 ; nChoices]
} //----- Fin de UI::Choose

void UI::Error(const char *message)
{
    cerr << "Erreur: " << message << EOL;
} //----- Fin de UI::Error

void UI::MenuTitle(const char *title)
{
    cout << EOL << "--- " << title << " ---" << EOL;
} //----- Fin de UI::Error

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
