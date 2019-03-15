//
//  Process.hpp
//  libgps
//
//  Created by Thomas Lemaire on 14/03/2019.
//  Copyright © 2019 Thomas Lemaire. All rights reserved.
//

#ifndef Process_hpp
#define Process_hpp

#include <stdio.h>
#include "../Models/Path.hpp"

class Process {
public:
    static sharedPath AStar(sharedPoint start, sharedPoint end);
};

#endif /* Process_hpp */
