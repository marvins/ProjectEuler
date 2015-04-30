#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    4/29/2015
#
#    Purpose: Build Project Euler 008 C++ Example
#

#----------------------------#
#-        Allow C++ 11x     -#
#----------------------------#
SET(CMAKE_CXX_FLAGS "-std=c++11")

#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( Euler008_Sources
     euler008.cpp
     ../common/StringUtilities.hpp
)

#----------------------------------#
#-      Build the Executable      -#
#----------------------------------#
add_executable( euler008
                ${Euler008_Sources}
)

