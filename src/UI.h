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
// Mode d'emploi :
//
// Contrat :
//
int Choose(const int nChoices, const char *choices[]);
const char *Ask(const char *question);

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
}; // namespace UI

//-------------------------------- Autres définitions dépendantes de <UI>

#endif // UI_H
