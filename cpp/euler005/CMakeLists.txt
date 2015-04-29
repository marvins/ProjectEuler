#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    4/28/2015
#
#    Purpose: Build Project Euler 005 C++ Example
#

#----------------------------#
#-        Allow C++ 11x     -#
#----------------------------#
SET(CMAKE_CXX_FLAGS "-std=c++11")

#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( Euler005_Sources
     euler005.cpp
)

#----------------------------------#
#-      Build the Executable      -#
#----------------------------------#
add_executable( euler005
                ${Euler005_Sources}
)

