cmake_minimum_required(VERSION 3.13)
project (Map)

set(SQLite3_DIR "cmake/")

file(GLOB_RECURSE SOURCES "./src/core/*.cpp")
add_executable(main ${SOURCES})
add_library(core SHARED ${SOURCES})

find_package (SQLite3)
if (SQLITE3_FOUND)
  include_directories(${SQLITE3_INCLUDE_DIRS})
  target_link_libraries (main ${SQLITE3_LIBRARIES})
  target_link_libraries (core ${SQLITE3_LIBRARIES})
endif (SQLITE3_FOUND)
