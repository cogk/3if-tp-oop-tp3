/*************************************************************************
                           ArrayList  -  description
                             -------------------
    début                : 2019-11-19
    copyright            : (C) 2019 BERTHOMET Guillaume & FORLER Corentin
    e-mail               : guillaume.berthomet@insa-lyon.fr
                           corentin.forler@insa-lyon.fr
*************************************************************************/

//---- Interface de la classe <ArrayList> (fichier ArrayList.h) ----------
#if !defined(ARRAY_LIST_H)
#define ARRAY_LIST_H

//--------------------------------------------------- Interfaces utilisées
#include "Trip.h"

//------------------------------------------------------------- Constantes
const unsigned int DEFAULT_SIZE = 5;

//------------------------------------------------------------------------
// Rôle de la classe <ArrayList>
//  ArrayList permet de stocker et manipuler une liste de taille variable
// de Trips
//  Via les méthodes Pop et Add, il est aussi possible de l'utiliser comme
// une pile de Trip
//------------------------------------------------------------------------

class ArrayList
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    void Add(Trip *element);
    // Mode d'emploi : Ajoute un élément à la fin de la liste

    Trip *Remove(unsigned int index);
    // Mode d'emploi : Supprime un élément à l'index donné, renvoie le Trip
    //    supprimé
    // Contrat : index < Size()

    Trip *Pop();
    // Mode d'emploi : Supprime le dernier élément de la liste, renvoie le Trip
    //    supprimé

    Trip *Get(unsigned int index) const;
    // Contrat : index < Size()

    Trip *GetLast() const;
    // Contrat : Size() > 0

    bool Contains(Trip *trip) const;
    // Mode d'emploi : Renvoie vrai si la liste contient un pointeur pointant
    //   sur LA MEME CASE MEMOIRE que le paramètre trip (!= égalité des valeurs)

    unsigned int Size() const;
    // Mode d'emploi : Retourne la taille actuelle de la liste

    bool IsEmpty() const;

    // On désactive l'opérateur d'affectation
    ArrayList &operator=(const ArrayList &) = delete;

    //-------------------------------------------- Constructeurs - destructeur
    ArrayList(const ArrayList &anArrayList);
    // Mode d'emploi (constructeur de copie) :
    //  INTERDIT D'UTILISATION

    ArrayList(unsigned int startingMaxSize = DEFAULT_SIZE);
    // Mode d'emploi : maxSize indique la taille que la liste allouera pour
    //   stocker ses éléments (qui pourra varier si besoin)
    // Contrat : startingMaxSize >= 1

    virtual ~ArrayList();

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées
    void DoubleSize();
    // Mode d'emploi : double la taille actuellement allouée à la list

    //----------------------------------------------------- Attributs protégés
    unsigned int currentSize;
    unsigned int maxSize;

    Trip **list;
};

#endif // ARRAY_LIST_H
