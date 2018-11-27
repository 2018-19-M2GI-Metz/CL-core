//
//  main.cpp
//  libgps
//
//  Created by Thomas Lemaire on 06/11/2018.
//  Copyright © 2018 Thomas Lemaire. All rights reserved.
//

#include <iostream>
#include <sqlite3.h>


int main(int argc, char** argv) {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    std::string query;
    
    /* Open database */
    rc = sqlite3_open("test.db", &db);
    
    if( rc ) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(0);
    } else {
        fprintf(stdout, "Opened database successfully\n");
    }
    
    /* Create SQL statement */
    query = "CREATE TABLE COMPANY(ID INT PRIMARY KEY NOT NULL,NAME TEXT NOT NULL, AGE            INT     NOT NULL,ADDRESS        CHAR(50),SALARY REAL );";
    
    /* Execute SQL statement */
    rc = sqlite3_exec(db, query.c_str(), NULL, 0, &zErrMsg);
    
    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Table created successfully\n");
    }
    sqlite3_close(db);

    return 0;
}
