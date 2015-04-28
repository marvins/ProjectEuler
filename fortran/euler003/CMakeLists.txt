#    File:     CMakeLists.txt
#    Author:   Marvin Smith
#    Date:     4/25/2015
#
#    Purpose:  Build the Euler003 example for Fortran
#

#   Set CMake Version
cmake_minimum_required( VERSION 2.8 FATAL_ERROR )

#------------------------------------#
#-     Define our Source Files      -#
#------------------------------------#
set( Euler003_SOURCES
     euler003.f90
     ../common/PrimeNumberModule.f90
)

#  Create Executable
add_executable( euler003 
                ${Euler003_SOURCES}
)

