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
#include "src/core/Models/Path.hpp"
#include <memory>

// --------------------------------------------------
// interface files define entry points of the library
// --------------------------------------------------

std::vector<std::shared_ptr<Point>> searchPlace(std::string naturalQuery);
std::shared_ptr<Path> searchFastest(long startPointId, long endPointId);
std::shared_ptr<Path> searchShortest(long startPointId, long endPointId);
std::shared_ptr<Path> searchNearestPlace(double latitude, double longitude);

