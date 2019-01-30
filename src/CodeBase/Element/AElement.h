#pragma once
#include <iostream>
#include <string>
#include <sstream>

/**
	Repr�sente la classe de base des �l�ments d'un graphe qui peuvent �tre des sommets ou des ar�tes.

	A ce niveau, on ne peut que d�finir que la clef d'un �l�ment inscrite dans cet �l�ment.

	En effet tout �l�ment d'un graphe est tout d'abord d�fini par une clef (c-�-d une valeur non nulle et unique)
*/

class AElement
{
public:
	int clef;

	explicit AElement(const int clef) : clef(clef) {}
	operator std::string() const { std::ostringstream o; o << "clef = " << clef; return o.str(); }

	friend std::ostream & operator << (std::ostream & os, const AElement& aElement) { return os << (std::string)aElement; }
};
