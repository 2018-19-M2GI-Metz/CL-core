#pragma once

#include <iostream>
#include <sstream>
#include <string>

#include "../Element/GElement.h"


template <class T> class Sommet : public GElement<T> {
public:
	int degre;
	Sommet(const int clef, const T & v) :GElement<T>(clef, v), degre(0) {}

	operator std::string() const;
};
