//
//  itinerary.hpp
//  libgps
//
//  Created by Thomas Lemaire on 06/11/2018.
//  Copyright © 2018 Thomas Lemaire. All rights reserved.
//

#pragma once

#include <stdio.h>

#include "Segment.hpp"

class Itinerary : public Model {
    void init();
public:
    double getLenght();
    long segmentCount();
    std::vector<Segment> getSegments();
    std::vector<double> getStart();
    std::vector<double> getEnd();
};
