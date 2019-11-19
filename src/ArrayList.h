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

//------------------------------------------------------------- Constantes
const unsigned int DEFAULT_SIZE = 5;

//------------------------------------------------------------------------
// Rôle de la classe <ArrayList>
//  ArrayList permet de stocker une liste de taille variable d'éléments de
//  types inconnus
//------------------------------------------------------------------------

class ArrayList
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    void Add(void * element);

    void *Get(unsigned int index) const;
    // Contrat : index < this->Size()

    unsigned int Size() const;
    // Mode d'emploi :
    //  Retourne la taille actuellement utilisée la liste

    //-------------------------------------------- Constructeurs - destructeur
    ArrayList(const ArrayList &anArrayList);
    // Mode d'emploi (constructeur de copie) :
    //  Copie le contenu de anArrayList.list dans this->list (!= copier
    // anArrayList.list comme un pointeur) ainsi que anArrayList.maxSize

    ArrayList(unsigned int startingMaxSize = DEFAULT_SIZE);
    // Mode d'emploi : maxSize indique la taille que la liste allouera pour
    //   stocker ses éléments (qui pourra varier si besoin)
    // Contrat : maxSize >= 1

    virtual ~ArrayList();

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées
    void DoubleSize();
    // Mode d'emploi : double la taille actuellement allouée à la list

    //----------------------------------------------------- Attributs protégés
    unsigned int currentSize;
    unsigned int maxSize;

    void **list;
};

#endif // ARRAY_LIST_H
