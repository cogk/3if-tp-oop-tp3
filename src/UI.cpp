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
  char *answer = new char[UI_BUFFER_SIZE];

  cout << question << " ";
  scanf("%255[^\n]", answer);
  getchar(); // skip new line

  return answer;
} //----- Fin de Méthode

//----------------------------------------------------- Méthodes publiques
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

  if (answer < 1 || answer > nChoices)
  {
    return -1;
  }

  return answer; // [1 ; nChoices]
} //----- Fin de Méthode

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
