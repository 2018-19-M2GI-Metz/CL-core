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
public:
    Path(int id, bool isShortest, bool isFastest, int distance, int time);
    static Path from(row row);
    
    double getLenght();
    long segmentCount();
    bool isShortest();
    bool isFastest();
    std::vector<sharedSegment> getSegments();
    std::vector<sharedPoint> getPoints(); // referenced points
    std::vector<PathPoint> getPathPoints(); // indexed points
private:
    int id;
    bool shortest;
    bool fastest;
    int distance;
    int time;
    std::string tableName = "path";
};
