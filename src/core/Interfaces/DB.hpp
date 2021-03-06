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
#include <unistd.h>
#include <fstream>
#include <vector>
#include <string>
#include <sqlite3.h>
#include "../SQL/SQLseeder.hpp"

typedef std::vector<std::vector<std::string>> rows;
typedef std::vector<std::string> row;

class DB {
public:
    // return vector of rows represented by vector of string
    // row 0 is column names
    static rows execute(std::string query, std::vector<std::string> binds = std::vector<std::string>());

    // load the full database
    static void load();
    
    // create arbitrary datas for segments
    static void populate();
    
    // close the database
    static void close();
private:
    DB();
    static sqlite3* instance;
    static void loadInstance();
    static bool isNewDatabase;
};

#endif /* BD_hpp */
