#    File:     CMakeLists.txt
#    Author:   Marvin Smith
#    Date:     4/25/2015
#
#    Purpose:  Build the Euler001 example for Fortran
#

#   Set CMake Version
cmake_minimum_required( VERSION 2.8 FATAL_ERROR )

#------------------------------------#
#-     Define our Source Files      -#
#------------------------------------#
set( Euler001_SOURCES
     euler001.f90
)

#  Create Executable
add_executable( euler001 
                ${Euler001_SOURCES}
)

