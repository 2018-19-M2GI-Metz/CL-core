#pragma once

#include <string>
#include <iostream>
#include <sstream>

/**
Information associ�e � une ar�te  (segment rectiligne) joignant 2 lieux d'une carte routi�re.
On ne stocke que le c�ut de l'ar�te, c-�-d sa longueur et sa couleur
*/


class InfoArete
{
public:

	double cout1;
	unsigned int couleur;

	/**
	Par d�faut, la couleur d'une ar�te est le bleu
	*/
	explicit InfoArete(const double & cout1, const unsigned int couleur = 0x0000FFFF) :cout1(cout1), couleur(couleur) {}

	operator std::string() const;
	friend std::ostream & operator << (std::ostream & os, const InfoArete & infoArete) { return os << (std::string)infoArete; }
};

inline InfoArete::operator std::string() const
{
	std::ostringstream oss;
	oss << "co�t = " << cout1 << ", " << couleur;
	return oss.str();
}