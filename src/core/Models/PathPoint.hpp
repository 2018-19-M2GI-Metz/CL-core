//
//  PathPoint.hpp
//  libgps
//
//  Created by Thomas Lemaire on 09/02/2019.
//  Copyright © 2019 Thomas Lemaire. All rights reserved.
//

#pragma once

#include <stdio.h>
#include "Segment.hpp"

class Path;

class PathPoint : public Model {
public:
    PathPoint(int id, int pathId, int pointId, int index);
    static PathPoint from(row row);
    static std::vector<PathPoint> from(rows rows);
private:
    int id;
    int pathId;
    int pointId;
    int index; // index in the path
    std::string tableName = "pathPoint";
};


