//
//  segment.cpp
//  libgps
//
//  Created by Thomas Lemaire on 06/11/2018.
//  Copyright © 2018 Thomas Lemaire. All rights reserved.
//

#include "Segment.hpp"

using std::vector;

Segment::Segment(int id, int startPointId, int endPointId, int distance, int time) {
    this->id = id;
    this->startPointId = startPointId;
    this->endPointId = endPointId;
    this->distance = distance;
    this->time = time;
}

Segment Segment::from(row row) {
    return Segment(atoi(row.at(0).c_str()), atoi(row.at(1).c_str()), atoi(row.at(2).c_str()), atoi(row.at(3).c_str()), atoi(row.at(4).c_str()));
}

double Segment::getDistance() {
    return this->distance;
}

sharedPoint Segment::getStartPoint() {
    return Point::find(this->startPointId);
}

sharedPoint Segment::getEndPoint() {
    return Point::find(this->endPointId);
}
