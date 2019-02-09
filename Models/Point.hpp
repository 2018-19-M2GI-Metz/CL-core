//
//  Point.hpp
//  libgps
//
//  Created by Thomas Lemaire on 27/11/2018.
//  Copyright © 2018 Thomas Lemaire. All rights reserved.
//

#pragma once

#include <stdio.h>
#include "Model.hpp"

class Point : public Model {
private:
    int id;
    std::string name;
    std::string address;
    double latitude;
    double longitude;
public:
    std::string getName();
    std::string getAddress();
    double getLatitude();
    double getLongitude();
};

