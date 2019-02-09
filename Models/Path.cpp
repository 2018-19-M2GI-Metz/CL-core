//
//  path.cpp
//  libgps
//
//  Created by Thomas Lemaire on 06/11/2018.
//  Copyright © 2018 Thomas Lemaire. All rights reserved.
//

#include "Path.hpp"

double Path::getLenght() {
    double length = 0;
    std::vector<Segment> segments = this->getSegments();
    for (int i = 0; i < segments.size(); i++) {
        length += segments[i].getLenght();
    }
    return length;
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
