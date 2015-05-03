#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    4/25/2015
#
#    Purpose:  Build the Project Euler C++ Examples
#

#  Set CMake Version
cmake_minimum_required( VERSION 2.8 FATAL_ERROR )

#  Set the project info
Project( Project-Euler-CPP )

#----------------------------#
#-        Allow C++ 11x     -#
#----------------------------#
SET(CMAKE_CXX_FLAGS "-std=c++11")


#  Override Binary Directory
set( EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../../bin/cpp )
set( LIBRARY_OUTPUT_PATH    ${PROJECT_BINARY_DIR}/../../lib/cpp )

#  Build Common Code
add_subdirectory( common )

#  Add Subdirectory
add_subdirectory( euler001 )
add_subdirectory( euler002 )
add_subdirectory( euler003 )
add_subdirectory( euler004 )
add_subdirectory( euler005 )
add_subdirectory( euler006 )
add_subdirectory( euler007 )
add_subdirectory( euler008 )
add_subdirectory( euler009 )
add_subdirectory( euler010 )
add_subdirectory( euler011 )
add_subdirectory( euler012 )
add_subdirectory( euler013 )
add_subdirectory( euler014 )
add_subdirectory( euler015 )
add_subdirectory( euler016 )
add_subdirectory( euler017 )
add_subdirectory( euler018 )
add_subdirectory( euler019 )
add_subdirectory( euler020 )
add_subdirectory( euler021 )
add_subdirectory( euler022 )
add_subdirectory( euler023 )
add_subdirectory( euler024 )
add_subdirectory( euler025 )
add_subdirectory( euler026 )
add_subdirectory( euler027 )
add_subdirectory( euler028 )
add_subdirectory( euler029 )
add_subdirectory( euler030 )
add_subdirectory( euler057 )


