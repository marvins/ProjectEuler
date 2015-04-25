#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    4/25/2015
#
#    Purpose:  Build the Project Euler Fortran Examples
#

#  Set CMake Version
cmake_minimum_required( VERSION 2.8 FATAL_ERROR )

#  Enable Fortran
enable_language( Fortran )

#  Override Binary Directory
set( EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin )
set( LIBRARY_OUTPUT_PATH    ${PROJECT_BINARY_DIR}/lib )

#  Add Subdirectory
add_subdirectory( euler001 )

#  Add Subdirectory
add_subdirectory( euler002 )

