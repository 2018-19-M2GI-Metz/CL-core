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
#include "../DAO/Model.hpp"
#include "Point.hpp"

class Segment;
typedef std::shared_ptr<Segment> sharedSegment;

class Segment : public Model {
public:
    Segment(int id, int startPointId, int endPointId, int distance, int time);
    static sharedSegment from(row row);
    static sharedSegment find(int startPointId, int endPointId);
    static void populateDB();
    
    double getDistance();
    sharedPoint getStartPoint();
    sharedPoint getEndPoint();
    void save();
private:
    int id;
    int startPointId;
    int endPointId;
    int distance;
    int time;
    std::string tableName = "segment";

};


