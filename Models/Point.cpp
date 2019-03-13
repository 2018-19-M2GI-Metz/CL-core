//
//  Point.cpp
//  libgps
//
//  Created by Thomas Lemaire on 27/11/2018.
//  Copyright © 2018 Thomas Lemaire. All rights reserved.
//

#include "Point.hpp"

Point::Point(int id, std::string name, std::string address, double latitude, double longitude) {
    this->id = id;
    this->name = name;
    this->address = address;
    this->latitude = latitude;
    this->longitude = longitude;
}

Point Point::from(row row) {
    return Point(atoi(row.at(0).c_str()), row.at(1), row.at(2), std::stod(row.at(3).c_str()), std::stod(row.at(4).c_str()));
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

void save () {

}
