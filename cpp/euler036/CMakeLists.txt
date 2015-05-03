#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    5/3/2015
#
#    Purpose: Build Project Euler 036 C++ Example
#


#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( Euler036_Sources
     euler036.cpp
     ../common/Math_Utilities.hpp
     ../common/StringUtilities.hpp
)

#----------------------------------#
#-      Build the Executable      -#
#----------------------------------#
add_executable( euler036
                ${Euler036_Sources}
)


