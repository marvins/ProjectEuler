#    File:     CMakeLists.txt
#    Author:   Marvin Smith
#    Date:     4/25/2015
#
#    Purpose:  Build the Euler002 example for Fortran
#

#   Set CMake Version
cmake_minimum_required( VERSION 2.8 FATAL_ERROR )

#------------------------------------#
#-     Define our Source Files      -#
#------------------------------------#
set( Euler002_SOURCES
     euler002.f90
     ../common/Fibonacci.f90
)

#  Create Executable
add_executable( euler002 
                ${Euler002_SOURCES}
)

