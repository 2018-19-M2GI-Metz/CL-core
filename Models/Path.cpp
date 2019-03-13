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
    std::vector<Segment> segments = this->getSegments();
    for (int i = 0; i < segments.size(); i++) {
        length += segments[i].getDistance();
    }
    return length;
}

bool Path::isShortest()
{
	return this->shortest;
}

bool Path::isFastest()
{
	return this->fastest;
}

long Path::segmentCount() {
    return this->getSegments().size();
}

std::vector<Segment> Path::getSegments() {
    // TODO
    return std::vector<Segment>();
}

std::vector<Point> Path::getPoints() {
    // TODO
    return std::vector<Point>();
}

std::vector<PathPoint> Path::getPathPoints() {
    // TODO
    return std::vector<PathPoint>();
}
