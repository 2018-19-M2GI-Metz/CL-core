//
//  itinerary.hpp
//  libgps
//
//  Created by Thomas Lemaire on 06/11/2018.
//  Copyright © 2018 Thomas Lemaire. All rights reserved.
//

#ifndef itinerary_hpp
#define itinerary_hpp

#include <stdio.h>
#include <vector>

#include "segment.hpp"

class Itinerary {
    void init();
public:
    double getLenght();
    long segmentCount();
    vector<Segment> getSegments();
    vector<double> getStart();
    vector<double> getEnd();
};

#endif /* itinerary_hpp */
