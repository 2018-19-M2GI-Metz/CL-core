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
#include "API/interface.hpp"

using std::cout;

int main(int argc, char** argv) {
    DB::load();
    
    // DB usage example :
    // bindable properties MUST start à '?1', then '?2', '?3', and so on
    // bindable properties are automaticaly converted to int when necessary
    // bindable properties are optionnals
    
    cout << std::endl;
    rows rows = DB::execute("SELECT * FROM point WHERE id = ?1", std::vector<std::string>({"2"}));
    for(row row : rows) {
        for(std::string value : row) {
            cout << " | " << value;
        }
        cout << " |" << std::endl;
    }
    cout << std::endl;

    auto res = searchPlace("metz");
    
    cout << "Printing names retrieved with searchPlace()" << std::endl;
    for (auto const point : res) {
        cout << point->getName() << std::endl;
    }
    
    return 0;
}


