#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    4/25/2015
#
#    Purpose:  Build the Project Euler Solutions.
#

#---------------------------#
#-    Set CMake Version    -#
#---------------------------#
cmake_minimum_required( VERSION 2.8 FATAL_ERROR )

#-------------------------#
#-     Project Name      -#
#-------------------------#
#project( Project-Euler-Solutions )


#--------------------------------#
#-     Add C++ Code Samples     -#
#--------------------------------#
add_subdirectory( cpp )

#------------------------------------#
#-     Add Fortran Code Samples     -#
#------------------------------------#
add_subdirectory( fortran )

