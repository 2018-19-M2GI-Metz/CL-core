//
//  segment.hpp
//  libgps
//
//  Created by Thomas Lemaire on 06/11/2018.
//  Copyright © 2018 Thomas Lemaire. All rights reserved.
//

#pragma once

#include <stdio.h>
#include <vector>
#include "Point.hpp"

class Segment {
public:
    Segment(int id, int startPointId, int endPointId, int distance, int time);
    static sharedSegment from(row row);
    static std::vector<sharedSegment> from(rows rows);
    static sharedSegment find(int startPointId, int endPointId);
    static void populateDB();
    
    int getDistance();
    int getTime();
    sharedPoint getStartPoint();
    sharedPoint getEndPoint();
    int getStartPointId();
    int getEndPointId();
    void save();
private:
    int id;
    int startPointId;
    int endPointId;
    int distance;
    int time;
    std::string tableName = "segment";

};


