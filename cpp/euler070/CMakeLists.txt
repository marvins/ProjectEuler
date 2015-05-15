#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    5/14/2015
#
#    Purpose: Build Project Euler 070 C++ Example
#

#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( Euler070_Sources
     euler070.cpp
     ../common/Math_Utilities.hpp
     ../common/Primesieve.hpp
)

#----------------------------------#
#-      Build the Executable      -#
#----------------------------------#
add_executable( euler070
                ${Euler070_Sources}
)


