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

#include "Interfaces/Process.hpp"

using std::cout;

int main(int argc, char** argv) {
    DB::load();
    //Segment::populateDB();

    // DB usage example :
    // bindable properties MUST start à '?1', then '?2', '?3', and so on
    // bindable properties are automaticaly converted to int when necessary
    // bindable properties are optionnals
//
//    cout << std::endl << std::endl << "Showing one point :" << std::endl;
//    rows rows = DB::execute("SELECT * FROM point WHERE id = ?1", std::vector<std::string>({"2"}));
//    for(row row : rows) {
//        for(std::string value : row) {
//            cout << " | " << value;
//        }
//        cout << " |" << std::endl;
//    }
//    cout << std::endl;
//
//    cout << std::endl << "Showing all segments :" << std::endl;
//    rows = DB::execute("SELECT * FROM segment");
//    for(row row : rows) {
//        for(std::string value : row) {
//            cout << " | " << value;
//        }
//        cout << " |" << std::endl;
//    }
//    cout << std::endl;
//
//    std::vector<sharedPoint> points = searchPlace("onti");
//
//    for (sharedPoint point : points) {
//        std::cout << point->getName() << " " << point->getAddress() << std::endl;
//    }
    

    sharedPath path = searchShortest(1, 200);

    for (sharedSegment segment : path->getSegments()) {
        std::cout << segment->getStartPoint()->getId() << " --> " << segment->getEndPoint()->getId() << std::endl;
    }

    return 0;
}


