#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    4/29/2015
#
#    Purpose: Build Project Euler 009 C++ Example
#

#----------------------------#
#-        Allow C++ 11x     -#
#----------------------------#
SET(CMAKE_CXX_FLAGS "-std=c++11")

#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( Euler009_Sources
     euler009.cpp
)

#----------------------------------#
#-      Build the Executable      -#
#----------------------------------#
add_executable( euler009
                ${Euler009_Sources}
)

