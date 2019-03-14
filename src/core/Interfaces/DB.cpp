//
//  DB.cpp
//  libgps
//
//  Created by Thomas Lemaire on 30/01/2019.
//  Copyright © 2019 Thomas Lemaire. All rights reserved.
//

#include "DB.hpp"
#include <cstring>

sqlite3* DB::instance;
bool DB::isNewDatabase = true;

rows DB::execute(std::string query, std::vector<std::string> binds) {
    rows result = rows();
    DB::loadInstance();
    if (DB::instance) {
        int stepStatus;
        const char *pzTest;
        bool firstRow = true;
        
        // Prepare the statement
        sqlite3_stmt* context = nullptr;
        int error = sqlite3_prepare_v2(DB::instance, query.c_str(), int(strlen(query.c_str())), &context, &pzTest);
        
        if (SQLITE_OK != error) {
            std::cout << "ERREUR NUMERO" << error;
        }
                
        // Binds value if needed
        
        int bindIndex = 1;
        for (std::string bind : binds) {
            
            // test if string is int
            
            bool isInt = true;
            for (int i = 0; i < bind.length(); i++) {
                if (isdigit(bind[i]) == false) {
                    isInt = false;
                }
            }
            
            // apply logic
            
            if (isInt) {
                int bindInt = atoi(bind.c_str());
                sqlite3_bind_int(context, bindIndex, bindInt);
            }
            else {
                sqlite3_bind_text(context, bindIndex, bind.c_str(), int(strlen(bind.c_str())), SQLITE_STATIC);
            }
            bindIndex += 1;
        }
        
        
        // do-while to get all rows
        
        do {
            stepStatus = sqlite3_step(context);
            if (stepStatus != SQLITE_DONE) {
                row rowResult = row();
                int columnCount = sqlite3_column_count(context);
                
                // create the first line of the result (column names)
                
                if (firstRow) {
                    for (int columnIndex = 0; columnIndex < columnCount; columnIndex += 1) {
                        std::string value = std::string(reinterpret_cast<const char*>(sqlite3_column_name(context, columnIndex)));
                        rowResult.push_back(value);
                    }
                    result.push_back(rowResult);
                    rowResult = row();
                    firstRow = false;
                }
                
                // foreach columns in the row
                
                for (int columnIndex = 0; columnIndex < columnCount; columnIndex += 1) {
                    std::string value = std::string(reinterpret_cast<const char*>(sqlite3_column_text(context, columnIndex)));
                    rowResult.push_back(value);
                }
                result.push_back(rowResult);
            }
        } while(stepStatus == SQLITE_ROW);
        
        // error catch
        
        if (stepStatus == SQLITE_ERROR || stepStatus == SQLITE_BUSY || stepStatus == SQLITE_MISUSE) {
            std::cout << "\nSQL error : Erreur d'execution de execute()";
        }
        
        // end of query
        
        sqlite3_finalize(context);
    }
    else {
        fprintf(stderr, "SQL error: Impossible de charger l'instance");
    }
    return result;
}

void DB::loadInstance() {
    if (!DB::instance) {
        //std::cout << "Development mode enabled, database deleted before loading.\n";
        //remove("database.db");
        
        if (access("database.db", F_OK) != -1) {
            DB::isNewDatabase = false;
        }
        if (sqlite3_open("database.db", &DB::instance)) { // sql3_open return true if error
            instance = nullptr;
            fprintf(stderr, "Error opening database: %s\n", sqlite3_errmsg(DB::instance));
        }
    }
}

void DB::load() {
    DB::loadInstance();
    
    if (DB::isNewDatabase) {
        // SCHEMA
        std::ifstream ifs = std::ifstream("rsc/schema.sql");
        std::string query((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
        
        std::vector<std::string> queries;
        while (query.size()) {
            int index = int(query.find(";"));
            if(index != std::string::npos){
                queries.push_back(query.substr(0, index));
                query = query.substr(index + 1);
            }
            else{
                queries.push_back(query);
                query = "";
            }
        }
        
        for (std::string query : queries) {
            DB::execute(query + ";");
        }
        
        // DATA
        ifs = std::ifstream("rsc/data.sql");
        query = std::string((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
        DB::execute(query);
    }
}

void DB::close() {
    if (DB::instance) {
        sqlite3_close(DB::instance);
    }
}






