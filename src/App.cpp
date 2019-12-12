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
    App::MenuStatus res = menuPrincipal();
    return (res == MenuStatus::ERROR) ? 1 : 0;
} //----- Fin de App::Run

const char *App::Ask(const char *question)
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
} //----- Fin de App::Ask

/**
 * Contrats :
 * - la valeur de retour de la fonction est :
 *     soit -1,
 *     soit entre 0 et nChoices inclus.
 */
int App::Choose(const unsigned int nChoices, const char *choices[])
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
} //----- Fin de App::Choose

void App::Error(const char *message)
{
    cerr << "Erreur: " << message << EOL;
} //----- Fin de App::Error

void App::MenuTitle(const char *title)
{
    cout << EOL << "--- " << title << " ---" << EOL;
} //----- Fin de App::Error

//-------------------------------------------- Constructeurs - destructeur
App::App()
    : catalog(new Catalog())
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <App>" << endl;
#endif
} //----- Fin de App

App::~App()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <App>" << endl;
#endif
    delete catalog;
} //----- Fin de ~App

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

App::MenuStatus App::menuPrincipal()
{
    const int nChoices = 4;
    const char *choices[] = {"Quitter l'application", "Consulter le catalogue", "Ajouter un trajet", "Rechercher un trajet"};

    while (true)
    {
        App::MenuTitle("MENU PRINCIPAL");
        const int ans = App::Choose(nChoices, choices);

        MenuStatus status = MenuStatus::DONE;
        switch (ans)
        {
        case 0:
            return MenuStatus::DONE; // exit normally
            // break;
        case 1:
            status = App::menuConsulter();
            break;
        case 2:
            status = App::menuAjouter();
            break;
        case 3:
            status = App::menuRechercher();
            break;
        default:
            App::Error("Cette option n'existe pas.");
            continue;
            // status = MenuStatus::ERROR;
            // break;
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
    App::MenuTitle("CONSULTATION DU CATALOGUE");
    catalog->Display();
    return MenuStatus::DONE;
}

App::MenuStatus App::menuAjouter()
{
    App::MenuTitle("AJOUTER UN TRAJET");
    cout << "Veuillez choisir un type de trajet." << EOL;

    const int nChoices = 3;
    const char *choices[] = {"Retourner au menu principal", "Trajet simple", "Trajet composé"};

    while (true)
    {
        const int ans = App::Choose(nChoices, choices);

        switch (ans)
        {
        case 0:
            return MenuStatus::DONE;
        case 1:
            return App::menuAjouterTrajetSimple();
        case 2:
            return App::menuAjouterTrajetCompose();
        default:
            App::Error("Cette option n'existe pas.");
            break;
        }

        return MenuStatus::DONE;
    }
}

App::MenuStatus App::menuAjouterTrajetSimple()
{
    App::MenuTitle("AJOUTER UN TRAJET SIMPLE");
    cout << "Veuillez entrer les informations du trajet." << EOL;

    const char MSG_DEP[] = "* Ville de départ:   ";
    const char MSG_ARR[] = "* Ville d'arrivée:   ";
    const char MSG_MOD[] = "* Mode de transport: ";

    const char *startName = App::Ask(MSG_DEP);
    if (startName == nullptr)
        return MenuStatus::DONE;

    const char *endName = App::Ask(MSG_ARR);
    if (endName == nullptr)
        return MenuStatus::DONE;

    if (!strcmp(startName, endName)) // startName equals endName
    {
        delete[] startName;
        delete[] endName;

        App::Error("La ville d'arrivée doit être différente de la ville de départ. "
                   "Le trajet simple n'a pas été enregistré.");
        return MenuStatus::DONE;
    }

    const char *mode = App::Ask(MSG_MOD);
    if (mode == nullptr)
        return MenuStatus::DONE;

    Trip *trip = new SimpleTrip(startName, endName, mode);
    catalog->Add(trip);

    delete[] startName;
    delete[] endName;
    delete[] mode;

    return MenuStatus::DONE;
}

App::MenuStatus App::menuAjouterTrajetCompose()
{
    App::MenuTitle("AJOUTER UN TRAJET COMPOSÉ");
    cout << "Appuyez sur [entrée] à tout moment pour quitter." << EOL
         << "Tous les sous-trajets valides seront enregistrés.";

    const char MSG_DEP[] = "  | Ville de départ:   ";
    const char MSG_ARR[] = "  | Ville d'arrivée:   ";
    const char MSG_MOD[] = "  | Mode de transport: ";

    ListOfTrips *trips = new ListOfTrips(4);

    unsigned int k = 0;
    while (true)
    {
        cout << EOL << "Trajet #" << (k + 1) << EOL;

        char *nonConstStartName = nullptr;

        if (k == 0)
        {
            // S'il s'agit du premier trajet, alors on demande le nom de la ville de départ.
            const char *answer = App::Ask(MSG_DEP);

            if (answer == nullptr)
            {
                break;
            }

            const long unsigned int len = strlen(answer);
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

            const long unsigned int len = strlen(lastEndCityName);
            nonConstStartName = new char[len + 1]{0};
            nonConstStartName = strncpy(nonConstStartName, lastEndCityName, len);

            cout << MSG_DEP << nonConstStartName << " [valeur remplie automatiquement]" << EOL;
        }

        const char *startName = nonConstStartName;
        if (startName == nullptr)
        {
            break;
        }

        const char *endName = App::Ask(MSG_ARR);
        if (endName == nullptr)
        {
            delete[] startName;
            break;
        }
        if (!strcmp(startName, endName)) // startName equals endName
        {
            delete[] startName;
            delete[] endName;
            const unsigned int nSubTrips = trips->Size();
            for (unsigned int i = 0; i < nSubTrips; i++)
            {
                delete trips->Get(i);
            }
            delete trips;

            App::Error("La ville d'arrivée doit être différente de la ville de départ. "
                       "Le trajet composé n'a pas été enregistré.");
            return MenuStatus::DONE;
        }

        const char *mode = App::Ask(MSG_MOD);
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

        k++;
    }

    const unsigned int nSubTrips = trips->Size();
    if (nSubTrips == 0) // trips est vide
    {
        for (unsigned int i = 0; i < nSubTrips; i++)
        {
            delete trips->Get(i);
        }
        delete trips;
        App::Error("Pas assez de sous-trajets dans le trajet composé en cours de création. "
                   "Le trajet composé n'a pas été enregistré.");
        return MenuStatus::DONE;
    }
    else
    {
        CompoundTrip *compoundTrip = new CompoundTrip(trips);
        catalog->Add(compoundTrip);

        cout << "Vous avez ajouté un nouveau trajet." << EOL;
        compoundTrip->Display();

        return MenuStatus::DONE;
    }
}

App::MenuStatus App::menuRechercher() const
{
    App::MenuTitle("RECHERCHER UN TRAJET");
    cout << "Veuillez renseigner les paramètres de recherche." << EOL;

    const char MSG_DEP[] = "  | Ville de départ: ";
    const char MSG_ARR[] = "  | Ville d'arrivée: ";

    const char *startName = App::Ask(MSG_DEP);
    if (startName == nullptr)
    {
        return MenuStatus::DONE;
    }

    const char *endName = App::Ask(MSG_ARR);
    if (endName == nullptr)
    {
        delete[] startName;
        return MenuStatus::DONE;
    }

    const int nChoices = 3;
    const char *choices[] = {"Retourner au menu principal", "Recherche simple", "Recherche avancée"};

    SearchResults *results = nullptr;
    while (results == nullptr)
    {
        cout << EOL << "Veuillez choisir un type de recherche." << EOL;
        const int ans = App::Choose(nChoices, choices);

        switch (ans)
        {
        case 0:
            delete startName;
            delete endName;
            return MenuStatus::DONE;
        case 1:
            results = catalog->Search(startName, endName);
            if (results == nullptr)
            {
                App::Error("BUG: results == nullptr");
                delete startName;
                delete endName;
                return MenuStatus::ERROR;
            }
            break;
        case 2:
            results = catalog->SearchV2(startName, endName);
            if (results == nullptr)
            {
                App::Error("BUG: results == nullptr");
                delete startName;
                delete endName;
                return MenuStatus::ERROR;
            }
            break;
        default:
            App::Error("Cette option n'existe pas.");
            // return MenuStatus::DONE;
            break;
        }
    }

    const unsigned int nResults = results->Size();

    if (nResults == 0)
    {
        cout << "Pas de trajet trouvé"
             << " entre " << startName << " et " << endName << "." << EOL << EOL;
    }
    else
    {
        cout << "Il y a " << nResults << " résultat" << (nResults > 1 ? "s" : "") << " de recherche"
             << " entre " << startName << " et " << endName << "." << EOL << EOL;

        for (unsigned int i = 0; i < nResults; i++)
        {
            ListOfTrips *subResult = results->Get(i);
            cout << "[Résultat N°" << (i + 1) << "]: ";

            const unsigned int nSubResult = subResult->Size();
            if (nSubResult == 1)
            {
                subResult->Get(0)->Display();
            }
            else
            {
                cout << EOL;
                for (unsigned int j = 0; j < nSubResult; j++)
                {
                    cout << " |-[" << (j + 1) << "/" << nSubResult << "]: ";
                    subResult->Get(j)->Display();
                }
            }
            cout << EOL;
        }
        cout << EOL;
    }

    delete[] startName;
    delete[] endName;
    for (unsigned int i = 0; i < results->Size(); i++)
    {
        // ATTENTION: on ne delete pas les trajets
        // contenus dans les sous-résultats car ils
        // ne sont que des références (pointeurs)
        // vers des objets qui sont présents dans le catalogue.

        // ListOfTrips *x = results->Get(i);
        // for (unsigned int j = 0; j < x->Size(); j++)
        // {
        //     delete x->Get(j);
        // }
        delete results->Get(i);
    }
    delete results;

    return MenuStatus::DONE;
}
