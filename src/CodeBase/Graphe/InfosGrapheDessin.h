#pragma once

#include <iostream>
#include <sstream>
#include <string>

#include "../Math/Vecteurs2D.h"

/**

Classes VSommet et Peinture : elles sont utilisées dans TestDessinGraphe pour dessiner un graphe.


informations associée à un sommet : nom, position, couleur
sert à tester l'opération "dessiner un graphe"

VSommet comme "valeur associée à un sommet"

*/
class VSommet
{
public:
	constexpr static  int rayonDisquePixels = 10;
	constexpr static unsigned int couleurBord = 0xA10684FF; // couleur violine opaque
	std::string nom;
	Vecteur2D p;		  // position
	unsigned int couleur; // couleur au format rgba


	/**
	par défaut, la couleur d'un sommet est rouge opaque
	*/
	VSommet(const std::string & nom, const Vecteur2D & p, const unsigned int couleur = 0xFF0000FF) : nom(nom), p(p), couleur(couleur) {}

	virtual
		operator std::string () const { std::ostringstream o; o << "( " << nom << ", " << p << ", " << couleur << ")"; return o.str(); }

	friend std::ostream & operator << (std::ostream & o, const VSommet & vSommet) { return o << (std::string)vSommet; }
};

/**
Peinture  à 2 couches : informations associées à une arête pour la dessiner avec des dégradés de couleur
sert à tester l'opération "dessiner un graphe"

*/
class Peinture
{
public:
	unsigned int fond;		// couleur du fond (ou sous-couche de peinture)
	unsigned int devant;	// couleur masquant  la couleur du fond. ou dernière couche de peinture.
							// Elle masque pas du tout, partiellement ou entièrement la couleur du fond
	Peinture(const unsigned int couleurFond, const unsigned int couleurDevant) : fond(couleurFond), devant(couleurDevant) {}

	virtual operator std::string () const { 
		std::ostringstream o; 
		o << "( " << fond << ", " << devant << ")"; 
		return o.str(); 
	}

	friend std::ostream & operator << (std::ostream & o, const Peinture & peinture) { 
		return o << (std::string)peinture; 
	}
};