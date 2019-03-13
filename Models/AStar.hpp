#pragma once
//
//  astar.hpp
//  libgps
//
//  Created by Ronan Rizzardi on 13/03/2019.
//  Copyright © 2019 Ronan Rizzardi. All rights reserved.
//
#include "Point.hpp"
#include "Path.hpp"



class AStarT
{
public:

	class Node//un node est un point dans un graphe
	{
	public:

		Node *parent;
		int longitude;//
		int latitude;//à récup sur les points
		double coutG; // coût final -> H+F
		double coutH; // coût heuristique
		double coutF; // coût déjà calculé

	};

	static bool isDestination(Point* dep, Point* dest) {
		if (dep->getLongitude() == dest->getLongitude() && dep->getLatitude() == dest->getLatitude()) {
			return true;
		}
		return false;
	}

	static double calculateH(Point* dep, Point* dest) {
		double H = (sqrt((dep->getLongitude() - dest->getLongitude())*(dep->getLongitude() - dest->getLongitude())
			+ (dep->getLatitude() - dest->getLatitude())*(dep->getLatitude() - dest->getLatitude())));
		return H;
	}

	static Path aStar(Point* dep, Point* dest) {
		Path res;

		if (isDestination(dep, dest) == true){
			return res;//il est vide
		}

		/*while(ouverts)
			Point* point;
			
		*/
	}
};
