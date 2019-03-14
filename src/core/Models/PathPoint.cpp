//
//  PathPoint.cpp
//  libgps
//
//  Created by Thomas Lemaire on 09/02/2019.
//  Copyright © 2019 Thomas Lemaire. All rights reserved.
//

#include "PathPoint.hpp"

PathPoint::PathPoint(int id, int pathId, int pointId, int index) {
    this->id = id;
    this->pathId = pathId;
    this->pointId = pointId;
    this->index = index;
}

PathPoint PathPoint::from(row row) {
    return PathPoint(atoi(row.at(0).c_str()), atoi(row.at(1).c_str()), atoi(row.at(2).c_str()), atoi(row.at(3).c_str()));
}

std::vector<PathPoint> PathPoint::from(rows rows) {
    std::vector<PathPoint> pathPoints = std::vector<PathPoint>();
    bool firstRow = true;
    for (row row : rows) {
        if (!firstRow) {
            pathPoints.push_back(PathPoint::from(row));
        }
        firstRow = false;
    }
    return pathPoints;
}
