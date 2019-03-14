//
//  Point.hpp
//  libgps
//
//  Created by Thomas Lemaire on 27/11/2018.
//  Copyright © 2018 Thomas Lemaire. All rights reserved.
//

#pragma once

#ifndef PI
#define PI 3.14159265358979323846
#endif

#include <stdio.h>
#include <math.h>
#include "../DAO/Model.hpp"
#include <memory>

class Point : public Model {
public:
    Point(int id, std::string name, std::string address, double latitude, double longitude);
    static std::shared_ptr<Point> from(row row);
    static std::shared_ptr<Point> find(int id);
    
    std::string getName();
    std::string getAddress();
    double getLatitude();
    double getLongitude();
    double distanceFrom(Point point);

private:
    int id;
    std::string name;
    std::string address;
    double latitude;
    double longitude;
    std::string tableName = "point";
};

