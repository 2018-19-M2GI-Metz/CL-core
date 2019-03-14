//
//  main.cpp
//  libgps
//
//  Created by Thomas Lemaire on 06/11/2018.
//  Copyright © 2018 Thomas Lemaire. All rights reserved.
//

#include <iostream>
#include "./Interfaces/DB.hpp"
#include "Models/Path.hpp"

using std::cout;

int main(int argc, char** argv) {
    DB::load();
    Segment::populateDB();
    
    // DB usage example :
    // bindable properties MUST start à '?1', then '?2', '?3', and so on
    // bindable properties are automaticaly converted to int when necessary
    // bindable properties are optionnals
    
    cout << std::endl << std::endl << "Showing one point :" << std::endl;
    rows rows = DB::execute("SELECT * FROM point WHERE id = ?1", std::vector<std::string>({"2"}));
    for(row row : rows) {
        for(std::string value : row) {
            cout << " | " << value;
        }
        cout << " |" << std::endl;
    }
    cout << std::endl;
    
    cout << std::endl << "Showing all segments :" << std::endl;
    rows = DB::execute("SELECT * FROM segment");
    for(row row : rows) {
        for(std::string value : row) {
            cout << " | " << value;
        }
        cout << " |" << std::endl;
    }
    cout << std::endl;
    
    
    return 0;
}


