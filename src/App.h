/*************************************************************************
                           App  -  description
                             -------------------
    début                : 2019-11-19
    copyright            : (C) 2019 FADILI Zineb & FORLER Corentin
    e-mail               : zineb.fadili@insa-lyon.fr
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
// La classe App sert de chef d'orchestre de tout le programme.
// Elle est notamment utilisée pour gérer l'aspect "interface utilisateur"
//
// Cette classe contient tout le code nécessaire pour faire fonctionner
// l’application de gestion de trajets. Le main() appelle la méthode Run()
// de l’instance de la classe App. La méthode Run() appelle ensuite
// la méthode protégée menuPrincipal(). Cette dernière fonction lit
// sur l’entrée standard le choix de menu que l’utilisateur fait,
// puis lance les fonctions menuConsulter, menuAjouter, ou menuRechercher
// en fonction de l’entrée de l’utilisateur. L’utilisateur peut revenir au
// menu précédent (ou quitter l’application, dans le menu principal)
// en sélectionnant l’option 0.
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
    // Cette méthode est le point d'entrée dans l'interface utilisateur
    // Elle renvoie le code de retour du programme, qui est :
    //   * 0 s'il n'y a pas eu d'erreur
    //   * 1 s'il y a eu une erreur fatale
    // Contrat :
    // La valeur de retour est soit 0 soit 1.
    int Run();

    static int Choose(const unsigned int nChoices, const char *choices[]);
    // Mode d'emploi :
    // Cette méthode sert à demander à l'utilisateur de choisir un menu
    // L'option 0 est toujours affichée en dernier (et sert à revenir au
    //   menu précédent ou quitter l'application)
    // Contrats :
    // - la valeur de retour de la fonction est :
    //     * soit -1 en cas d'erreur ou de ligne vide,
    //     * soit entre 0 et nChoices inclus.
    //

    static const char *Ask(const char *question);
    // Mode d'emploi :
    // Le paramètre "question" est une chaîne de caractères
    // qui décrit la question à poser à l'utilisateur
    // La réponse est lue sur l'entrée standard dans une chaîne de
    // caractères allouée sur le tas et dont un pointeur est renvoyé.
    // Contrat :
    // * "question" doit être un pointeur vers une chaîne de caractères
    //   (donc différent de nullptr)
    // * La valeur de retour est un pointeur vers
    //   une chaîne de caractères allouée sur le tas,
    //   donc ce pointeur doit être libéré, car il ne sera pas libéré dans
    //   Ask(...), à part si Ask(...) retourne `nullptr`.
    // * La valeur de retourne ne vaut `nullptr` que quand l'utilisateur
    //   a entré une chaîne vide.

    // Mode d'emploi :
    // Le paramètre "message" est une chaîne de caractères
    // qui décrit l'erreur à afficher sur la sortie d'erreur.
    // Ce message est préfixé de la chaîne « Erreur: ».
    // Contrat :
    // * "message" doit être un pointeur vers une chaîne de caractères
    //   (donc différent de nullptr)
    static void Error(const char *message);

    // Mode d'emploi :
    // Le paramètre "title" est une chaîne de caractères
    // qui décrit le titre d'un menu qui sera affiché
    // sur la sortie standard.
    // Ce titre est affiché préfixé et suffixé de tirets
    // et ne correspond qu'à un aspect esthétique.
    // Contrat :
    // * "title" doit être un pointeur vers une chaîne de caractères
    //   (donc différent de nullptr)
    static void MenuTitle(const char *title);

    // On désactive l'opérateur d'affectation
    App &operator=(const App &) = delete;

    //-------------------------------------------- Constructeurs - destructeur
    // On désactive le constructeur de copie
    App(const App &anApp) = delete;

    App();
    // Mode d'emploi :
    // Alloue le catalogue sur la pile.

    ~App();
    // Mode d'emploi :
    // Détruit le catalogue

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées
    MenuStatus menuPrincipal();
    // Mode d'emploi :
    // Affiche le menu principal
    // L'utilisateur peut choisir parmi plusieurs options :
    // 1. Consulter le catalogue
    // 2. Ajouter un trajet
    // 3. Rechercher un trajet
    // 0. Quitter l'application
    //
    // La valeur de retour est MenuStatus::ERROR en cas d'erreur fatale
    // MenuStatus::DONE sinon.

    MenuStatus menuConsulter() const;
    // Mode d'emploi :
    // Affiche le catalogue
    // La valeur de retour est MenuStatus::ERROR en cas d'erreur fatale
    // MenuStatus::DONE sinon.

    MenuStatus menuAjouter();
    // Mode d'emploi :
    // Affiche le menu d'ajout de trajet
    // L'utilisateur peut choisir parmi plusieurs options :
    // 1. Trajet simple
    // 2. Trajet composé
    // 0. Retourner au menu principal
    //
    // La valeur de retour est MenuStatus::ERROR en cas d'erreur fatale
    // MenuStatus::DONE sinon.

    MenuStatus menuAjouterTrajetSimple();
    // Mode d'emploi :
    // Affiche l'interface d'ajout de trajet simple
    // L'utilisateur doit renseigner plusieurs données :
    // - ville de départ
    // - ville d'arrivée
    // - mode de transport
    //
    // À tout moment l'utilisateur peut rentrer une valeur vide
    // pour quitter le menu (le trajet ne sera pas enregistré).
    //
    // La valeur de retour est MenuStatus::ERROR en cas d'erreur fatale
    // MenuStatus::DONE sinon.

    MenuStatus menuAjouterTrajetCompose();
    // Mode d'emploi :
    // Affiche l'interface d'ajout de trajet composé
    // L'utilisateur doit renseigner plusieurs données :
    // - ville de départ
    // - ville d'escale 1
    // - mode de transport 1
    // - ville d'escale 2
    // - mode de transport 2
    // - [...]
    // - ville d'escale N [qui est aussi ville d'arrivée]
    // - mode de transport N
    //
    // La ville de départ de chaque sous-trajet (sauf le premier)
    // est automatiquement remplie car les sous-trajets doivent être contigus.
    //
    // À tout moment l'utilisateur peut rentrer une valeur vide
    // pour quitter le menu. Le trajet ne sera enregistré QUE si
    // le trajet composé est valide, c'est-à-dire assez long.
    //
    // Si l'escale en cours d'ajout n'est pas valide,
    // alors elle ne sera pas ajoutée au trajet composé.
    //
    // La valeur de retour est MenuStatus::ERROR en cas d'erreur fatale
    // MenuStatus::DONE sinon (même si l'utilisateur quitte le menu).

    MenuStatus menuRechercher() const;
    // Mode d'emploi :
    // Affiche le menu de recherche
    //
    // L'utilisateur doit renseigner plusieurs données :
    // - ville de départ
    // - ville d'arrrivée
    //
    // L'utilisateur peut choisir parmi plusieurs types de recherche :
    // 1. Recherche simple
    // 2. Recherche avancée
    // 0. Retourner au menu principal
    //
    // L'application affiche ensuite les différentes suites de trajets
    // qui peuvent convenir pour les critères de recherche spécifiés.
    //
    // La valeur de retour est MenuStatus::ERROR en cas d'erreur fatale
    // MenuStatus::DONE sinon (même si l'utilisateur quitte le menu).

    //----------------------------------------------------- Attributs protégés
    Catalog *catalog;
};

//-------------------------------- Autres définitions dépendantes de <App>

#endif // APP_H
