//
//  interface.hpp
//  libgps
//
//  Created by Thomas Lemaire on 06/11/2018.
//  Copyright © 2018 Thomas Lemaire. All rights reserved.
//

#pragma once

#include <stdio.h>
#include <vector>
#include "Models/Path.hpp"

// --------------------------------------------------
// interface files define entry points of the library
// --------------------------------------------------

std::vector<Point> searchPlace(std::string naturalQuery);
Path searchFastest(Point start, Point end);
Path searchShortest(Point start, Point end);
Path searchNearestPlace(double latitude, double longitude);

