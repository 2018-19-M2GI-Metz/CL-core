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

sharedSegment Segment::from(row row) {
    Segment segment = Segment(atoi(row.at(0).c_str()), atoi(row.at(1).c_str()), atoi(row.at(2).c_str()), atoi(row.at(3).c_str()), atoi(row.at(4).c_str()));
    return std::make_shared<Segment>(segment);
}

sharedSegment Segment::find(int startPointId, int endPointId) {
    std::vector<std::string> parameters = std::vector<std::string>();
    parameters.push_back(std::to_string(startPointId));
    parameters.push_back(std::to_string(endPointId));
    
    rows rows = DB::execute("SELECT id, startPointId, endPointId, distance, time FROM semgent WHERE (startPointId = ?1 AND endPointId = ?2) OR (endPointId = ?2 AND startPointId = ?1)");
    sharedSegment result = sharedSegment();
    if (rows.size() > 1) {
        result = Segment::from(rows[1]);
    }
    return result;
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
