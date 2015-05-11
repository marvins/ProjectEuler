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
SET(CMAKE_CXX_FLAGS "-std=c++11 -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}     ${CMAKE_CXX_FLAGS}")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${CMAKE_CXX_FLAGS} -O3")

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
add_subdirectory( euler031 )
add_subdirectory( euler032 )
add_subdirectory( euler033 )
add_subdirectory( euler034 )
add_subdirectory( euler035 )
add_subdirectory( euler036 )
add_subdirectory( euler037 )
add_subdirectory( euler038 )
add_subdirectory( euler039 )
add_subdirectory( euler040 )
add_subdirectory( euler041 )
add_subdirectory( euler042 )
add_subdirectory( euler043 )
add_subdirectory( euler044 )
add_subdirectory( euler045 )
add_subdirectory( euler046 )
add_subdirectory( euler047 )
add_subdirectory( euler048 )
add_subdirectory( euler049 )
add_subdirectory( euler050 )
add_subdirectory( euler051 )
add_subdirectory( euler052 )
add_subdirectory( euler053 )
add_subdirectory( euler054 )
add_subdirectory( euler055 )
add_subdirectory( euler056 )
add_subdirectory( euler057 )
add_subdirectory( euler058 )
add_subdirectory( euler059 )
add_subdirectory( euler060 )
add_subdirectory( euler061 )
add_subdirectory( euler062 )
add_subdirectory( euler063 )
add_subdirectory( euler064 )
add_subdirectory( euler065 )
add_subdirectory( euler066 )
add_subdirectory( euler067 )
add_subdirectory( euler068 )
add_subdirectory( euler069 )
add_subdirectory( euler080 )
add_subdirectory( euler084 )
add_subdirectory( euler500 )

