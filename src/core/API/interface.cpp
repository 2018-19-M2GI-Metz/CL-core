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

std::vector<std::shared_ptr<Point>> searchPlace(std::string naturalQuery) {
    std::shared_ptr<Point> p1 = Point::find(1);
    std::shared_ptr<Point> p2 = Point::find(2);
    std::vector<std::shared_ptr<Point>> vector = std::vector<std::shared_ptr<Point>>();
    vector.push_back(p1);
    vector.push_back(p2);
    return vector;
}

std::shared_ptr<Path> searchFastest(long startPointId, long endPointId) {
    Path p = Path(4, true, false, 1000, 1300);
    return std::make_shared<Path>(p);
}

std::shared_ptr<Path> searchShortest(long startPointId, long endPointId) {
    Path p = Path(4, true, false, 1000, 1300);
    return std::make_shared<Path>(p);
    
}

std::shared_ptr<Path> searchNearestPlace(double latitude, double longitude) {
    Path p = Path(4, true, false, 1000, 1300);
    return std::make_shared<Path>(p);
}








