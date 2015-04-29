#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    4/25/2015
#
#    Purpose: Build Project Euler 007 C++ Example
#

#----------------------------#
#-        Allow C++ 11x     -#
#----------------------------#
SET(CMAKE_CXX_FLAGS "-std=c++11")

#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( Euler007_Sources
     euler007.cpp
     Primesieve.hpp
)

#----------------------------------#
#-      Build the Executable      -#
#----------------------------------#
add_executable( euler007
                ${Euler007_Sources}
)

