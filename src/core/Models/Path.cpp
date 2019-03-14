//
//  path.cpp
//  libgps
//
//  Created by Thomas Lemaire on 06/11/2018.
//  Copyright © 2018 Thomas Lemaire. All rights reserved.
//

#include "Path.hpp"

Path::Path(int id, bool isShortest, bool isFastest, int distance, int time) {
    this->id = id;
    this->shortest = isShortest;
    this->fastest = isFastest;
    this->distance = distance;
    this->time = time;
}

Path Path::from(row row) {
    return Path(atoi(row.at(0).c_str()), atoi(row.at(1).c_str()) == 1, atoi(row.at(2).c_str()) == 1, atoi(row.at(3).c_str()), atoi(row.at(4).c_str()));
}

double Path::getLenght() {
    double length = 0;
    std::vector<sharedSegment> segments = this->getSegments();
    for (int i = 0; i < segments.size(); i++) {
        length += segments[i]->getDistance();
    }
    return length;
}

bool Path::isShortest() {
	return this->shortest;
}

bool Path::isFastest() {
	return this->fastest;
}

long Path::segmentCount() {
    return this->getSegments().size();
}

std::vector<sharedSegment> Path::getSegments() {
    std::vector<sharedPoint> points = this->getPoints();
    std::vector<sharedSegment> segments = std::vector<sharedSegment>();

    for (int index = 0; index < (points.size() - 1); index += 1) {
        int startPointId = points[index]->getId();
        int endPointId = points[index]->getId();
        segments.push_back(Segment::find(startPointId, endPointId));
    }
    
    return segments;
}

std::vector<sharedPoint> Path::getPoints() {
    rows rows = DB::execute("SELECT point.id, point.name, point.address, point.latitude, point.longitude FROM point INNER JOIN pathPoint ON (point.id = pathPoint.pointId) WHERE pathId = ?1 ORDER BY pathPoint.index", std::vector<std::string>({std::to_string(this->id)}));
    return Point::from(rows);
}

std::vector<PathPoint> Path::getPathPoints() {
    rows rows = DB::execute("SELECT id, pathId, pointId, index FROM pathPoint WHERE pathId = ?1 ORDER BY index", std::vector<std::string>({std::to_string(this->id)}));
    return PathPoint::from(rows);
}
