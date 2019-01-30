#include <iostream>
#include <utility>

template <class S, class T>
std::ostream & operator << (std::ostream & os, const std::pair<S*, T*> & paire)
{
	return os << "(" << *(paire.first) << ", " << *(paire.second) << ")";
}