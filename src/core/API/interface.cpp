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

std::vector<sharedPoint> searchPlace(std::string naturalQuery) {
    std::vector<std::string> parameters = std::vector<std::string>();
    parameters.push_back(naturalQuery);
    rows rows = DB::execute("SELECT id, name, address, latitude, longitude FROM point WHERE name LIKE '%' || ?1 || '%' OR address LIKE ?1", parameters);
    return Point::from(rows);
}

sharedPath searchFastest(int startPointId, int endPointId) {
    sharedPoint start = Point::find(startPointId);
    sharedPoint end = Point::find(endPointId);
    return Process::AStar(start, end);
}

sharedPath searchShortest(int startPointId, int endPointId) {
    sharedPoint start = Point::find(startPointId);
    sharedPoint end = Point::find(endPointId);
    return Process::AStar(start, end);
}

sharedPoint searchNearestPlace(double latitude, double longitude) {
    sharedPoint nearestPoint;
    double minimalDistance = -1;
    for (sharedPoint point : Point::all()) {
        double distance = point->distanceFrom(latitude, longitude);
        if (distance < minimalDistance || minimalDistance == -1) {
            nearestPoint = point;
            minimalDistance = distance;
        }
    }
    return nearestPoint;
}








