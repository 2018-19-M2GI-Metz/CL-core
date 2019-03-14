//
//  Point.cpp
//  libgps
//
//  Created by Thomas Lemaire on 27/11/2018.
//  Copyright © 2018 Thomas Lemaire. All rights reserved.
//

#include "Point.hpp"

std::map<int, std::weak_ptr<Point>> Point::loadedPoints = std::map<int, std::weak_ptr<Point>>();

Point::Point(int id, std::string name, std::string address, double latitude, double longitude) {
    this->id = id;
    this->name = name;
    this->address = address;
    this->latitude = latitude;
    this->longitude = longitude;
}

std::shared_ptr<Point> Point::from(row row) {
    Point point = Point(atoi(row.at(0).c_str()), row.at(1), row.at(2), std::stod(row.at(3).c_str()), std::stod(row.at(4).c_str()));
    auto shared = std::make_shared<Point>(point);
    std::weak_ptr<Point> weak = shared;
    Point::loadedPoints[point.id] = weak;
    return shared;
}

sharedPoint Point::find(int id) {
    if (Point::loadedPoints.find(id) != Point::loadedPoints.end() && !Point::loadedPoints.at(id).expired()) {
        sharedPoint point = Point::loadedPoints[id].lock();
        return point;
    }
    else {
        rows rows = DB::execute("SELECT id, name, address, latitude, longitude FROM point WHERE id = ?");
        return Point::from(rows.at(1));
    }
}

int Point::getId() {
    return this->id;
}

std::string Point::getName() {
    return this->name;
}

std::string Point::getAddress() {
    return this->address;
}

double Point::getLatitude() {
    return this->latitude;
}

double Point::getLongitude() {
    return this->longitude;
}

double Point::distanceFrom(Point point) {
    double earthRadius = 6378000;
    double lat_a = (PI * this->latitude) / 180;
    double lon_a = (PI * this->longitude) / 180;
    double lat_b = (PI * point.latitude) / 180;
    double lon_b = (PI * point.longitude) / 180;
    double distance = earthRadius * (PI/2 - asin(sin(lat_b) * sin(lat_a) + cos(lon_b - lon_a) * cos(lat_b) * cos(lat_a)));
    return distance;
}
