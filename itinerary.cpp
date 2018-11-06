//
//  itinerary.cpp
//  libgps
//
//  Created by Thomas Lemaire on 06/11/2018.
//  Copyright © 2018 Thomas Lemaire. All rights reserved.
//

#include "itinerary.hpp"

double Itinerary::getLenght() {
    double length = 0;
    vector<Segment> segments = this->getSegments();
    for (int i = 0; i < segments.size(); i++) {
        length += segments[i].getLenght();
    }
    return length;
}

long Itinerary::segmentCount() {
    return this->getSegments().size();
}

vector<double> Itinerary::getStart() {
    return this->getSegments()[0].getStart();
}

vector<double> Itinerary::getEnd() {
    return this->getSegments()[this->segmentCount() - 1].getEnd();
}
