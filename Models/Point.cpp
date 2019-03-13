//
//  Point.cpp
//  libgps
//
//  Created by Thomas Lemaire on 27/11/2018.
//  Copyright © 2018 Thomas Lemaire. All rights reserved.
//

#include "Point.hpp"

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
