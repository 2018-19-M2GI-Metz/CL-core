# CL-core

The core C++ and the database dumps/instructions


## Development information

SQL Schemas and data files must be in ./SQL/ when running the executable.
these two files will be embedded in the executable at the end of the project.


## C++

Make the A* and Djikstra algorithm
Communication between Java and the dababase


## Database

We decided to go with a sqlite database.
Sources (needed) : https://www.sqlite.org/index.html
Documentation : https://www.tutorialspoint.com/sqlite/sqlite_c_cpp.htm

If you're running `Debian` you can install the library with `sudo apt install libsqlite3-dev`

## Compilation on Unix systems

First you have to set an environment variable to tell `CMake` where to find `sqlite3`. Do the following :
`export SQLite3_DIR=cmake/` then you can use `cmake .` at the root of the project. Finally run `make` to compile the sources.

You'll need several packages like `cmake`, `make` and `g++`. On GNU/Debian derivatives you can do `sudo apt install build-essentials cmake make g++` to be sure to have them.

