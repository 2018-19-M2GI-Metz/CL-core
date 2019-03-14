//
//  path.cpp
//  libgps
//
//  Created by Thomas Lemaire on 06/11/2018.
//  Copyright © 2018 Thomas Lemaire. All rights reserved.
//

#include "Path.hpp"

Path::Path(bool isShortest, bool isFastest) {
    this->shortest = isShortest;
    this->fastest = isFastest;
    this->distance = 0;
    this->time = 0;
}

int Path::getDistance() {
    return this->distance;
}

int Path::getTime() {
    return this->time;
}

bool Path::isShortest() {
	return this->shortest;
}

bool Path::isFastest() {
	return this->fastest;
}

int Path::segmentCount() {
    return (this->pointCount() - 1);
}

int Path::pointCount() {
    return (int)this->points.size();
}

std::vector<sharedSegment> Path::getSegments() {
    std::vector<sharedPoint> points = this->getPoints();
    std::vector<sharedSegment> segments = std::vector<sharedSegment>();
    for (int index = 0; index < (points.size() - 1); index += 1) {
        int startPointId = points[index]->getId();
        int endPointId = points[index+1]->getId();
        segments.push_back(Segment::find(startPointId, endPointId));
    }
    return segments;
}

std::vector<sharedPoint> Path::getPoints() {
    return this->points;
}

void Path::addPoint(sharedPoint point) {
    if (this->points.size() != 0) {
        sharedPoint lastPoint = this->points.back();
        sharedSegment newSegment = Segment::find(lastPoint->getId(), point->getId());
        this->distance += newSegment->getDistance();
        this->time += newSegment->getTime();
    }
    this->points.push_back(point);
}

