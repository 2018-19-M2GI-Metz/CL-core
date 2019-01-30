#pragma once

#include "AlgebreLineaire.h"
#include "../Sommet/Sommet.h"
#include "../Sommet/InfoSommet.h"
#include "../Arete/InfoArete.h"

#include "../Arete/Arete.h"

#include "../Graphe/Graphe.h"

//#include "AStarT.h"

/**
sert d'interm�diaire entre A* et une carte routi�re. D�finit pour une carte routi�re, toutes les m�thodes que
r�clame l'algo A*.
L'information inscrite dans une ar�te est une InfoArete qui contient une couleur et la longueur de l'ar�te
L'information inscrite dans un sommet est une InfoSommet qui contient 2 attributs : VSommet et InfoAStar.

Par cons�quent :

Une carte routi�re est un Graphe <InfoArete, InfoSommet >

A savoir, A* r�clame les m�thodes suivantes :

libereToutSommet(graphe) : met l'�tat de tous les sommets � LIBRE et tous les liens p�re � NULL
listeVoisins(sommet,graphe) : renvoie une liste de paires (voisin, co�t entre sommet et voisin)
pere(sommet)
etat(sommet)
c(sommet)
g(sommet)
h(sommet)
estFinal(sommet)

*/


class OutilsCarte
{
public:
	static double distance(const Sommet<InfoSommet> * s1, const Sommet<InfoSommet> * s2);
	static Arete<InfoArete, InfoSommet> *  creeArete(Sommet<InfoSommet> * sA, Sommet<InfoSommet> * sB, Graphe<InfoArete, InfoSommet> & graphe);
	static void libereToutSommet(Graphe<InfoArete, InfoSommet> & graphe);
	static double hh(const Sommet<InfoSommet> * s);
	static PElement< std::pair<Sommet<InfoSommet>*, double> > * listeVoisins(const Sommet<InfoSommet> * s, const Graphe<InfoArete, InfoSommet> & graphe);

	static Sommet<InfoSommet> *  pere(const Sommet<InfoSommet> * sommet);
	static Sommet<InfoSommet> * & pere(Sommet<InfoSommet> * sommet);
	static int & etat(Sommet<InfoSommet> * sommet);
	static double & c(Sommet<InfoSommet> * sommet);
	static double & h(Sommet<InfoSommet> * sommet);
	static double g(const Sommet<InfoSommet> * sommet);
	static double & g(Sommet<InfoSommet> * sommet);

	static bool estFinal(const Sommet<InfoSommet> * sommet);

	static Sommet<InfoSommet> * cible;
};

void libereToutSommet(Graphe<InfoArete, InfoSommet> & graphe);
PElement< std::pair<Sommet<InfoSommet>*, double> > * listeVoisins(const Sommet<InfoSommet> * s, const Graphe<InfoArete, InfoSommet> & graphe);

Sommet<InfoSommet> *  pere(const Sommet<InfoSommet> * sommet);
Sommet<InfoSommet> * & pere(Sommet<InfoSommet> * sommet);
int & etat(Sommet<InfoSommet> * sommet);
double & c(Sommet<InfoSommet> * sommet);
double & h(Sommet<InfoSommet> * sommet);
double g(const Sommet<InfoSommet> * sommet);
double & g(Sommet<InfoSommet> * sommet);

bool estFinal(const Sommet<InfoSommet> * sommet);

/**
compte le nombre de maillons de la liste cha�n�e "pere" dont le maillon de t�te est "t�te".
*/
int longueurChemin(const Sommet<InfoSommet>* tete);

const Sommet<InfoSommet> * dernierMaillon(const Sommet<InfoSommet>* tete);