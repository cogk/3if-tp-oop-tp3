/*************************************************************************
                           App  -  description
                             -------------------
    début                : 2019-11-19
    copyright            : (C) 2019 BERTHOMET Guillaume & FORLER Corentin
    e-mail               : guillaume.berthomet@insa-lyon.fr
                           corentin.forler@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <App> (fichier App.h) ----------------
#if !defined(APP_H)
#define APP_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Catalog.h"
#include "CompoundTrip.h"
#include "SimpleTrip.h"
#include "Trip.h"

//------------------------------------------------------------- Constantes
#define EOL "\r\n"
const int UI_BUFFER_SIZE = 256;

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <App>
//
//
//------------------------------------------------------------------------

class App
{
    //----------------------------------------------------------------- PUBLIC

    enum MenuStatus
    {
        DONE, // On a terminé sans problème.
        ERROR // On sort de la boucle et on a déjà
              // affiché une erreur à l'utilisateur.
    };

public:
    //----------------------------------------------------- Méthodes publiques
    // Mode d'emploi :
    //
    // Contrat :
    //
    int Run();

    static int Choose(const unsigned int nChoices, const char *choices[]);
    // Mode d'emploi :
    //
    // Contrat :
    //

    static const char *Ask(const char *question);
    // Mode d'emploi :
    // Le paramètre question est une chaîne de caractères
    // qui décrit la question à poser à l'utilisateur
    // Contrat :
    // * question doit être un pointeur vers une chaîne de caractères
    //   (donc différent de nullptr)
    // * La valeur de retour est un pointeur vers
    //   une chaîne de caractères allouée sur le tas,
    //   donc ce pointeur doit être libéré, car il ne sera pas libéré dans
    //   Ask(...), à part si Ask(...) retourne `nullptr`.
    // * La valeur de retourne ne vaut `nullptr` que quand l'utilisateur
    //   a entré une chaîne vide.

    static void Error(const char *message);

    static void MenuTitle(const char *title);

    // On désactive l'opérateur d'affectation
    App &operator=(const App &) = delete;

    //-------------------------------------------- Constructeurs - destructeur
    // On désactive le constructeur de copie
    App(const App &anApp) = delete;

    App();
    // Mode d'emploi :
    //
    // Contrat :
    //

    ~App();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées
    MenuStatus menuPrincipal();
    MenuStatus menuConsulter() const;
    MenuStatus menuAjouter();
    MenuStatus menuAjouterTrajetSimple();
    MenuStatus menuAjouterTrajetCompose();
    MenuStatus menuRechercher() const;

    //----------------------------------------------------- Attributs protégés
    Catalog *catalog;
};

//-------------------------------- Autres définitions dépendantes de <App>

#endif // APP_H
