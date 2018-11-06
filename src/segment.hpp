//
//  segment.hpp
//  libgps
//
//  Created by Thomas Lemaire on 06/11/2018.
//  Copyright © 2018 Thomas Lemaire. All rights reserved.
//

#ifndef segment_hpp
#define segment_hpp

#include <stdio.h>
#include <vector>

using namespace std;

class Segment {
    void init();
public:
    double getLenght();
    vector<double> getStart();
    vector<double> getEnd();
};

#endif /* segment_hpp */

