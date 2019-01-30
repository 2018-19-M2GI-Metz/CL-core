//
//  itinerary.cpp
//  libgps
//
//  Created by Thomas Lemaire on 06/11/2018.
//  Copyright © 2018 Thomas Lemaire. All rights reserved.
//

#include "Itinerary.hpp"

using std::vector;

double Itinerary::getLenght() {
    double length = 0;
    vector<Segment> segments = getSegments();
    for (int i = 0; i < segments.size(); i++) {
        length += segments[i].getLenght();
    }
    return length;
}

long Itinerary::segmentCount() {
    return getSegments().size();
}

vector<double> Itinerary::getStart() {
    return getSegments()[0].getStart();
}

vector<double> Itinerary::getEnd() {
    return getSegments()[this->segmentCount() - 1].getEnd();
}

vector<Segment> Itinerary::getSegments() {
    return vector<Segment> {};
}
