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

// ONLY FOR INSERT AT THIS TIME
void Segment::save() {
    std::vector<std::string> parameters = std::vector<std::string>();
    parameters.push_back(std::to_string(this->startPointId));
    parameters.push_back(std::to_string(this->endPointId));
    parameters.push_back(std::to_string(this->distance));
    parameters.push_back(std::to_string(this->time));
    DB::execute("INSERT INTO segment (startPointId, endPointId, distance, time) VALUES (?2, ?3, ?4, ?5)", parameters);
}

void Segment::populateDB() {
    std::vector<sharedPoint> points = Point::all();
    int pointCount = int(points.size());
    int startPointIndex = 0;
    int endPointIndex = 1;
    int segmentId = 0;
    int connexionCountOfPoint = 0;
    int currentPercent = 0;
    sharedPoint startPoint = points[startPointIndex];
    sharedPoint endPoint = points[endPointIndex];
    
    while (startPointIndex != pointCount - 2) {
        
        // Test
        
        int distance = int(startPoint->distanceFrom(*endPoint));
        if (distance < 5) {
            sharedSegment segment = std::make_shared<Segment>(Segment(segmentId, startPoint->getId(), endPoint->getId(), distance, distance));
            segment->save();
            segmentId += 1;
            connexionCountOfPoint += 1;
        }
        
        // Increment
        
        if (endPointIndex == pointCount - 1 || connexionCountOfPoint == 3) {
            startPointIndex += 1;
            endPointIndex = startPointIndex + 1;
            startPoint = points[startPointIndex];
            endPoint = points[endPointIndex];
            
            int percent = int(ceil(100 * ((double)startPointIndex / (double)pointCount)));
            if (percent % 5 == 0 && percent != currentPercent) {
                currentPercent = percent;
                std::cout << "\r" << percent << "%";
            }
        }
        else {
            endPointIndex += 1;
            endPoint = points[endPointIndex];
        }
    }
    
    std::cout << std::endl << "created " << segmentId << " routes";
}

