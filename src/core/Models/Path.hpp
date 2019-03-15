//
//  path.hpp
//  libgps
//
//  Created by Thomas Lemaire on 06/11/2018.
//  Copyright © 2018 Thomas Lemaire. All rights reserved.
//

#pragma once

#include <stdio.h>
#include "Segment.hpp"

class Path;
typedef std::shared_ptr<Path> sharedPath;

class Path {
public:
    Path(bool isShortest, bool isFastest);
    int getDistance();
    int getTime();
    int segmentCount();
    int pointCount();
    bool isShortest();
    bool isFastest();
    std::vector<sharedSegment> getSegments();
    std::vector<sharedPoint> getPoints();
    
    void addPoint(sharedPoint point);
private:
    bool shortest;
    bool fastest;
    int distance;
    int time;
    std::vector<sharedPoint> points;
};
