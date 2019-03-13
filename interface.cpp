//
//  interface.cpp
//  libgps
//
//  Created by Thomas Lemaire on 06/11/2018.
//  Copyright © 2018 Thomas Lemaire. All rights reserved.
//

// --------------------------------------------------
// interface files define entry points of the library
// --------------------------------------------------


#include "interface.hpp"

std::vector<std::unique_ptr<Point>> searchPlace(std::string naturalQuery) {
    Point p1 = Point(1, "Raclette", "Hakuna Matata", 64, 24);
    Point p2 = Point(2, "Salami", "Le lac !.. du conemaraaaaa", 64, 24);
    std::vector<std::unique_ptr<Point>> vector = std::vector<std::unique_ptr<Point>>();
    vector.push_back(std::make_unique<Point>(p1));
    vector.push_back(std::make_unique<Point>(p2));
    return vector;
}

std::unique_ptr<Path> searchFastest(long startPointId, long endPointId) {
    Path p = Path(4, true, false, 1000, 1300);
    return std::make_unique<Path>(p);
}

std::unique_ptr<Path> searchShortest(long startPointId, long endPointId) {
    Path p = Path(4, true, false, 1000, 1300);
    return std::make_unique<Path>(p);
    
}

std::unique_ptr<Path> searchNearestPlace(double latitude, double longitude) {
    Path p = Path(4, true, false, 1000, 1300);
    return std::make_unique<Path>(p);
    
}








