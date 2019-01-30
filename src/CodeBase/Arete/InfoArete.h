#pragma once

#include <string>
#include <iostream>
#include <sstream>

/**
Information associée à une arête  (segment rectiligne) joignant 2 lieux d'une carte routière.
On ne stocke que le côut de l'arête, c-à-d sa longueur et sa couleur
*/


class InfoArete
{
public:

	double cout1;
	unsigned int couleur;

	/**
	Par défaut, la couleur d'une arête est le bleu
	*/
	explicit InfoArete(const double & cout1, const unsigned int couleur = 0x0000FFFF) :cout1(cout1), couleur(couleur) {}

	operator std::string() const;
	friend std::ostream & operator << (std::ostream & os, const InfoArete & infoArete) { return os << (std::string)infoArete; }
};

inline InfoArete::operator std::string() const
{
	std::ostringstream oss;
	oss << "coût = " << cout1 << ", " << couleur;
	return oss.str();
}