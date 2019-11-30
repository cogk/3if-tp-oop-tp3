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
    cout << EOL << "--- MENU PRINCIPAL ---" << EOL;

    const int nChoices = 4;
    const char *choices[] = {"Consulter le catalogue", "Ajouter un trajet", "Rechercher un trajet", "Quitter"};

    while (true)
    {
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
            cout << "Cette option n'existe pas." << EOL;
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

App::MenuStatus App::menuConsulter()
{
    cout << EOL << "--- CONSULTATION DU CATALOGUE ---" << EOL;
    const unsigned int nTrajets = this->catalog->Size();

    if (nTrajets == 0)
    {
        cout << "Pas de trajets dans le catalogue." << EOL;
    }
    else
    {
        cout << "Il y a " << nTrajets << " trajets dans le catalogue." << EOL;
    }

    for (unsigned int i = 0; i < nTrajets; i++)
    {
        Trip *trajet = this->catalog->Get(i);
        cout << "Trajet #" << i << "/" << nTrajets << " : de "
             << "'" << trajet->GetStart()->GetName() << "'"
             << " à "
             << "'" << trajet->GetEnd()->GetName() << "'"
             << " en "
             << "'" << trajet->GetMode() << "'";
    }

    return MenuStatus::DONE;
}

App::MenuStatus App::menuAjouter()
{
    cout << EOL << "--- AJOUTER UN TRAJET ---" << EOL;
    cout << EOL << "Veuillez choisir un type de trajet." << EOL;

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
            cout << "Cette option n'existe pas." << EOL;
            continue;
        }

        return MenuStatus::DONE;
    }
}

App::MenuStatus App::menuAjouterTrajetSimple()
{
    cout << EOL << "--- AJOUTER UN TRAJET SIMPLE ---" << EOL;
    cout << EOL << "Veuillez entrer les informations du trajet." << EOL;

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

    const City *startCity = new City(startName);
    const City *endCity = new City(endName);
    Trip *trip = new Trip(startCity, endCity, mode);

    this->catalog->Add(trip);

    delete[] startName;
    delete[] endName;
    delete[] mode;
    return MenuStatus::DONE;
}
App::MenuStatus App::menuAjouterTrajetCompose()
{
    cout << EOL << "--- AJOUTER UN TRAJET COMPOSÉ ---" << EOL;

    unsigned int i = 0;

    ArrayList *trips = new ArrayList(8);

    while (true)
    {
        cout << EOL << "Trajet #" << (i + 1) << EOL;
        const char MSG_DEP[] = "  | Ville de départ:   ";
        const char MSG_ARR[] = "  | Ville d'arrivée:   ";
        const char MSG_MOD[] = "  | Mode de transport: ";

        const char *startName = UI::Ask(MSG_DEP);
        if (startName == nullptr)
            break;

        const char *endName = UI::Ask(MSG_ARR);
        if (endName == nullptr)
            break;

        const char *mode = UI::Ask(MSG_MOD);
        if (mode == nullptr)
            break;

        const City *startCity = new City(startName);
        const City *endCity = new City(endName);
        Trip *trip = new Trip(startCity, endCity, mode);

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

App::MenuStatus App::menuRechercher()
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
