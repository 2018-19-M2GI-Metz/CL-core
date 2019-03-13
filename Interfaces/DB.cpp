//
//  DB.cpp
//  libgps
//
//  Created by Thomas Lemaire on 30/01/2019.
//  Copyright © 2019 Thomas Lemaire. All rights reserved.
//

#include "DB.hpp"

sqlite3* DB::instance;

rows DB::execute(std::string query) {
    rows result = rows();
    DB::loadInstance();
    if (DB::instance) {
        int stepStatus;
        const char *pzTest;
        bool firstRow = true;
        
        sqlite3_stmt* context = nullptr;
        sqlite3_prepare(DB::instance, query.c_str(), int(strlen(query.c_str())), &context, &pzTest);
        do {
            stepStatus = sqlite3_step(context);
            if (stepStatus != SQLITE_DONE) {
                row rowResult = row();
                int columnCount = sqlite3_column_count(context);
                
                if (firstRow) {
                    for (int columnIndex = 0; columnIndex < columnCount; columnIndex += 1) {
                        std::string value = std::string(reinterpret_cast<const char*>(sqlite3_column_name(context, columnIndex)));
                        rowResult.push_back(value);
                    }
                    result.push_back(rowResult);
                    rowResult = row();
                    firstRow = false;
                }

                for (int columnIndex = 0; columnIndex < columnCount; columnIndex += 1) {
                    std::string value = std::string(reinterpret_cast<const char*>(sqlite3_column_text(context, columnIndex)));
                    rowResult.push_back(value);
                }
                result.push_back(rowResult);
            }
        } while(stepStatus == SQLITE_ROW);
        
        if (stepStatus == SQLITE_ERROR || stepStatus == SQLITE_BUSY || stepStatus == SQLITE_MISUSE) {
            std::cout << "erreur d'execution de execute()";
        }
        sqlite3_finalize(context);
        return result;
    }
    else {
        fprintf(stderr, "SQL error: Impossible de charger l'instance");
    }
    return result;
}

void DB::loadInstance() {
    if (!DB::instance) {
        std::cout << "Development mode enabled, database deleted before loading.\n";
        remove("database.db");
        // (access("database.db", F_OK) != -1)   => return true if exists, need unistd.h
        if (sqlite3_open("database.db", &DB::instance)) { // sql3_open return true if error
            instance = nullptr;
            fprintf(stderr, "Error opening database: %s\n", sqlite3_errmsg(DB::instance));
        }
    }
}

void DB::load() {
    // SCHEMA
    std::ifstream ifs = std::ifstream("rsc/schema.sql");
    std::string query((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
    DB::execute(query);
    
    // DATA
    ifs = std::ifstream("rsc/data.sql");
    query = std::string((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
    DB::execute(query);
}

void DB::close() {
    if (DB::instance) {
        sqlite3_close(DB::instance);
    }
}





