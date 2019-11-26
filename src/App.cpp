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
#include "UI.h"

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
    while (true)
    {
        cout << EOL << "--- MENU PRINCIPAL ---" << EOL;

        const int nChoices = 3;
        const char *choices[] = {"Consulter le catalogue", "Ajouter un trajet", "Rechercher un trajet"};

        const int ans = UI::Choose(nChoices, choices);

        switch (ans)
        {
        case 1:
            return App::menuConsulter();
        case 2:
            return App::menuAjouter();
        case 3:
            return App::menuRechercher();
        default:
            cout << "Cette option n'existe pas." << EOL;
            continue;
        }

        return MenuStatus::DONE;
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
        cout << "Trajet #" << i << "/" << nTrajets << " :\tde "
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
    // const int nChoices = 2;
    // const char *choices[] = {"Trajet simple", "Trajet composé"};
    // const char *answer = UI::Ask("Comment allez-vous ?");
    // cout << answer << EOL;
    // delete[] answer;
    return MenuStatus::DONE;
}
App::MenuStatus App::menuAjouterTrajetSimple()
{
    return MenuStatus::DONE;
}
App::MenuStatus App::menuAjouterTrajetCompose()
{
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
