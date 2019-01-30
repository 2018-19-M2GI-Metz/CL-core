#pragma once
#include "../Graphe/InfosGrapheDessin.h"
#include "../AStar/InfoAStar.h"

/**
	Information associée à un lieu (donc un sommet) d'une carte géographique pour laquelle on veut faire "tourner" A*
*/

class InfoSommet
{
public:
	VSommet vSommet;
	InfoAStar infoAStar;

	InfoSommet(const VSommet & vSommet, const InfoAStar & infoAStar) : vSommet(vSommet), infoAStar(infoAStar) {}

	operator std::string() const { 
		std::ostringstream oss; 
		oss << vSommet << '\n'; 
		oss << infoAStar;
		return oss.str(); 
	}

	friend std::ostream & operator <<(std::ostream & os, const InfoSommet & infoSommet) { return os << (std::string)infoSommet; }
};


