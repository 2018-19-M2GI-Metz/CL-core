//
//  main.cpp
//  libgps
//
//  Created by Thomas Lemaire on 06/11/2018.
//  Copyright © 2018 Thomas Lemaire. All rights reserved.
//

#include <iostream>
#include "DB.hpp"
#include "Models/Path.hpp"

using std::cout;

int main(int argc, char** argv) {
    DB::load();
    
    // DB usage example
    rows rows = DB::execute("SELECT * FROM point");
    for(row row : rows) {
        for(std::string value : row) {
            cout << value << std::endl;
        }
    }
    
    Point point = Point(1,"test", "test", 1, 1);
    return 0;
}


