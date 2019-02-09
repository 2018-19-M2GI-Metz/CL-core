#pragma once

#include <iostream>
#include <sstream>
#include <string>

#include "../Element/GElement.h"

/**
Sommet d'un graphe en général

v est l'information associée au sommet : elle dépend de l'application du graphe
*/
template <class T>
class Sommet : public GElement<T>
{
public:
	int degre;		// Rappel : degré = nombre d'arêtes adjacentes à ce sommet
	/**
		Un sommet est toujours créé isolé (c'est-à-dire qu'il n'y a pas d'arête adjacente à ce sommet)
	*/
	Sommet(const int clef, const T & v) :GElement<T>(clef, v), degre(0) {}

	operator std::string() const;

};

template <class T>
Sommet<T>::operator std::string() const
{
	std::ostringstream oss;

	oss << "Sommet(" << '\n';
	oss << GElement<T>::operator string() << '\n';
	oss << "degré = " << degre << '\n';
	oss << ")";
	return oss.str();
}

template <class T>
std::ostream & operator << (std::ostream & os, const Sommet<T> & sommet)
{
	return os << (std::string)sommet;
}
