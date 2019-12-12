// /*************************************************************************
//                            ArrayList  -  description
//                              -------------------
//     début                : 2019-11-19
//     copyright            : (C) 2019 BERTHOMET Guillaume & FORLER Corentin
//     e-mail               : guillaume.berthomet@insa-lyon.fr
//                            corentin.forler@insa-lyon.fr
// *************************************************************************/
//
// //---- Réalisation de la classe <ArrayList> (fichier ArrayList.cpp) ------
//
// //---------------------------------------------------------------- INCLUDE
//
// //-------------------------------------------------------- Include système
// #include <iostream>
// using namespace std;
//
// //------------------------------------------------------ Include personnel
// #include "ArrayList.h"
// #include "Trip.h"
//
// //----------------------------------------------------------------- PUBLIC
//
// //----------------------------------------------------- Méthodes publiques
// void ArrayList::Add(Trip *element)
// {
//     if (currentSize == maxSize)
//     {
//         DoubleSize();
//     }
//
//     list[currentSize++] = element;
// } //----- Fin de Add
//
// Trip *ArrayList::Remove(unsigned int index)
// {
//     Trip *removed = list[index];
//     for (unsigned int i = index; i < currentSize - 1; i++)
//     {
//         list[i] = list[i + 1];
//     }
//     currentSize--;
//     return removed;
// } //---- Fin de Remove
//
// Trip *ArrayList::Pop()
// {
//     return list[--currentSize];
// } //----- Fin de Pop
//
// Trip *ArrayList::Get(unsigned int index) const
// {
//     return list[index];
// } //----- Fin de Get
//
// Trip *ArrayList::GetLast() const
// {
//     return list[currentSize - 1];
// } //----- Fin de GetLast
//
// bool ArrayList::Contains(Trip *trip) const
// {
//     for (unsigned int i = 0; i < currentSize; i++)
//         if (list[i] == trip)
//             return true;
//
//     return false;
// } //----- Fin de Contains
//
// unsigned int ArrayList::Size() const
// {
//     return currentSize;
// } //----- Fin de Size
//
// bool ArrayList::IsEmpty() const
// {
//     return Size() == 0;
// } //----- Fin de IsEmpty
//
// //-------------------------------------------- Constructeurs - destructeur
//
// ArrayList::ArrayList(unsigned int startingMaxSize)
//     : currentSize(0), maxSize(startingMaxSize)
// {
// #ifdef MAP
//     cout << "Appel au constructeur de <ArrayList>" << endl;
// #endif
//     if (maxSize == 0)
//         maxSize = 1;
//
//     list = new Trip *[maxSize];
// } //----- Fin de ArrayList
//
// ArrayList::~ArrayList()
// {
// #ifdef MAP
//     cout << "Appel au destructeur de <ArrayList>" << endl;
// #endif
//     delete[] list;
// } //----- Fin de ~ArrayList
//
// //------------------------------------------------------------------ PRIVE
//
// //----------------------------------------------------- Méthodes protégées
//
// void ArrayList::DoubleSize()
// {
//     maxSize *= 2;
//     Trip **oldList = list;
//     list = new Trip *[maxSize];
//     for (unsigned int i = 0; i < currentSize; i++)
//     {
//         list[i] = oldList[i];
//     }
//     delete[] oldList;
// }
