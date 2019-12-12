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
#include <iostream>
using namespace std;

//------------------------------------------------------------- Constantes
const unsigned int DEFAULT_SIZE = 5;

//------------------------------------------------------------------------
// Rôle de la classe <ArrayList>
//  ArrayList permet de stocker et manipuler une liste de taille variable
// de 'T' génériques
//  Via les méthodes Pop et Add, il est aussi possible de l'utiliser comme
// une pile
//------------------------------------------------------------------------

template <typename T>
class ArrayList
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    void Add(T *elem);
    // Mode d'emploi : Ajoute un élément à la fin de la liste

    T *Remove(unsigned int index);
    // Mode d'emploi : Supprime un élément à l'index donné, renvoie l'élément
    //    supprimé
    // Contrat : index < this->Size()

    T *Pop();
    // Mode d'emploi : Supprime le dernier élément de la liste, renvoie le Trip
    //    supprimé

    T *Get(unsigned int index) const;
    // Contrat : index < this->Size()

    T *GetLast() const;
    // Contrat : this->Size() > 0

    bool Contains(T *elem) const;
    // Mode d'emploi : Renvoie vrai si la liste contient un pointeur pointant
    //   sur LA MEME CASE MEMOIRE que le paramètre elem (égalité de référence)

    unsigned int Size() const;
    // Mode d'emploi : Retourne la taille actuelle de la liste

    bool IsEmpty() const;

    //-------------------------------------------- Constructeurs - destructeur
    ArrayList(const ArrayList &anArrayList);
    // Mode d'emploi (constructeur de copie) :
    //  INTERDIT D'UTILISATION (provoquera une erreur de l'EDL)

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

    T **list;
};

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

template <typename T>
void ArrayList<T>::Add(T *element)
{
    if (currentSize == maxSize)
    {
        DoubleSize();
    }

    list[currentSize++] = element;
} //----- Fin de Add

template <typename T>
T *ArrayList<T>::Remove(unsigned int index)
{
    T *removed = list[index];
    for (unsigned int i = index; i < currentSize - 1; i++)
    {
        list[i] = list[i + 1];
    }
    currentSize--;
    return removed;
} //---- Fin de Remove

template <typename T>
T *ArrayList<T>::Pop()
{
    return list[--currentSize];
} //----- Fin de Pop

template <typename T>
T *ArrayList<T>::Get(unsigned int index) const
{
    return list[index];
} //----- Fin de Get

template <typename T>
T *ArrayList<T>::GetLast() const
{
    return list[currentSize - 1];
} //----- Fin de GetLast

template <typename T>
bool ArrayList<T>::Contains(T *elem) const
{
    for (unsigned int i = 0; i < currentSize; i++)
        if (list[i] == elem)
            return true;

    return false;
} //----- Fin de Contains

template <typename T>
unsigned int ArrayList<T>::Size() const
{
    return currentSize;
} //----- Fin de Size

template <typename T>
bool ArrayList<T>::IsEmpty() const
{
    return Size() == 0;
} //----- Fin de IsEmpty

//-------------------------------------------- Constructeurs - destructeur

template <typename T>
ArrayList<T>::ArrayList(unsigned int startingMaxSize)
    : currentSize(0), maxSize(startingMaxSize)
{
#ifdef MAP
    cout << "Appel au constructeur de <ArrayList>" << endl;
#endif
    if (maxSize == 0)
        maxSize = 1;

    list = new T *[maxSize];
} //----- Fin de ArrayList

template <typename T>
ArrayList<T>::~ArrayList()
{
#ifdef MAP
    cout << "Appel au destructeur de <ArrayList>" << endl;
#endif
    delete[] list;
} //----- Fin de ~ArrayList

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

template <typename T>
void ArrayList<T>::DoubleSize()
{
    maxSize *= 2;
    T **oldList = list;
    list = new T *[maxSize];
    for (unsigned int i = 0; i < currentSize; i++)
    {
        list[i] = oldList[i];
    }
    delete[] oldList;
}


#endif // ARRAY_LIST_H
