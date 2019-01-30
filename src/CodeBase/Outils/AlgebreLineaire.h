/*
 * AlgebreLineaire.h
 *
 *  Created on: 30 juin 2011
 *      Author: Valérie
 */

#pragma once

#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

#include "../Erreur/Erreur.h"

template <class T>
inline const T operator - (const T & u, const T & v)
{
	return u + -v;
}

/*
template <class T>
inline const T operator * (const double & a, const T & u)
{
return u * a;
}
*/

template <class T>
inline const T operator / (const T & u, const double & a)
{
	return u * (1 / a);
}

template <class T>
inline const T & operator *=(T & u, const T & v)
{
	u = u * v;

	return u;
}

template <class T>
inline const T & operator ^=(T & u, const T & v)
{
	u = u ^ v;

	return u;
}

template <class T>
inline const T & operator -= (T & u, const T & v)
{
	return u += -v;
}

template <class T>
inline const T & operator /= (T & u, const double & a)
{
	return u *= (1 / a);
}

template <class T>
inline double norme(const T & u)
{
	return sqrt(u*u);
}

template <class T>
inline double cos(const T & u1, const T & u2) { return (u1*u2) / (norme(u1)*norme(u2)); }


template <class T>
inline double norme2(const T & u)
{
	return (u*u);
}


template <class T>
inline bool operator != (const T & u, const T & v)
{
	return !(u == v);
}


/**
 * calcul de 1/x
 *
 * à l'aide de la relation :
 *
 * 1/(1-a) = 1 + a + a^2 + a^3 + .....
 *
 * ATTENTION : pour assurer la cvgence, il faut que à partir d'un certain rang on ait |a| < 1
 * l'idéal est donc que |1-x| <<1. Lance une Erreur si ne cvge pas
 *
 * DONNEES : x, unité : élément neutre pour la multiplication
 *
 * RESULTATS : 1/x
 *
 * */
template <class T>
const T inverse(const T & x, const T & unite = (T)1, const double & EPS = 1.0e-6)
{

	T a(unite - x);

	//Erreur::testePlusPetitOuEgal( norme(a), 1-EPS, "Dans AlgebreLineaire.h : calcul de l'inverse de x : on n'a pas |1-x| < 1 !!");

	double n, n1; // norme courante, norme précédente
	T s, u;

	s = u = unite; n = norme(u);
	do
	{
		u *= a;
		s += u;
		n1 = n; n = norme(u);

		if (n1 <= n) throw Erreur("Dans AlgebreLineaire.h : calcul de l'inverse de x : on a |Ui-1| <= |Ui| !!!");

	} while (n > EPS);


	return s;
}


/*
 * Définit un couple de valeurs où les 2 valeurs ne sont pas forcément de même nature
 *
 * */
template < class S, class T>
class Paire
{
public:
	S x; T y;
	Paire(const S & x = (S)0, const T & y = (T)-1) : x(x), y(y) {}

	virtual operator std::string () const { 
		std::ostringstream o; 
		o << "( " << x << ", " << y << ")"; 
		return o.str();
	}

	friend std::ostream & operator << (std::ostream & o, const Paire<S, T> & paire) { return o << (std::string)paire; }
};


/**
 * opérateur :
 *
 * template <class S, class T>
 * inline istream & operator >> ( istream & is,  Paire<S,T> & paire)
 *
 * cf. ChainesCar.h
 * */
template <class S, class T>
class CreateurPaire
{
public:
	const Paire<S, T> operator() (const S & s, const T & t) const { return f(s, t); }
	const Paire<S, T> f(const S & s, const T & t) const { return Paire<S, T>(s, t); }
};


template <class G, class D>
class ProjecteurGauchePaire
{
public:
	const G f(const Paire<G, D> & t) const { return t.x; }
	const G operator() (const Paire<G, D> & t) const { return f(t); }
};


template <class G, class D>
class ProjecteurDroitPaire
{
public:
	const D f(const Paire<G, D> & t) const { return t.y; }
	const D operator() (const Paire<G, D> & t) const { return f(t); }
};

/**
 * permet de comparer 2 paires suivant la composante x.
 *
 * La comparaison est définie par le paramètre comparateur supposé être un foncteur de comparaison qui sait comparer deux objets instances de la classe G
 *
 * */
template <class G, class D, class FONCTEUR>
class ComparateurGauchePaire
{
public:
	FONCTEUR comparateur;

	explicit ComparateurGauchePaire(const FONCTEUR & comparateur) : comparateur(comparateur) {}

	bool comparaison(const Paire<G, D> & t1, const Paire<G, D> & t2) const { return comparateur(t1.x, t2.x); }
	bool  operator() (const Paire<G, D> & t1, const Paire<G, D> & t2) const { return comparaison(t1, t2); }
};



/*
template <class T>
inline ostream & operator << (ostream & os, const T & x) { return os << (string) x;}
*/