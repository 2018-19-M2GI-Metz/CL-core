//
//  path.hpp
//  libgps
//
//  Created by Thomas Lemaire on 06/11/2018.
//  Copyright © 2018 Thomas Lemaire. All rights reserved.
//

#pragma once

#include <stdio.h>
#include "PathPoint.hpp"

class Path : public Model {
private:
    int id;
    bool shortest;
    bool fastest;
public:
    double getLenght();
    long segmentCount();
    bool isShortest();
    bool isFastest();
    std::vector<Segment> getSegments();
    std::vector<Point> getPoints(); // referenced points
    std::vector<PathPoint> getPathPoints(); // indexed points
};
