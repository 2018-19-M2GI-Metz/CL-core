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
    return std::vector<std::unique_ptr<Point>>();
}

std::unique_ptr<Path> searchFastest(long startPointId, long endPointId) {
    return std::unique_ptr<Path>();
}

std::unique_ptr<Path> searchShortest(long startPointId, long endPointId) {
    return std::unique_ptr<Path>();
}

std::unique_ptr<Path> searchNearestPlace(double latitude, double longitude) {
    return std::unique_ptr<Path>();
}






