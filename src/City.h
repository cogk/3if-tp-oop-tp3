/*************************************************************************
                           City  -  description
                             -------------------
    début                : 2019-11-19
    copyright            : (C) 2019 BERTHOMET Guillaume & FORLER Corentin
    e-mail               : guillaume.berthomet@insa-lyon.fr
                           corentin.forler@insa-lyon.fr
*************************************************************************/

//--------- Interface de la classe <City> (fichier City.h) ---------------
#if !defined(CITY_H)
#define CITY_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <City>
//   Représente une ville
//------------------------------------------------------------------------

class City
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    const char *GetName() const;
    // Mode d'emploi :
    //   Renvoie le nom de la cité.
    //   Ce nom est à delete[] par l'utilisateur

    bool Equals(const City *aCity) const;
    // Mode d'emploi :
    //  Renvoie vrai si les deux villes ont le même nom, faux sinon

    //-------------------------------------------- Constructeurs - destructeur
    City(const City &aCity);
    // Mode d'emploi (constructeur de copie) : copie aCity.name dans this->name

    City(const char *cityName);
    // Mode d'emploi : Crée une ville avec cityName comme nom

    virtual ~City();
    // Mode d'emploi : Libère name

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Attributs protégés
    const char *name;
};

#endif // CITY_H
