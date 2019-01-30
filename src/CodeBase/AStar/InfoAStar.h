#pragma once

#include <stdlib.h>
#include <string>
#include <iostream>
#include <sstream>

#include "../Element/AElement.h"

/**
Le d�roulement correct de A* n�cessite que l'information suivante soit associ�e � tout Sommet
*/

//#define LIBRE 0
//#define OUVERT 1
//#define FERME 2

constexpr int LIBRE = 0;
constexpr int OUVERT = 1;
constexpr int FERME = 2;


class InfoAStar
{
public:
	const static char *ETATS[]; // = {"LIBRE","OUVERT","FERME"};

	AElement * pere;	// pointeur sur un Sommet<?>. o� ? est une classe compos�e ou d�riv�e de InfoStar
	int etat;			// LIBRE, OUVERT ou FERM�
	double c;			// co�t d�j� calcul�. cf. A* ou Dijkstra
	double h;			// estimation heuristique. cf. A*
	double g;			// co�t total : g = h+c

	explicit InfoAStar(AElement * pere = NULL, const int etat = LIBRE,
		const double & c = 0, const double & h = 0, const double & g = 0) :
		pere(pere), etat(etat), c(c), h(h), g(g) {}

	operator std::string() const;

	friend std::ostream & operator << (std::ostream & os, const InfoAStar & infoAStar) { return os << (std::string)infoAStar; }
};