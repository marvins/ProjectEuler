#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    5/7/2015
#
#    Purpose: Build Project Euler 064 C++ Example
#


#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( Euler064_Sources
     euler064.cpp
     ../common/Math_Utilities.hpp
     ../common/StringUtilities.hpp
)

#----------------------------------#
#-      Build the Executable      -#
#----------------------------------#
add_executable( euler064
                ${Euler064_Sources}
)


