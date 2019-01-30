//
//  DB.cpp
//  libgps
//
//  Created by Thomas Lemaire on 30/01/2019.
//  Copyright © 2019 Thomas Lemaire. All rights reserved.
//

#include "DB.hpp"

sqlite3* DB::instance;

void DB::loadInstance() {
    if (!DB::instance) {
        
        std::cout << "Development mode enabled, database deleted before loading.\n";
        remove("database.db");
        
        if(sqlite3_open("database.db", &DB::instance)) {
            instance = nullptr;
            fprintf(stderr, "Error opening database: %s\n", sqlite3_errmsg(DB::instance));
        }
    }
}

void DB::load() {
    DB::loadInstance();
    if (DB::instance) {
        char* errorMessage;
        
        // SCHEMA
        std::ifstream ifs = std::ifstream("rsc/schema.sql");
        std::string query((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
        int errorCode = sqlite3_exec(DB::instance, query.c_str(), NULL, 0, &errorMessage);
        if(errorCode != SQLITE_OK){
            fprintf(stderr, "SQL error: %s\n", errorMessage);
            sqlite3_free(errorMessage);
        }
        
        // DATA
        ifs = std::ifstream("rsc/data.sql");
        query = std::string((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
        errorCode = sqlite3_exec(DB::instance, query.c_str(), NULL, 0, &errorMessage);
        if(errorCode != SQLITE_OK){
            fprintf(stderr, "SQL error: %s\n", errorMessage);
            sqlite3_free(errorMessage);
        }
    }
}

void DB::close() {
    if (DB::instance) {
        sqlite3_close(DB::instance);
    }
}


