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
#include <map>

class Point;
typedef std::shared_ptr<Point> sharedPoint;

class Point : public Model {
public:
    static sharedPoint from(row row);
    static std::vector<sharedPoint> from(rows rows);
    static std::vector<sharedPoint> all();
    static sharedPoint find(int id);

    int getId();
    std::string getName();
    std::string getAddress();
    double getLatitude();
    double getLongitude();
    double distanceFrom(Point point);
    double distanceFrom(double latitude, double longitude);
private:
    Point(int id, std::string name, std::string address, double latitude, double longitude);

    static std::map<int, std::weak_ptr<Point>> loadedPoints;

    int id;
    std::string name;
    std::string address;
    double latitude;
    double longitude;
    std::string tableName = "point";
};

