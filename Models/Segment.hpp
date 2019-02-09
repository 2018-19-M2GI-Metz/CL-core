//
//  segment.hpp
//  libgps
//
//  Created by Thomas Lemaire on 06/11/2018.
//  Copyright © 2018 Thomas Lemaire. All rights reserved.
//

#pragma once

#include <stdio.h>
#include <vector>
#include "Model.hpp"
#include "Point.hpp"

class Segment : public Model {
private:
    int id;
    double lenght;
    int startPointId;
    int endPointId;
public:
    double getLenght();
    Point* start();
    Point* end();
};


