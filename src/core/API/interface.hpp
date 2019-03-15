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
#include "../Models/Path.hpp"
#include "../Interfaces/Process.hpp"
#include <memory>

// --------------------------------------------------
// interface files define entry points of the library
// --------------------------------------------------

std::vector<sharedPoint> searchPlace(std::string naturalQuery);
sharedPath searchFastest(int startPointId, int endPointId);
sharedPath searchShortest(int startPointId, int endPointId);
sharedPoint searchNearestPlace(double latitude, double longitude);

