cmake_minimum_required(VERSION 3.13)
project (Map)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin/")

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/core/*.cpp")
add_executable(main ${SOURCES})

find_package (SQLite3)
if (SQLITE3_FOUND)
  include_directories(${SQLITE3_INCLUDE_DIRS})
  target_link_libraries (main ${SQLITE3_LIBRARIES})
endif (SQLITE3_FOUND)
