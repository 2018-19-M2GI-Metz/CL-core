#pragma once

#include <iostream>
#include <sstream>
#include <string>

#include "../Element/GElement.h"

/**
Sommet d'un graphe en g�n�ral

v est l'information associ�e au sommet : elle d�pend de l'application du graphe
*/
template <class T>
class Sommet : public GElement<T>
{
public:
	int degre;		// Rappel : degr� = nombre d'ar�tes adjacentes � ce sommet
	/**
		Un sommet est toujours cr�� isol� (c'est-�-dire qu'il n'y a pas d'ar�te adjacente � ce sommet)
	*/
	Sommet(const int clef, const T & v) :GElement<T>(clef, v), degre(0) {}

	operator std::string() const;

};

template <class T>
Sommet<T>::operator std::string() const
{
	std::ostringstream oss;

	oss << "Sommet(" << '\n';
	oss << GElement<T>::operator std::string() << '\n';
	oss << "degr� = " << degre << '\n';
	oss << ")";
	return oss.str();
}

template <class T>
std::ostream & operator << (std::ostream & os, const Sommet<T> & sommet)
{
	return os << (std::string)sommet;
}
