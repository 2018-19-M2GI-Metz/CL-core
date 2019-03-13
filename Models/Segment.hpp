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
#include "Model.hpp"
#include "Point.hpp"

class Segment : public Model {
public:
    Segment(int id, int startPointId, int endPointId, int distance, int time);
    static Segment from(row row);
    
    double getDistance();
    Point* startPoint();
    Point* endPoint();
private:
    int id;
    int startPointId;
    int endPointId;
    int distance;
    int time;
    std::string tableName = "segment";

};


