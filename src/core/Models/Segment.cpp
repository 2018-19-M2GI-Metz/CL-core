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
    DB::execute("INSERT INTO segment (startPointId, endPointId, distance, time) VALUES (?1, ?2, ?3, ?4)", parameters);
}

void Segment::populateDB() {
    int maxDistance = 20000;
    int maxConnexion = 3;
    std::vector<sharedPoint> points = Point::all();
    int pointCount = int(points.size());
    int startPointIndex = 0;
    int endPointIndex = 1;
    int segmentCount = 0;
    int connexionCountOfPoint = 0;
    int currentPercent = 0;
    sharedPoint startPoint = points[startPointIndex];
    sharedPoint endPoint = points[endPointIndex];
    
    std::cout << std::endl << "Populating database with segments.. [maxDistance = " << maxDistance << "m, maxConnexion = " << maxConnexion << "]" << std::endl << "0%";
    
    while (startPointIndex != pointCount - 2) {
        
        // Test
        
        int distance = int(startPoint->distanceFrom(*endPoint));
        if (distance < maxDistance) {
            sharedSegment segment = std::make_shared<Segment>(Segment(0, startPoint->getId(), endPoint->getId(), distance, distance));
            segment->save();
            segmentCount += 1;
            connexionCountOfPoint += 1;
        }
        
        // Increment
        
        if (endPointIndex == pointCount - 1 || connexionCountOfPoint >= maxConnexion) {
            startPointIndex += 1;
            endPointIndex = startPointIndex + 1;
            startPoint = points[startPointIndex];
            endPoint = points[endPointIndex];
            connexionCountOfPoint = 0;
            
            int percent = int(ceil(100 * ((double)startPointIndex / (double)pointCount)));
            if (percent % 5 == 0 && percent != currentPercent) {
                currentPercent = percent;
                std::cout << " " << percent << "%";
            }
        }
        else {
            endPointIndex += 1;
            endPoint = points[endPointIndex];
        }
    }
    
    std::cout << std::endl << std::endl << "created " << segmentCount << " routes";
}

