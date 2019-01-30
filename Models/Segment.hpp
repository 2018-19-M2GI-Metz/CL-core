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

class Segment : public Model {
    void init();
public:
    double getLenght();
    std::vector<double> getStart();
    std::vector<double> getEnd();
    void save();
};


