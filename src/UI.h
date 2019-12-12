/*************************************************************************
                           UI  -  description
                             -------------------
    début                : 2019-11-19
    copyright            : (C) 2019 BERTHOMET Guillaume & FORLER Corentin
    e-mail               : guillaume.berthomet@insa-lyon.fr
                           corentin.forler@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <UI> (fichier UI.h) ----------------
#if !defined(UI_H)
#define UI_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>

//------------------------------------------------------------- Constantes
#define EOL "\r\n"

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <UI>
//
//
//------------------------------------------------------------------------

namespace UI
{
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
int Choose(const int nChoices, const char *choices[]);
// Mode d'emploi :
//
// Contrat :
//

const char *Ask(const char *question);
// Mode d'emploi :
// Le paramètre question est une chaîne de caractères
// qui décrit la question à poser à l'utilisateur
// Contrat :
// * question doit être un pointeur vers une chaîne de caractères
//   (donc différent de nullptr)
// * La valeur de retour est un pointeur vers
//   une chaîne de caractères allouée sur le tas,
//   donc ce pointeur doit être libéré, car il ne sera pas libéré dans
//   UI::Ask(...), à part si UI::Ask retourne `nullptr`.
// * La valeur de retourne ne vaut `nullptr` que quand l'utilisateur
//   a entré une chaîne vide.

void Error(const char *message);

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
} // namespace UI

//-------------------------------- Autres définitions dépendantes de <UI>

#endif // UI_H
