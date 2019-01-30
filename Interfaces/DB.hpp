//
//  DB.hpp
//  libgps
//
//  Created by Thomas Lemaire on 30/01/2019.
//  Copyright © 2019 Thomas Lemaire. All rights reserved.
//

#ifndef DB_hpp
#define DB_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sqlite3.h>

class DB {
public:
    static void load();
    static void close();
private:
    DB();
    static sqlite3* instance;
    static void loadInstance();
};

#endif /* BD_hpp */
