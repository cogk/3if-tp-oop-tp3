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
#include <cstring>
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "App.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
int App::Run()
{
    cout << "Bienvenue dans l'application de gestion de trajets !" << EOL;
    menuPrincipal();
    return 0;
} //----- Fin de App::Run

App::MenuStatus App::menuPrincipal()
{
    const int nChoices = 4;
    const char *choices[] = {"Consulter le catalogue", "Ajouter un trajet", "Rechercher un trajet", "Quitter"};

    while (true)
    {
        cout << EOL << "--- MENU PRINCIPAL ---" << EOL;
        const int ans = UI::Choose(nChoices, choices);

        MenuStatus status = MenuStatus::DONE;
        switch (ans)
        {
        case 1:
            status = App::menuConsulter();
            break;
        case 2:
            status = App::menuAjouter();
            break;
        case 3:
            status = App::menuRechercher();
            break;
        case 4:
            return MenuStatus::DONE; // exit normally
            break;
        default:
            UI::Error("Cette option n'existe pas.");
            status = MenuStatus::ERROR;
            break;
        }

        if (status == MenuStatus::ERROR)
        {
            return status;
        }
        else
        {
            continue;
        }
    }
}

App::MenuStatus App::menuConsulter() const
{
    cout << EOL << "--- CONSULTATION DU CATALOGUE ---" << EOL;
    catalog->Display();
    return MenuStatus::DONE;
}

App::MenuStatus App::menuAjouter()
{
    cout << EOL << "--- AJOUTER UN TRAJET ---" << EOL;
    cout << "Veuillez choisir un type de trajet." << EOL;

    const int nChoices = 2;
    const char *choices[] = {"Trajet simple", "Trajet composé"};

    while (true)
    {
        const int ans = UI::Choose(nChoices, choices);

        switch (ans)
        {
        case 1:
            return App::menuAjouterTrajetSimple();
        case 2:
            return App::menuAjouterTrajetCompose();
        default:
            UI::Error("Cette option n'existe pas.");
            break;
        }

        return MenuStatus::DONE;
    }
}

App::MenuStatus App::menuAjouterTrajetSimple()
{
    cout << EOL << "--- AJOUTER UN TRAJET SIMPLE ---" << EOL;
    cout << "Veuillez entrer les informations du trajet." << EOL;

    const char MSG_DEP[] = "* Ville de départ:   ";
    const char MSG_ARR[] = "* Ville d'arrivée:   ";
    const char MSG_MOD[] = "* Mode de transport: ";

    const char *startName = UI::Ask(MSG_DEP);
    if (startName == nullptr)
        return MenuStatus::ERROR;

    const char *endName = UI::Ask(MSG_ARR);
    if (endName == nullptr)
        return MenuStatus::ERROR;

    const char *mode = UI::Ask(MSG_MOD);
    if (mode == nullptr)
        return MenuStatus::ERROR;

    Trip *trip = new SimpleTrip(startName, endName, mode);
    catalog->Add(trip);

    delete[] startName;
    delete[] endName;
    delete[] mode;

    return MenuStatus::DONE;
}

App::MenuStatus App::menuAjouterTrajetCompose()
{
    cout << EOL << "--- AJOUTER UN TRAJET COMPOSÉ ---" << EOL;
    cout << "Appuyez sur [entrée] à tout moment pour quitter." << EOL
         << "Tous les sous-trajets valides seront enregistrés.";

    const char MSG_DEP[] = "  | Ville de départ:   ";
    const char MSG_ARR[] = "  | Ville d'arrivée:   ";
    const char MSG_MOD[] = "  | Mode de transport: ";

    unsigned int i = 0;

    ArrayList *trips = new ArrayList(4);

    while (true)
    {
        cout << EOL << "Trajet #" << (i + 1) << EOL;

        char *nonConstStartName = nullptr;

        if (i == 0)
        {
            // S'il s'agit du premier trajet, alors on demande le nom de la ville de départ.
            const char *answer = UI::Ask(MSG_DEP);

            if (answer == nullptr)
            {
                break;
            }

            const unsigned int len = strlen(answer);
            nonConstStartName = new char[len + 1]{0};
            nonConstStartName = strncpy(nonConstStartName, answer, len);

            delete[] answer;
        }
        else
        {
            // S'il ne s'agit pas du premier trajet,
            // alors on connait déjà le nom de sa ville de départ
            // puisqu'il s'agit du nom de la dernière ville d'arrivée.
            const char *lastEndCityName = trips->GetLast()->GetEnd();

            const unsigned int len = strlen(lastEndCityName);
            nonConstStartName = new char[len + 1]{0};
            nonConstStartName = strncpy(nonConstStartName, lastEndCityName, len);

            cout << MSG_DEP << nonConstStartName << " [valeur remplie automatiquement]" << EOL;
        }

        const char *startName = nonConstStartName;
        if (startName == nullptr)
        {
            break;
        }

        const char *endName = UI::Ask(MSG_ARR);
        if (endName == nullptr)
        {
            delete[] startName;
            break;
        }

        const char *mode = UI::Ask(MSG_MOD);
        if (mode == nullptr)
        {
            delete[] startName;
            delete[] endName;
            break;
        }

        Trip *trip = new SimpleTrip(startName, endName, mode);
        trips->Add(trip);

        delete[] startName;
        delete[] endName;
        delete[] mode;

        i++;
    }

    CompoundTrip *compoundTrip = new CompoundTrip(trips);
    catalog->Add(compoundTrip);

    return MenuStatus::DONE;
}

App::MenuStatus App::menuRechercher() const
{
    return MenuStatus::DONE;
}

//-------------------------------------------- Constructeurs - destructeur

App::App()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <App>" << endl;
#endif
    this->catalog = new Catalog();
} //----- Fin de App

App::~App()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <App>" << endl;
#endif
    delete this->catalog;
} //----- Fin de ~App

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
